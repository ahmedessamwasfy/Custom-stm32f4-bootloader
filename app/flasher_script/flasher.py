from __future__ import print_function

import sys, serial, binascii, time, struct, _thread, argparse
from intelhex import IntelHex


ACK       = 0x41
NACK      = 0x4E
CMD_WRITE = 0x03

class ProgramModeError(Exception):
    pass

class TimeoutError(Exception):
    pass

class STM32Flasher(object):
    def __init__(self, serialPort, baudrate=115200):
        self.serial = serial.Serial(serialPort, baudrate=baudrate, timeout=30)

    def writeImage(self, filename):
        #Sends an CMD_WRITE to the bootloader
        #This is method is a generator, that returns its progresses to the caller.
        #In this way, it's possible for the caller to live-print messages about
        #writing progress 
        ih = IntelHex()  
        ih.loadhex(filename)
        yield {"saddr": ih.minaddr(), "eaddr": ih.maxaddr()}

        addr = ih.minaddr()
        content = ih.todict()
        abort = False
        resend = 0
        while addr <= ih.maxaddr():
            if not resend:
                data = []
                saddr = addr
                for i in range(16):
                  try:
                      data.append(content[addr])
                  except KeyError:
                      #if the HEX file doesn't contain a value for the given address
                      #we "pad" it with 0xFF, which corresponds to the erase value
                      data.append(0xFF)
                  addr+=1
            try:
                if resend >= 3:
                     abort = True
                     break
                     
                self.serial.flushInput()
                
                self.serial.write([CMD_WRITE] + list(struct.pack("I", saddr)) + list(data))
                
                ret = self.serial.read(1)
                if struct.unpack("b", ret)[0] != ACK:
                    raise ProgramModeError("Write abort")
					
                
                yield {"loc": saddr, "resend": resend}
                resend = 0
            except (TimeoutError, ProgramModeError):
                resend +=1

        yield {"success": not abort}


if __name__ == '__main__':
    eraseDone = 0
    
    parser = argparse.ArgumentParser(
        description='Loads a IntelHEX binary file using the custom bootloader described in the "MasteringSTM32 book')

    parser.add_argument('com_port', metavar='com_port_path', type=str,
                        help="Serial port ('/dev/tty.usbxxxxx' for UNIX-like systems or 'COMx' for Windows")

    parser.add_argument('hex_file', metavar='hex_file_path', type=str,
                        help="Path to the IntelHEX file containing the firmware to flash on the target MCU")

    args = parser.parse_args()


    flasher = STM32Flasher(args.com_port)

    for e in flasher.writeImage(sys.argv[2]):
        if "saddr" in e:
            print("\tStart address: ", hex(e["saddr"]))
            print("\tEnd address: ", hex(e["eaddr"]))
        if "loc" in e:
            if e["resend"] > 0:
                end = "\n"
            else:
                end = ""
            print("\r\tWriting address: %s --- %d" % (hex(e["loc"]), e["resend"]), end=end)
            sys.stdout.flush()

        if "success" in e and e["success"]:
            print("\n\tDone")
        elif "success" in e and not e["success"]:
            print("\n\tFailed to upload firmware")