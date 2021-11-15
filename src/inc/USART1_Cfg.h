

/*******************************************************************************
 * @file    USART1_Cfg.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 16, 2019
 *
 * @brief   USART1_Cfg.h example using ST virtual COM port (VCP)
 * @note
 *
@verbatim
Copyright (C) Ahnmed Wasfy 2019

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Define to prevent recursive inclusion */
/*
 * USART1_Cfg.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_USART1_CFG_H_
#define INC_USART1_CFG_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif


/***************************** USART_SR register**************************** */
/***************************** USART_DR register**************************** */
/***************************** USART_BRR register**************************** */

/***************************** USART_CR1 register**************************** */

/*
 *Bit 15 OVER8: Oversampling mode
0: oversampling by 16
1: oversampling by 8
Note: Oversampling by 8 is not available in the Smartcard, IrDA and LIN modes: when
SCEN=1,IREN=1 or LINEN=1 then OVER8 is forced to ‘0 by hardware.
 */
#define USART1_OVER8 FALSE


/*
 * Bit 13 UE: USART enable
When this bit is cleared the USART prescalers and outputs are stopped and the end of the
current
byte transfer in order to reduce power consumption. This bit is set and cleared by software.
0: USART prescaler and outputs disabled
1: USART enabled
 * */
#define USART1_UE FALSE

/*
 * Bit 12 M: Word length
This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit
Note: The M bit must not be modified during a data transfer (both transmission and reception)
 * */
#define USART1_M TRUE


/*
 * Bit 11 WAKE: Wakeup method
This bit determines the USART wakeup method, it is set or cleared by software.
0: Idle Line
1: Address Mark
 * */
#define USART1_WAKE FALSE


/*
 * Bit 10 PCE: Parity control enable
This bit selects the hardware parity control (generation and detection). When the parity
control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
if M=0) and parity is checked on the received data. This bit is set and cleared by software.
Once it is set, PCE is active after the current byte (in reception and in transmission).
0: Parity control disabled
1: Parity control enabled
 * */
#define USART1_PCE TRUE



/*
 *Bit 9 PS: Parity selection
This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
bit set). It is set and cleared by software. The parity will be selected after the current byte.
0: Even parity
1: Odd parity
 * */
#define USART1_PS TRUE



/*
 * Bit 8 PEIE: PE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever PE=1 in the USART_SR register
 * */
#define USART1_PEIE TRUE



/*
 * Bit 7 TXEIE: TXE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
 * */
#define USART1_TXEIE FALSE



/*
 * Bit 6 TCIE: Transmission complete interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever TC=1 in the USART_SR register
*/
#define USART1_TCIE FALSE



/*
 * Bit 5 RXNEIE: RXNE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR
register
 * */
#define USART1_RXNEIE FALSE



/*
 * Bit 4 IDLEIE: IDLE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: An USART interrupt is generated whenever IDLE=1 in the USART_SR register
 * */
#define USART1_IDLEIE FALSE



/*
 * Bit 3 TE: Transmitter enable
This bit enables the transmitter. It is set and cleared by software.
0: Transmitter is disabled
1: Transmitter is enabled
Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
(idle line) after the current word, except in smartcard mode.
2: When TE is set there is a 1 bit-time delay before the transmission starts.
 * */
#define USART1_TE FALSE



/*
 * Bit 2 RE: Receiver enable
This bit enables the receiver. It is set and cleared by software.
0: Receiver is disabled
1: Receiver is enabled and begins searching for a start bit
*/
#define USART1_RE FALSE



/*
 * Bit 1 RWU: Receiver wakeup
This bit determines if the USART is in mute mode or not. It is set and cleared by software
and can be cleared by hardware when a wakeup sequence is recognized.
0: Receiver in active mode
1: Receiver in mute mode
Note: 1: Before selecting Mute mode (by setting the RWU bit) the USART must first receive a
data byte, otherwise it cannot function in Mute mode with wakeup by Idle line detection.
2: In Address Mark Detection wakeup configuration (WAKE bit=1) the RWU bit cannot
be modified by software while the RXNE bit is set.
*/
#define USART1_RWU FALSE



/*Bit 0 SBK: Send break
This bit set is used to send break characters. It can be set and cleared by software. It should
be set by software, and will be reset by hardware during the stop bit of break.
0: No break character is transmitted
1: Break character will be transmitted
 * */
#define USART1_SBK FALSE





/***************************** USART_CR2 register**************************** */


/*
 * Bit 14 LINEN: LIN mode enable
This bit is set and cleared by software.
0: LIN mode disabled
1: LIN mode enabled
The LIN mode enables the capability to send LIN Synch Breaks (13 low bits) using the SBK bit in
the USART_CR1 register, and to detect LIN Sync breaks.
 * */
#define USART1_LINEN FALSE


/*
 *Bits 13:12 STOP: STOP bits
These bits are used for programming the stop bits.
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit
Note: The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
 * */
#define USART1_STOP				STOP_ONE_bit
#define STOP_ONE_bit			((uint16)0x0000)
#define STOP_half_bit			((uint16)0X1000)
#define STOP_TWO_bit			((uint16)0x2000)
#define STOP_ONE_and_half_bit	((uint16)0x3000)



/*
 * Bit 11 CLKEN: Clock enable
This bit allows the user to enable the SCLK pin.
0: SCLK pin disabled
1: SCLK pin enabled
This bit is not available for UART4 & UART5.
 * */
#define USART1_CLKEN FALSE



/*
 * Bit 10 CPOL: Clock polarity
This bit allows the user to select the polarity of the clock output on the SCLK pin in synchronous
mode. It works in conjunction with the CPHA bit to produce the desired clock/data relationship
0: Steady low value on SCLK pin outside transmission window.
1: Steady high value on SCLK pin outside transmission window.
This bit is not available for UART4 & UART5.
 * */
#define USART1_CPOL FALSE



/*
 * Bit 9 CPHA: Clock phase
This bit allows the user to select the phase of the clock output on the SCLK pin in synchronous
mode. It works in conjunction with the CPOL bit to produce the desired clock/data relationship (see
figures 258 to 259)
0: The first clock transition is the first data capture edge
1: The second clock transition is the first data capture edge
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_CPHA FALSE



/*
 * Bit 8 LBCL: Last bit clock pulse
This bit allows the user to select whether the clock pulse associated with the last data bit
transmitted (MSB) has to be output on the SCLK pin in synchronous mode.
0: The clock pulse of the last data bit is not output to the SCLK pin
1: The clock pulse of the last data bit is output to the SCLK pin
Note: 1: The last bit is the 8th or 9th data bit transmitted depending on the 8 or 9 bit format selected
by the M bit in the USART_CR1 register.
2: This bit is not available for UART4 & UART5.
 * */
#define USART1_LBCL FALSE



/*
 * Bit 6 LBDIE: LIN break detection interrupt enable
Break interrupt mask (break detection using break delimiter).
0: Interrupt is inhibited
1: An interrupt is generated whenever LBD=1 in the USART_SR register
 * */
#define USART1_LBDIE FALSE



/*
 * Bit 5 LBDL: lin break detection length
This bit is for selection between 11 bit or 10 bit break detection.
0: 10-bit break detection
1: 11-bit break detection
 * */
#define USART1_LBDL FALSE



/*
 * Bits 3:0 ADD[3:0]: Address of the USART node
This bit-field gives the address of the USART node.
This is used in multiprocessor communication during mute mode, for wake up with address mark
detection.
Note: These 3 bits (CPOL, CPHA, LBCL) should not be written while the transmitter is enabled.
 * */




/***************************** USART_CR3 register**************************** */


/*
 * Bit 11 ONEBIT: One sample bit method enable
This bit allows the user to select the sample method. When the one sample bit method is
selected the noise detection flag (NF) is disabled.
0: Three sample bit method
1: One sample bit method
 * */
#define USART1_ONEBIT TRUE



/*
 * Bit 10 CTSIE: CTS interrupt enable
0: Interrupt is inhibited
1: An interrupt is generated whenever CTS=1 in the USART_SR register
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_CTSIE FALSE



/*
 * Doc ID 018909 Rev 4 790/1422
Bit 9 CTSE: CTS enable
0: CTS hardware flow control disabled
1: CTS mode enabled, data is only transmitted when the nCTS input is asserted (tied to 0).
If the nCTS input is deasserted while a data is being transmitted, then the transmission is
completed before stopping. If a data is written into the data register while nCTS is asserted,
the transmission is postponed until nCTS is asserted.
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_CTSE FALSE



/*
 * Bit 8 RTSE: RTS enable
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
The transmission of data is expected to cease after the current character has been
transmitted. The nRTS output is asserted (tied to 0) when a data can be received.
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_RTSE FALSE



/*
 * Bit 7 DMAT: DMA enable transmitter
This bit is set/reset by software
1: DMA mode is enabled for transmission.
0: DMA mode is disabled for transmission.
 * */
#define USART1_DMAT FALSE



/*
 * Bit 6 DMAR: DMA enable receiver
This bit is set/reset by software
1: DMA mode is enabled for reception
0: DMA mode is disabled for reception
 * */
#define USART1_DMAR FALSE



/*
 * Bit 5 SCEN: Smartcard mode enable
This bit is used for enabling Smartcard mode.
0: Smartcard Mode disabled
1: Smartcard Mode enabled
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_SCEN FALSE



/*
 * Bit 4 NACK: Smartcard NACK enable
0: NACK transmission in case of parity error is disabled
1: NACK transmission during parity error is enabled
Note: This bit is not available for UART4 & UART5.
 * */
#define USART1_NACK FALSE



/*
 * Bit 3 HDSEL: Half-duplex selection
Selection of Single-wire Half-duplex mode
0: Half duplex mode is not selected
1: Half duplex mode is selected
 * */
#define USART1_HDSEL FALSE


/*
 * Bit 2 IRLP: IrDA low-power
This bit is used for selecting between normal and low-power IrDA modes
0: Normal mode
1: Low-power mode
 * */
#define USART1_IRLP FALSE



/*
 * Bit 1 IREN: IrDA mode enable
This bit is set and cleared by software.
0: IrDA disabled
1: IrDA enabled
 * */
#define USART1_IREN FALSE



/*
 * Bit 0 EIE: Error interrupt enable
Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing
error, overrun error or noise flag (FE=1 or ORE=1 or NF=1 in the USART_SR register) in
case of Multi Buffer Communication (DMAR=1 in the USART_CR3 register).
0: Interrupt is inhibited
1: An interrupt is generated whenever DMAR=1 in the USART_CR3 register and FE=1 or
ORE=1 or NF=1 in the USART_SR register.
 * */
#define USART1_EIE FALSE






/***************************** USART_GTPR register**************************** */



/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	





/* Includes */


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup USART1_Cfg.h
 * @{
 */

/**
 * @defgroup USART1_Cfg.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_Cfg.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_Cfg.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_Cfg.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_Cfg.h_exported_functions
 * @{
 */

/**
 * @brief  
 * @note   
 * @param   
 * @retval  
 */

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_USART1_CFG_H_ */
