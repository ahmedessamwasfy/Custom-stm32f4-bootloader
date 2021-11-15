/*
 * DMA_Cfg.h
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_DMA_CFG_H_
#define INC_DMA_CFG_H_

/* ==================================================================== */
/* ============================ DMA 1 ================================= */
/* ==================================================================== */

/* ============================ STREAM 0 ================================= */

//# DMA_CR			/*!< DMA stream x configuration register      */

/*Bits 27:25 CHSEL[2:0]: Channel selection
These bits are set and cleared by software.
000: channel 0 selected
001: channel 1 selected
010: channel 2 selected
011: channel 3 selected
100: channel 4 selected
101: channel 5 selected
110: channel 6 selected
111: channel 7 selected
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_0_Channel_Selection		Channel_0
#define Channel_0 							0x00000000
#define Channel_1 							0x02000000
#define Channel_2 							0x04000000
#define Channel_3 							0x06000000
#define Channel_4 							0x08000000
#define Channel_5 							0x0A000000
#define Channel_6 							0x0C000000
#define Channel_7 							0x0E000000


/*
 * Bits 24:23 MBURST: Memory burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
*/
#define DMA1_STREAM_0_MBURST			MBURST_Single_Transfer
#define MBURST_Single_Transfer			0x00000000
#define MBURST_INCR4					0x00800000
#define MBURST_INCR8					0x01000000
#define MBURST_INCR16					0x01800000



/*
 * Bits 22:21 PBURST[1:0]: Peripheral burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware.
 * */
#define DMA1_STREAM_0_PBURST			PBURST_Single_Transfer
#define PBURST_Single_Transfer			0x00000000
#define PBURST_INCR4					0x00020000
#define PBURST_INCR8					0x00040000
#define PBURST_INCR16					0x00060000


/*
 * Bit 19 CT: Current target (only in double buffer mode)
This bits is set and cleared by hardware. It can also be written by software.
0: The current target memory is Memory 0 (addressed by the DMA_SxM0AR pointer)
1: The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)
This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer.
Once the stream is enabled, this bit operates as a status flag indicating which memory area
is the current target.
 * */
#define DMA1_STREAM_0_CT	FALSE


/*
 * Bit 18 DBM: Double buffer mode
This bits is set and cleared by software.
0: No buffer switching at the end of transfer
1: Memory target switched at the end of the DMA transfer
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_0_DBM	FALSE


/*
 * Bits 17:16 PL[1:0]: Priority level
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
These bits are protected and can be written only if EN is ‘0’.
*/
#define DMA1_STREAM_0_PL		Low
#define Low						0x00000000
#define Medium					0x00010000
#define High					0x00020000
#define Very_High				0x00030000


/*
 * Bit 15 PINCOS: Peripheral increment offset size
This bit is set and cleared by software
0: The offset size for the peripheral address calculation is linked to the PSIZE
1: The offset size for the peripheral address calculation is fixed to 4 (32-bit alignment).
This bit has no meaning if bit PINC = '0'.
This bit is protected and can be written only if EN = '0'.
This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct
mode is selected or if PBURST are different from “00”.
 * */
#define DMA1_STREAM_0_PINCOS	FALSE


/*
 * Bits 14:13 MSIZE[1:0]: Memory data size
These bits are set and cleared by software.
00: byte (8-bit)
01: half-word (16-bit)
10: word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’.
In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN
= '1'.
 * */
#define DMA1_STREAM_0_MSIZE			MSIZE_Byte
#define MSIZE_Byte					0x00000000
#define MSIZE_Half_Word				0x00002000
#define MSIZE_Word					0x00004000




/*
 * Bits 12:11 PSIZE[1:0]: Peripheral data size
These bits are set and cleared by software.
00: Byte (8-bit)
01: Half-word (16-bit)
10: Word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_0_PSIZE			PSIZE_Byte
#define PSIZE_Byte					0x00000000
#define PSIZE_Half_Word				0x00000800
#define PSIZE_Word					0x00001000


/*
 * Bit 10 MINC: Memory increment mode
This bit is set and cleared by software.
0: Memory address pointer is fixed
1: Memory address pointer is incremented after each data transfer (increment is done
according to MSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_0_MINC	FALSE


/*
 * Bit 9 PINC: Peripheral increment mode
This bit is set and cleared by software.
0: Peripheral address pointer is fixed
1: Peripheral address pointer is incremented after each data transfer (increment is done
according to PSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_0_PINC	FALSE


/*
 * Bit 8 CIRC: Circular mode
This bit is set and cleared by software and can be cleared by hardware.
0: Circular mode disabled
1: Circular mode enabled
When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit
EN=1), then this bit is automatically forced by hardware to 0.
It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is
enabled (bit EN ='1').
 * */
#define DMA1_STREAM_0_CIRC	FALSE


/*
 * Bits 7:6 DIR[1:0]: Data transfer direction
These bits are set and cleared by software.
00: Peripheral-to-memory
01: Memory-to-peripheral
10: Memory-to-memory
11: reserved
These bits are protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_0_DIR						Peripheral_to_memory
#define Peripheral_to_memory					0x00000000
#define Memory_to_peripheral					0x00000040
#define Memory_to_memory						0x00000080


/*
 * Bit 5 PFCTRL: Peripheral flow controller
This bit is set and cleared by software.
0: The DMA is the flow controller
1: The peripheral is the flow controller
This bit is protected and can be written only if EN is ‘0’.
When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is
automatically forced to 0 by hardware.
 * */
#define DMA1_STREAM_0_PFCTRL	FALSE


/*
 * Bit 4 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
 * */
#define DMA1_STREAM_0_TCIE	FALSE


/*
 * Bit 3 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
 * */
#define DMA1_STREAM_0_HTIE	FALSE


/**
 * Bit 2 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
 */
#define DMA1_STREAM_0_TEIE	FALSE


/*
 * Bit 1 DMEIE: Direct mode error interrupt enable
This bit is set and cleared by software.
0: DME interrupt disabled
1: DME interrupt enabled
 * */
#define DMA1_STREAM_0_DMEIE	FALSE


/*
 * Bit 0 EN: Stream enable / flag stream ready when read low
This bit is set and cleared by software.
0: Stream disabled
1: Stream enabled
This bit may be cleared by hardware:
– on a DMA end of transfer (stream ready to be configured)
– if a transfer error occurs on the AHB master buses
– when the FIFO threshold on memory AHB port is not compatible with the size of the
burst
When this bit is read as 0, the software is allowed to program the Configuration and FIFO
bits registers. It is forbidden to write these registers when the EN bit is read as 1.
Note: Before setting EN bit to '1' to start a new transfer, the event flags corresponding to the
stream in DMA_LISR or DMA_HISR register must be cleared.
 * */


//***************************END OF CONFIG**************************//


//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */



//# DMA_FCR			/*!< DMA stream x FIFO control register       */
/*
 * Bit 7 FEIE: FIFO error interrupt enable
This bit is set and cleared by software.
0: FE interrupt disabled
1: FE interrupt enabled
 *
 * */
#define	DMA1_STREAM_0_FIFO_Error_Interrupt_enable TRUE


/*
 * DMDIS: Direct mode disable
This bit is set and cleared by software. It can be set by hardware.
0: Direct mode enabled
1: Direct mode disabled
This bit is protected and can be written only if EN is ‘0’.
This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in
DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct
mode is not allowed in the memory-to-memory configuration.
 *
 * */
#define DMA1_STREAM_0_Direct_Mode_Disable		 TRUE



/*
 * These bits are set and cleared by software.
00: 1/4 full FIFO
01: 1/2 full FIFO
10: 3/4 full FIFO
11: full FIFO
These bits are not used in the direct mode when the DMIS value is zero.
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_0_FIFO_Threshold_Selection	QUARTER_FIFO
#define	QUARTER_FIFO							0x00000000
#define	HALF_FIFO								0x00000001
#define	THREE_QUARTERS_FIFO						0x00000002
#define	FULL_FIFO								0x00000003

//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */



/* ============================ STREAM 1 ================================= */

/* ============================ STREAM 2 ================================= */

/* ============================ STREAM 3 ================================= */

/* ============================ STREAM 4 ================================= */

/* ============================ STREAM 5 ================================= */

/* ============================ STREAM 6 ================================= */

/* ============================ STREAM 7 ================================= */

//# DMA_CR			/*!< DMA stream x configuration register      */

/*Bits 27:25 CHSEL[2:0]: Channel selection
These bits are set and cleared by software.
000: channel 0 selected
001: channel 1 selected
010: channel 2 selected
011: channel 3 selected
100: channel 4 selected
101: channel 5 selected
110: channel 6 selected
111: channel 7 selected
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_7_Channel_Selection		Channel_0
#define Channel_0 							0x00000000
#define Channel_1 							0x02000000
#define Channel_2 							0x04000000
#define Channel_3 							0x06000000
#define Channel_4 							0x08000000
#define Channel_5 							0x0A000000
#define Channel_6 							0x0C000000
#define Channel_7 							0x0E000000


/*
 * Bits 24:23 MBURST: Memory burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
*/
#define DMA1_STREAM_7_MBURST			MBURST_Single_Transfer
#define MBURST_Single_Transfer			0x00000000
#define MBURST_INCR4					0x00800000
#define MBURST_INCR8					0x01000000
#define MBURST_INCR16					0x01800000



/*
 * Bits 22:21 PBURST[1:0]: Peripheral burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware.
 * */
#define DMA1_STREAM_7_PBURST			PBURST_Single_Transfer
#define PBURST_Single_Transfer			0x00000000
#define PBURST_INCR4					0x00020000
#define PBURST_INCR8					0x00040000
#define PBURST_INCR16					0x00060000


/*
 * Bit 19 CT: Current target (only in double buffer mode)
This bits is set and cleared by hardware. It can also be written by software.
0: The current target memory is Memory 0 (addressed by the DMA_SxM0AR pointer)
1: The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)
This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer.
Once the stream is enabled, this bit operates as a status flag indicating which memory area
is the current target.
 * */
#define DMA1_STREAM_7_CT	FALSE


/*
 * Bit 18 DBM: Double buffer mode
This bits is set and cleared by software.
0: No buffer switching at the end of transfer
1: Memory target switched at the end of the DMA transfer
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_7_DBM	FALSE


/*
 * Bits 17:16 PL[1:0]: Priority level
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
These bits are protected and can be written only if EN is ‘0’.
*/
#define DMA1_STREAM_7_PL		Low
#define Low						0x00000000
#define Medium					0x00010000
#define High					0x00020000
#define Very_High				0x00030000


/*
 * Bit 15 PINCOS: Peripheral increment offset size
This bit is set and cleared by software
0: The offset size for the peripheral address calculation is linked to the PSIZE
1: The offset size for the peripheral address calculation is fixed to 4 (32-bit alignment).
This bit has no meaning if bit PINC = '0'.
This bit is protected and can be written only if EN = '0'.
This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct
mode is selected or if PBURST are different from “00”.
 * */
#define DMA1_STREAM_7_PINCOS	FALSE


/*
 * Bits 14:13 MSIZE[1:0]: Memory data size
These bits are set and cleared by software.
00: byte (8-bit)
01: half-word (16-bit)
10: word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’.
In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN
= '1'.
 * */
#define DMA1_STREAM_7_MSIZE			MSIZE_Byte
#define MSIZE_Byte					0x00000000
#define MSIZE_Half_Word				0x00002000
#define MSIZE_Word					0x00004000




/*
 * Bits 12:11 PSIZE[1:0]: Peripheral data size
These bits are set and cleared by software.
00: Byte (8-bit)
01: Half-word (16-bit)
10: Word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_7_PSIZE			PSIZE_Byte
#define PSIZE_Byte					0x00000000
#define PSIZE_Half_Word				0x00000800
#define PSIZE_Word					0x00001000


/*
 * Bit 10 MINC: Memory increment mode
This bit is set and cleared by software.
0: Memory address pointer is fixed
1: Memory address pointer is incremented after each data transfer (increment is done
according to MSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_7_MINC	FALSE


/*
 * Bit 9 PINC: Peripheral increment mode
This bit is set and cleared by software.
0: Peripheral address pointer is fixed
1: Peripheral address pointer is incremented after each data transfer (increment is done
according to PSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_7_PINC	FALSE


/*
 * Bit 8 CIRC: Circular mode
This bit is set and cleared by software and can be cleared by hardware.
0: Circular mode disabled
1: Circular mode enabled
When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit
EN=1), then this bit is automatically forced by hardware to 0.
It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is
enabled (bit EN ='1').
 * */
#define DMA1_STREAM_7_CIRC	FALSE


/*
 * Bits 7:6 DIR[1:0]: Data transfer direction
These bits are set and cleared by software.
00: Peripheral-to-memory
01: Memory-to-peripheral
10: Memory-to-memory
11: reserved
These bits are protected and can be written only if EN is ‘0’.
 * */
#define DMA1_STREAM_7_DIR						Peripheral_to_memory
#define Peripheral_to_memory					0x00000000
#define Memory_to_peripheral					0x00000040
#define Memory_to_memory						0x00000080


/*
 * Bit 5 PFCTRL: Peripheral flow controller
This bit is set and cleared by software.
0: The DMA is the flow controller
1: The peripheral is the flow controller
This bit is protected and can be written only if EN is ‘0’.
When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is
automatically forced to 0 by hardware.
 * */
#define DMA1_STREAM_7_PFCTRL	FALSE


/*
 * Bit 4 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
 * */
#define DMA1_STREAM_7_TCIE	FALSE


/*
 * Bit 3 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
 * */
#define DMA1_STREAM_7_HTIE	FALSE


/**
 * Bit 2 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
 */
#define DMA1_STREAM_7_TEIE	FALSE


/*
 * Bit 1 DMEIE: Direct mode error interrupt enable
This bit is set and cleared by software.
0: DME interrupt disabled
1: DME interrupt enabled
 * */
#define DMA1_STREAM_7_DMEIE	FALSE


/*
 * Bit 0 EN: Stream enable / flag stream ready when read low
This bit is set and cleared by software.
0: Stream disabled
1: Stream enabled
This bit may be cleared by hardware:
– on a DMA end of transfer (stream ready to be configured)
– if a transfer error occurs on the AHB master buses
– when the FIFO threshold on memory AHB port is not compatible with the size of the
burst
When this bit is read as 0, the software is allowed to program the Configuration and FIFO
bits registers. It is forbidden to write these registers when the EN bit is read as 1.
Note: Before setting EN bit to '1' to start a new transfer, the event flags corresponding to the
stream in DMA_LISR or DMA_HISR register must be cleared.
 * */


//***************************END OF CONFIG**************************//


//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */



//# DMA_FCR			/*!< DMA stream x FIFO control register       */
/*
 * Bit 7 FEIE: FIFO error interrupt enable
This bit is set and cleared by software.
0: FE interrupt disabled
1: FE interrupt enabled
 *
 * */
#define	DMA1_STREAM_7_FIFO_Error_Interrupt_enable TRUE


/*
 * DMDIS: Direct mode disable
This bit is set and cleared by software. It can be set by hardware.
0: Direct mode enabled
1: Direct mode disabled
This bit is protected and can be written only if EN is ‘0’.
This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in
DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct
mode is not allowed in the memory-to-memory configuration.
 *
 * */
#define DMA1_STREAM_7_Direct_Mode_Disable		 TRUE



/*
 * These bits are set and cleared by software.
00: 1/4 full FIFO
01: 1/2 full FIFO
10: 3/4 full FIFO
11: full FIFO
These bits are not used in the direct mode when the DMIS value is zero.
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA1_STREAM_7_FIFO_Threshold_Selection	QUARTER_FIFO
#define	QUARTER_FIFO							0x00000000
#define	HALF_FIFO								0x00000001
#define	THREE_QUARTERS_FIFO						0x00000002
#define	FULL_FIFO								0x00000003

//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */





/* ==================================================================== */
/* ============================ DMA 2 ================================= */
/* ==================================================================== */


//# DMA_CR			/*!< DMA stream x configuration register      */
//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */
//# DMA_FCR			/*!< DMA stream x FIFO control register       */
//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */



/* ============================ STREAM 0 ================================= */

//# DMA_CR			/*!< DMA stream x configuration register      */

/*Bits 27:25 CHSEL[2:0]: Channel selection
These bits are set and cleared by software.
000: channel 0 selected
001: channel 1 selected
010: channel 2 selected
011: channel 3 selected
100: channel 4 selected
101: channel 5 selected
110: channel 6 selected
111: channel 7 selected
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_0_Channel_Selection		Channel_0
#define Channel_0 							0x00000000
#define Channel_1 							0x02000000
#define Channel_2 							0x04000000
#define Channel_3 							0x06000000
#define Channel_4 							0x08000000
#define Channel_5 							0x0A000000
#define Channel_6 							0x0C000000
#define Channel_7 							0x0E000000


/*
 * Bits 24:23 MBURST: Memory burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
*/
#define DMA2_STREAM_0_MBURST			MBURST_Single_Transfer
#define MBURST_Single_Transfer			0x00000000
#define MBURST_INCR4					0x00800000
#define MBURST_INCR8					0x01000000
#define MBURST_INCR16					0x01800000



/*
 * Bits 22:21 PBURST[1:0]: Peripheral burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware.
 * */
#define DMA2_STREAM_0_PBURST			PBURST_Single_Transfer
#define PBURST_Single_Transfer			0x00000000
#define PBURST_INCR4					0x00020000
#define PBURST_INCR8					0x00040000
#define PBURST_INCR16					0x00060000


/*
 * Bit 19 CT: Current target (only in double buffer mode)
This bits is set and cleared by hardware. It can also be written by software.
0: The current target memory is Memory 0 (addressed by the DMA_SxM0AR pointer)
1: The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)
This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer.
Once the stream is enabled, this bit operates as a status flag indicating which memory area
is the current target.
 * */
#define DMA2_STREAM_0_CT	FALSE


/*
 * Bit 18 DBM: Double buffer mode
This bits is set and cleared by software.
0: No buffer switching at the end of transfer
1: Memory target switched at the end of the DMA transfer
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_0_DBM	FALSE


/*
 * Bits 17:16 PL[1:0]: Priority level
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
These bits are protected and can be written only if EN is ‘0’.
*/
#define DMA2_STREAM_0_PL		Low
#define Low						0x00000000
#define Medium					0x00010000
#define High					0x00020000
#define Very_High				0x00030000


/*
 * Bit 15 PINCOS: Peripheral increment offset size
This bit is set and cleared by software
0: The offset size for the peripheral address calculation is linked to the PSIZE
1: The offset size for the peripheral address calculation is fixed to 4 (32-bit alignment).
This bit has no meaning if bit PINC = '0'.
This bit is protected and can be written only if EN = '0'.
This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct
mode is selected or if PBURST are different from “00”.
 * */
#define DMA2_STREAM_0_PINCOS	FALSE


/*
 * Bits 14:13 MSIZE[1:0]: Memory data size
These bits are set and cleared by software.
00: byte (8-bit)
01: half-word (16-bit)
10: word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’.
In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN
= '1'.
 * */
#define DMA2_STREAM_0_MSIZE			MSIZE_Byte
#define MSIZE_Byte					0x00000000
#define MSIZE_Half_Word				0x00002000
#define MSIZE_Word					0x00004000




/*
 * Bits 12:11 PSIZE[1:0]: Peripheral data size
These bits are set and cleared by software.
00: Byte (8-bit)
01: Half-word (16-bit)
10: Word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_0_PSIZE			PSIZE_Byte
#define PSIZE_Byte					0x00000000
#define PSIZE_Half_Word				0x00000800
#define PSIZE_Word					0x00001000


/*
 * Bit 10 MINC: Memory increment mode
This bit is set and cleared by software.
0: Memory address pointer is fixed
1: Memory address pointer is incremented after each data transfer (increment is done
according to MSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_0_MINC	TRUE


/*
 * Bit 9 PINC: Peripheral increment mode
This bit is set and cleared by software.
0: Peripheral address pointer is fixed
1: Peripheral address pointer is incremented after each data transfer (increment is done
according to PSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_0_PINC	TRUE


/*
 * Bit 8 CIRC: Circular mode
This bit is set and cleared by software and can be cleared by hardware.
0: Circular mode disabled
1: Circular mode enabled
When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit
EN=1), then this bit is automatically forced by hardware to 0.
It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is
enabled (bit EN ='1').
 * */
#define DMA2_STREAM_0_CIRC	FALSE


/*
 * Bits 7:6 DIR[1:0]: Data transfer direction
These bits are set and cleared by software.
00: Peripheral-to-memory
01: Memory-to-peripheral
10: Memory-to-memory
11: reserved
These bits are protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_0_DIR						Peripheral_to_memory
#define Peripheral_to_memory					0x00000000
#define Memory_to_peripheral					0x00000040
#define Memory_to_memory						0x00000080


/*
 * Bit 5 PFCTRL: Peripheral flow controller
This bit is set and cleared by software.
0: The DMA is the flow controller
1: The peripheral is the flow controller
This bit is protected and can be written only if EN is ‘0’.
When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is
automatically forced to 0 by hardware.
 * */
#define DMA2_STREAM_0_PFCTRL	FALSE


/*
 * Bit 4 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
 * */
#define DMA2_STREAM_0_TCIE	TRUE


/*
 * Bit 3 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
 * */
#define DMA2_STREAM_0_HTIE	FALSE


/**
 * Bit 2 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
 */
#define DMA2_STREAM_0_TEIE	FALSE


/*
 * Bit 1 DMEIE: Direct mode error interrupt enable
This bit is set and cleared by software.
0: DME interrupt disabled
1: DME interrupt enabled
 * */
#define DMA2_STREAM_0_DMEIE	FALSE


/*
 * Bit 0 EN: Stream enable / flag stream ready when read low
This bit is set and cleared by software.
0: Stream disabled
1: Stream enabled
This bit may be cleared by hardware:
– on a DMA end of transfer (stream ready to be configured)
– if a transfer error occurs on the AHB master buses
– when the FIFO threshold on memory AHB port is not compatible with the size of the
burst
When this bit is read as 0, the software is allowed to program the Configuration and FIFO
bits registers. It is forbidden to write these registers when the EN bit is read as 1.
Note: Before setting EN bit to '1' to start a new transfer, the event flags corresponding to the
stream in DMA_LISR or DMA_HISR register must be cleared.
 * */


//***************************END OF CONFIG**************************//


//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */



//# DMA_FCR			/*!< DMA stream x FIFO control register       */
/*
 * Bit 7 FEIE: FIFO error interrupt enable
This bit is set and cleared by software.
0: FE interrupt disabled
1: FE interrupt enabled
 *
 * */
#define	DMA2_STREAM_0_FIFO_Error_Interrupt_enable TRUE


/*
 * DMDIS: Direct mode disable
This bit is set and cleared by software. It can be set by hardware.
0: Direct mode enabled
1: Direct mode disabled
This bit is protected and can be written only if EN is ‘0’.
This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in
DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct
mode is not allowed in the memory-to-memory configuration.
 *
 * */
#define DMA2_STREAM_0_Direct_Mode_Disable		 TRUE



/*
 * These bits are set and cleared by software.
00: 1/4 full FIFO
01: 1/2 full FIFO
10: 3/4 full FIFO
11: full FIFO
These bits are not used in the direct mode when the DMIS value is zero.
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_0_FIFO_Threshold_Selection	HALF_FIFO
#define	QUARTER_FIFO							0x00000000
#define	HALF_FIFO								0x00000001
#define	THREE_QUARTERS_FIFO						0x00000002
#define	FULL_FIFO								0x00000003

//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */
















/* ============================ STREAM 5 ================================= */

//# DMA_CR			/*!< DMA stream x configuration register      */

/*Bits 27:25 CHSEL[2:0]: Channel selection
These bits are set and cleared by software.
000: channel 0 selected
001: channel 1 selected
010: channel 2 selected
011: channel 3 selected
100: channel 4 selected
101: channel 5 selected
110: channel 6 selected
111: channel 7 selected
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_5_Channel_Selection		Channel_4
#define Channel_0 							0x00000000
#define Channel_1 							0x02000000
#define Channel_2 							0x04000000
#define Channel_3 							0x06000000
#define Channel_4 							0x08000000 ///USART1_RX
#define Channel_5 							0x0A000000
#define Channel_6 							0x0C000000
#define Channel_7 							0x0E000000


/*
 * Bits 24:23 MBURST: Memory burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
*/
#define DMA2_STREAM_5_MBURST			MBURST_Single_Transfer
#define MBURST_Single_Transfer			0x00000000
#define MBURST_INCR4					0x00800000
#define MBURST_INCR8					0x01000000
#define MBURST_INCR16					0x01800000



/*
 * Bits 22:21 PBURST[1:0]: Peripheral burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware.
 * */
#define DMA2_STREAM_5_PBURST			PBURST_Single_Transfer
#define PBURST_Single_Transfer			0x00000000
#define PBURST_INCR4					0x00020000
#define PBURST_INCR8					0x00040000
#define PBURST_INCR16					0x00060000


/*
 * Bit 19 CT: Current target (only in double buffer mode)
This bits is set and cleared by hardware. It can also be written by software.
0: The current target memory is Memory 0 (addressed by the DMA_SxM0AR pointer)
1: The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)
This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer.
Once the stream is enabled, this bit operates as a status flag indicating which memory area
is the current target.
 * */
#define DMA2_STREAM_5_CT	FALSE


/*
 * Bit 18 DBM: Double buffer mode
This bits is set and cleared by software.
0: No buffer switching at the end of transfer
1: Memory target switched at the end of the DMA transfer
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_5_DBM	FALSE


/*
 * Bits 17:16 PL[1:0]: Priority level
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
These bits are protected and can be written only if EN is ‘0’.
*/
#define DMA2_STREAM_5_PL		Very_High
#define Low						0x00000000
#define Medium					0x00010000
#define High					0x00020000
#define Very_High				0x00030000


/*
 * Bit 15 PINCOS: Peripheral increment offset size
This bit is set and cleared by software
0: The offset size for the peripheral address calculation is linked to the PSIZE
1: The offset size for the peripheral address calculation is fixed to 4 (32-bit alignment).
This bit has no meaning if bit PINC = '0'.
This bit is protected and can be written only if EN = '0'.
This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct
mode is selected or if PBURST are different from “00”.
 * */
#define DMA2_STREAM_5_PINCOS	FALSE


/*
 * Bits 14:13 MSIZE[1:0]: Memory data size
These bits are set and cleared by software.
00: byte (8-bit)
01: half-word (16-bit)
10: word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’.
In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN
= '1'.
 * */
#define DMA2_STREAM_5_MSIZE			MSIZE_Byte
#define MSIZE_Byte					0x00000000
#define MSIZE_Half_Word				0x00002000
#define MSIZE_Word					0x00004000




/*
 * Bits 12:11 PSIZE[1:0]: Peripheral data size
These bits are set and cleared by software.
00: Byte (8-bit)
01: Half-word (16-bit)
10: Word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_5_PSIZE			PSIZE_Byte
#define PSIZE_Byte					0x00000000
#define PSIZE_Half_Word				0x00000800
#define PSIZE_Word					0x00001000


/*
 * Bit 10 MINC: Memory increment mode
This bit is set and cleared by software.
0: Memory address pointer is fixed
1: Memory address pointer is incremented after each data transfer (increment is done
according to MSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_5_MINC	TRUE


/*
 * Bit 9 PINC: Peripheral increment mode
This bit is set and cleared by software.
0: Peripheral address pointer is fixed
1: Peripheral address pointer is incremented after each data transfer (increment is done
according to PSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_5_PINC	FALSE


/*
 * Bit 8 CIRC: Circular mode
This bit is set and cleared by software and can be cleared by hardware.
0: Circular mode disabled
1: Circular mode enabled
When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit
EN=1), then this bit is automatically forced by hardware to 0.
It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is
enabled (bit EN ='1').
 * */
#define DMA2_STREAM_5_CIRC	FALSE


/*
 * Bits 7:6 DIR[1:0]: Data transfer direction
These bits are set and cleared by software.
00: Peripheral-to-memory
01: Memory-to-peripheral
10: Memory-to-memory
11: reserved
These bits are protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_5_DIR						Peripheral_to_memory
#define Peripheral_to_memory					0x00000000
#define Memory_to_peripheral					0x00000040
#define Memory_to_memory						0x00000080


/*
 * Bit 5 PFCTRL: Peripheral flow controller
This bit is set and cleared by software.
0: The DMA is the flow controller
1: The peripheral is the flow controller
This bit is protected and can be written only if EN is ‘0’.
When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is
automatically forced to 0 by hardware.
 * */
#define DMA2_STREAM_5_PFCTRL	FALSE


/*
 * Bit 4 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
 * */
#define DMA2_STREAM_5_TCIE	TRUE


/*
 * Bit 3 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
 * */
#define DMA2_STREAM_5_HTIE	FALSE


/**
 * Bit 2 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
 */
#define DMA2_STREAM_5_TEIE	FALSE


/*
 * Bit 1 DMEIE: Direct mode error interrupt enable
This bit is set and cleared by software.
0: DME interrupt disabled
1: DME interrupt enabled
 * */
#define DMA2_STREAM_5_DMEIE	FALSE


/*
 * Bit 0 EN: Stream enable / flag stream ready when read low
This bit is set and cleared by software.
0: Stream disabled
1: Stream enabled
This bit may be cleared by hardware:
– on a DMA end of transfer (stream ready to be configured)
– if a transfer error occurs on the AHB master buses
– when the FIFO threshold on memory AHB port is not compatible with the size of the
burst
When this bit is read as 0, the software is allowed to program the Configuration and FIFO
bits registers. It is forbidden to write these registers when the EN bit is read as 1.
Note: Before setting EN bit to '1' to start a new transfer, the event flags corresponding to the
stream in DMA_LISR or DMA_HISR register must be cleared.
 * */


//***************************END OF CONFIG**************************//


//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */



//# DMA_FCR			/*!< DMA stream x FIFO control register       */
/*
 * Bit 5 FEIE: FIFO error interrupt enable
This bit is set and cleared by software.
0: FE interrupt disabled
1: FE interrupt enabled
 *
 * */
#define	DMA2_STREAM_5_FIFO_Error_Interrupt_enable FALSE


/*
 * DMDIS: Direct mode disable
This bit is set and cleared by software. It can be set by hardware.
0: Direct mode enabled
1: Direct mode disabled
This bit is protected and can be written only if EN is ‘0’.
This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in
DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct
mode is not allowed in the memory-to-memory configuration.
 *
 * */
#define DMA2_STREAM_5_Direct_Mode_Disable		 TRUE



/*
 * These bits are set and cleared by software.
00: 1/4 full FIFO
01: 1/2 full FIFO
10: 3/4 full FIFO
11: full FIFO
These bits are not used in the direct mode when the DMIS value is zero.
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_5_FIFO_Threshold_Selection	HALF_FIFO
#define	QUARTER_FIFO							0x00000000
#define	HALF_FIFO								0x00000001
#define	THREE_QUARTERS_FIFO						0x00000002
#define	FULL_FIFO								0x00000003

//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */






















/* ============================ STREAM 7 ================================= */

//# DMA_CR			/*!< DMA stream x configuration register      */

/*Bits 27:25 CHSEL[2:0]: Channel selection
These bits are set and cleared by software.
000: channel 0 selected
001: channel 1 selected
010: channel 2 selected
011: channel 3 selected
100: channel 4 selected
101: channel 5 selected
110: channel 6 selected
111: channel 7 selected
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_7_Channel_Selection		Channel_4
#define Channel_0 							0x00000000
#define Channel_1 							0x02000000
#define Channel_2 							0x04000000
#define Channel_3 							0x06000000
#define Channel_4 							0x08000000 ///USART1_TX
#define Channel_5 							0x0A000000
#define Channel_6 							0x0C000000
#define Channel_7 							0x0E000000


/*
 * Bits 24:23 MBURST: Memory burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
*/
#define DMA2_STREAM_7_MBURST			MBURST_Single_Transfer
#define MBURST_Single_Transfer			0x00000000
#define MBURST_INCR4					0x00800000
#define MBURST_INCR8					0x01000000
#define MBURST_INCR16					0x01800000



/*
 * Bits 22:21 PBURST[1:0]: Peripheral burst transfer configuration
These bits are set and cleared by software.
00: single transfer
01: INCR4 (incremental burst of 4 beats)
10: INCR8 (incremental burst of 8 beats)
11: INCR16 (incremental burst of 16 beats)
These bits are protected and can be written only if EN is ‘0’
In direct mode, these bits are forced to 0x0 by hardware.
 * */
#define DMA2_STREAM_7_PBURST			PBURST_Single_Transfer
#define PBURST_Single_Transfer			0x00000000
#define PBURST_INCR4					0x00020000
#define PBURST_INCR8					0x00040000
#define PBURST_INCR16					0x00060000


/*
 * Bit 19 CT: Current target (only in double buffer mode)
This bits is set and cleared by hardware. It can also be written by software.
0: The current target memory is Memory 0 (addressed by the DMA_SxM0AR pointer)
1: The current target memory is Memory 1 (addressed by the DMA_SxM1AR pointer)
This bit can be written only if EN is ‘0’ to indicate the target memory area of the first transfer.
Once the stream is enabled, this bit operates as a status flag indicating which memory area
is the current target.
 * */
#define DMA2_STREAM_7_CT	FALSE


/*
 * Bit 18 DBM: Double buffer mode
This bits is set and cleared by software.
0: No buffer switching at the end of transfer
1: Memory target switched at the end of the DMA transfer
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_7_DBM	FALSE


/*
 * Bits 17:16 PL[1:0]: Priority level
These bits are set and cleared by software.
00: Low
01: Medium
10: High
11: Very high
These bits are protected and can be written only if EN is ‘0’.
*/
#define DMA2_STREAM_7_PL		Very_High
#define Low						0x00000000
#define Medium					0x00010000
#define High					0x00020000
#define Very_High				0x00030000


/*
 * Bit 15 PINCOS: Peripheral increment offset size
This bit is set and cleared by software
0: The offset size for the peripheral address calculation is linked to the PSIZE
1: The offset size for the peripheral address calculation is fixed to 4 (32-bit alignment).
This bit has no meaning if bit PINC = '0'.
This bit is protected and can be written only if EN = '0'.
This bit is forced low by hardware when the stream is enabled (bit EN = '1') if the direct
mode is selected or if PBURST are different from “00”.
 * */
#define DMA2_STREAM_7_PINCOS	FALSE


/*
 * Bits 14:13 MSIZE[1:0]: Memory data size
These bits are set and cleared by software.
00: byte (8-bit)
01: half-word (16-bit)
10: word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’.
In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN
= '1'.
 * */
#define DMA2_STREAM_7_MSIZE			MSIZE_Byte
#define MSIZE_Byte					0x00000000
#define MSIZE_Half_Word				0x00002000
#define MSIZE_Word					0x00004000




/*
 * Bits 12:11 PSIZE[1:0]: Peripheral data size
These bits are set and cleared by software.
00: Byte (8-bit)
01: Half-word (16-bit)
10: Word (32-bit)
11: reserved
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_7_PSIZE			PSIZE_Byte
#define PSIZE_Byte					0x00000000
#define PSIZE_Half_Word				0x00000800
#define PSIZE_Word					0x00001000


/*
 * Bit 10 MINC: Memory increment mode
This bit is set and cleared by software.
0: Memory address pointer is fixed
1: Memory address pointer is incremented after each data transfer (increment is done
according to MSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_7_MINC	TRUE


/*
 * Bit 9 PINC: Peripheral increment mode
This bit is set and cleared by software.
0: Peripheral address pointer is fixed
1: Peripheral address pointer is incremented after each data transfer (increment is done
according to PSIZE)
This bit is protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_7_PINC	FALSE


/*
 * Bit 8 CIRC: Circular mode
This bit is set and cleared by software and can be cleared by hardware.
0: Circular mode disabled
1: Circular mode enabled
When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit
EN=1), then this bit is automatically forced by hardware to 0.
It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is
enabled (bit EN ='1').
 * */
#define DMA2_STREAM_7_CIRC	FALSE


/*
 * Bits 7:6 DIR[1:0]: Data transfer direction
These bits are set and cleared by software.
00: Peripheral-to-memory
01: Memory-to-peripheral
10: Memory-to-memory
11: reserved
These bits are protected and can be written only if EN is ‘0’.
 * */
#define DMA2_STREAM_7_DIR						Memory_to_peripheral
#define Peripheral_to_memory					0x00000000
#define Memory_to_peripheral					0x00000040
#define Memory_to_memory						0x00000080


/*
 * Bit 5 PFCTRL: Peripheral flow controller
This bit is set and cleared by software.
0: The DMA is the flow controller
1: The peripheral is the flow controller
This bit is protected and can be written only if EN is ‘0’.
When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is
automatically forced to 0 by hardware.
 * */
#define DMA2_STREAM_7_PFCTRL	FALSE


/*
 * Bit 4 TCIE: Transfer complete interrupt enable
This bit is set and cleared by software.
0: TC interrupt disabled
1: TC interrupt enabled
 * */
#define DMA2_STREAM_7_TCIE	TRUE


/*
 * Bit 3 HTIE: Half transfer interrupt enable
This bit is set and cleared by software.
0: HT interrupt disabled
1: HT interrupt enabled
 * */
#define DMA2_STREAM_7_HTIE	FALSE


/**
 * Bit 2 TEIE: Transfer error interrupt enable
This bit is set and cleared by software.
0: TE interrupt disabled
1: TE interrupt enabled
 */
#define DMA2_STREAM_7_TEIE	FALSE


/*
 * Bit 1 DMEIE: Direct mode error interrupt enable
This bit is set and cleared by software.
0: DME interrupt disabled
1: DME interrupt enabled
 * */
#define DMA2_STREAM_7_DMEIE	FALSE


/*
 * Bit 0 EN: Stream enable / flag stream ready when read low
This bit is set and cleared by software.
0: Stream disabled
1: Stream enabled
This bit may be cleared by hardware:
– on a DMA end of transfer (stream ready to be configured)
– if a transfer error occurs on the AHB master buses
– when the FIFO threshold on memory AHB port is not compatible with the size of the
burst
When this bit is read as 0, the software is allowed to program the Configuration and FIFO
bits registers. It is forbidden to write these registers when the EN bit is read as 1.
Note: Before setting EN bit to '1' to start a new transfer, the event flags corresponding to the
stream in DMA_LISR or DMA_HISR register must be cleared.
 * */


//***************************END OF CONFIG**************************//


//# DMA_NDTR		/*!< DMA stream x number of data register     */
//# DMA_PAR			/*!< DMA stream x peripheral address register */
//# DMA_M0AR		/*!< DMA stream x memory 0 address register   */
//# DMA_M1AR		/*!< DMA stream x memory 1 address register   */



//# DMA_FCR			/*!< DMA stream x FIFO control register       */
/*
 * Bit 7 FEIE: FIFO error interrupt enable
This bit is set and cleared by software.
0: FE interrupt disabled
1: FE interrupt enabled
 *
 * */
#define	DMA2_STREAM_7_FIFO_Error_Interrupt_enable TRUE


/*
 * DMDIS: Direct mode disable
This bit is set and cleared by software. It can be set by hardware.
0: Direct mode enabled
1: Direct mode disabled
This bit is protected and can be written only if EN is ‘0’.
This bit is set by hardware if the memory-to-memory mode is selected (DIR bit in
DMA_SxCR are “10”) and the EN bit in the DMA_SxCR register is ‘1’ because the direct
mode is not allowed in the memory-to-memory configuration.
 *
 * */
#define DMA2_STREAM_7_Direct_Mode_Disable		 TRUE



/*
 * These bits are set and cleared by software.
00: 1/4 full FIFO
01: 1/2 full FIFO
10: 3/4 full FIFO
11: full FIFO
These bits are not used in the direct mode when the DMIS value is zero.
These bits are protected and can be written only if EN is ‘0’
 * */
#define DMA2_STREAM_7_FIFO_Threshold_Selection	HALF_FIFO
#define	QUARTER_FIFO							0x00000000
#define	HALF_FIFO								0x00000001
#define	THREE_QUARTERS_FIFO						0x00000002
#define	FULL_FIFO								0x00000003

//# LISR 			/*!< DMA low interrupt status register,      Address offset: 0x00 */
//# HISR 			/*!< DMA high interrupt status register,     Address offset: 0x04 */
//# LIFCR 			/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//# HIFCR 			/*!< DMA high interrupt flag clear register, Address offset: 0x0C */








#endif /* INC_DMA_CFG_H_ */
