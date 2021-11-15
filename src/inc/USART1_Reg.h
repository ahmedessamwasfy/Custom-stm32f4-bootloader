

/*******************************************************************************
 * @file    USART1_Reg.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 16, 2019
 *
 * @brief   USART1_Reg.h example using ST virtual COM port (VCP)
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
 * USART1_Reg.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_USART1_REG_H_
#define INC_USART1_REG_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif



/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/




/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/




/* ==================================================================== */
/* ========================== RCC Registers =========================== */
/* ==================================================================== */



#define RCC_APB1ENR   *((volatile uint32*)(0x40000000+0x00020000+0x3800+0x30)) /*!< RCC APB2 peripheral clock enable register, Address offset: 0x44 */
#define  RCC_AHB1ENR_GPIOAEN                 ((uint32)0x00000001)

/* ==================================================================== */
/* ========================== 	UART PINS	=========================== */
/* ==================================================================== */
#define USART1_CK_PORT	PORTA
#define USART1_CK_PIN 	8

#define USART1_TX_PORT	PORTA
#define USART1_TX_PIN 	9

#define USART1_RX_PORT	PORTA
#define USART1_RX_PIN 	10

#define USART1_CTS_PORT	PORTA
#define USART1_CTS_PIN 	11

#define USART1_RTS_PORT	PORTA
#define USART1_RTS_PIN 	12





/******************************************************************************/
/*                                                                            */
/*         Universal Synchronous Asynchronous Receiver Transmitter            */
/*                                                                            */
/******************************************************************************/


/* ==================================================================== */
/* ========================== RCC Registers =========================== */
/* ==================================================================== */



#define RCC_APB2ENR   *((volatile uint32*)(0x40000000+0x00020000+0x3800+0x44)) /*!< RCC APB2 peripheral clock enable register, Address offset: 0x44 */
#define  RCC_APB2ENR_USART1EN                ((uint32)0x00000010)





/* ==================================================================== */
/* ========================== USART Registers =========================== */
/* ==================================================================== */


/***************************** USART Bases **************************** */
#define USART1_BASE           (0x40000000+0x00010000+0x1000)


/***************************** USART Offset **************************** */

# define sr        0x00         /*!< USART Status register,   Address offset: 0x00 */
# define dr        0x04         /*!< USART Data register,     Address offset: 0x04 */
# define brr       0x08        /*!< USART Baud rate register, Address offset: 0x08 */
# define cr1       0x0C        /*!< USART Control register 1, Address offset: 0x0C */
# define cr2       0x10        /*!< USART Control register 2, Address offset: 0x10 */
# define cr3       0x14        /*!< USART Control register 3, Address offset: 0x14 */
# define gtpr      0x18       /*!< USART Guard time and prescaler register, Address offset: 0x18 */

/***************************** USART Final address **************************** */

/*
 *									USART 1 Final address
 */

# define USART1_SR        *((volatile uint16*)(sr+USART1_BASE))         /*!< USART Status register,   Address offset: 0x00 */
# define USART1_DR        *((volatile uint16*)(dr+USART1_BASE))         /*!< USART Data register,     Address offset: 0x04 */
# define USART1_BRR       *((volatile uint16*)(brr+USART1_BASE))        /*!< USART Baud rate register, Address offset: 0x08 */
# define USART1_CR1       *((volatile uint16*)(cr1+USART1_BASE))        /*!< USART Control register 1, Address offset: 0x0C */
# define USART1_CR2       *((volatile uint16*)(cr2+USART1_BASE))        /*!< USART Control register 2, Address offset: 0x10 */
# define USART1_CR3       *((volatile uint16*)(cr3+USART1_BASE))        /*!< USART Control register 3, Address offset: 0x14 */
# define USART1_GTPR      *((volatile uint16*)(gtpr+USART1_BASE))       /*!< USART Guard time and prescaler register, Address offset: 0x18 */









/* ==================================================================== */
/* ========================== USART Bit Def =========================== */
/* ==================================================================== */

/*******************  Bit definition for USART_SR register  *******************/
#define  USART_SR_PE                         ((uint16)0x0001)            /*!<Parity Error                 */
#define  USART_SR_FE                         ((uint16)0x0002)            /*!<Framing Error                */
#define  USART_SR_NE                         ((uint16)0x0004)            /*!<Noise Error Flag             */
#define  USART_SR_ORE                        ((uint16)0x0008)            /*!<OverRun Error                */
#define  USART_SR_IDLE                       ((uint16)0x0010)            /*!<IDLE line detected           */
#define  USART_SR_RXNE                       ((uint16)0x0020)            /*!<Read Data Register Not Empty */
#define  USART_SR_TC                         ((uint16)0x0040)            /*!<Transmission Complete        */
#define  USART_SR_TXE                        ((uint16)0x0080)            /*!<Transmit Data Register Empty */
#define  USART_SR_LBD                        ((uint16)0x0100)            /*!<LIN Break Detection Flag     */
#define  USART_SR_CTS                        ((uint16)0x0200)            /*!<CTS Flag                     */

/*******************  Bit definition for USART_DR register  *******************/
#define  USART_DR_DR                         ((uint16)0x01FF)            /*!<Data value */

/******************  Bit definition for USART_BRR register  *******************/
#define  USART_BRR_DIV_Fraction              ((uint16)0x000F)            /*!<Fraction of USARTDIV */
#define  USART_BRR_DIV_Mantissa              ((uint16)0xFFF0)            /*!<Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define  USART_CR1_SBK                       ((uint16)0x0001)            /*!<Send Break                             */
#define  USART_CR1_RWU                       ((uint16)0x0002)            /*!<Receiver wakeup                        */
#define  USART_CR1_RE                        ((uint16)0x0004)            /*!<Receiver Enable                        */
#define  USART_CR1_TE                        ((uint16)0x0008)            /*!<Transmitter Enable                     */
#define  USART_CR1_IDLEIE                    ((uint16)0x0010)            /*!<IDLE Interrupt Enable                  */
#define  USART_CR1_RXNEIE                    ((uint16)0x0020)            /*!<RXNE Interrupt Enable                  */
#define  USART_CR1_TCIE                      ((uint16)0x0040)            /*!<Transmission Complete Interrupt Enable */
#define  USART_CR1_TXEIE                     ((uint16)0x0080)            /*!<PE Interrupt Enable                    */
#define  USART_CR1_PEIE                      ((uint16)0x0100)            /*!<PE Interrupt Enable                    */
#define  USART_CR1_PS                        ((uint16)0x0200)            /*!<Parity Selection                       */
#define  USART_CR1_PCE                       ((uint16)0x0400)            /*!<Parity Control Enable                  */
#define  USART_CR1_WAKE                      ((uint16)0x0800)            /*!<Wakeup method                          */
#define  USART_CR1_M                         ((uint16)0x1000)            /*!<Word length                            */
#define  USART_CR1_UE                        ((uint16)0x2000)            /*!<USART Enable                           */
#define  USART_CR1_OVER8                     ((uint16)0x8000)            /*!<USART Oversampling by 8 enable         */

/******************  Bit definition for USART_CR2 register  *******************/
#define  USART_CR2_ADD                       ((uint16)0x000F)            /*!<Address of the USART node            */
#define  USART_CR2_LBDL                      ((uint16)0x0020)            /*!<LIN Break Detection Length           */
#define  USART_CR2_LBDIE                     ((uint16)0x0040)            /*!<LIN Break Detection Interrupt Enable */
#define  USART_CR2_LBCL                      ((uint16)0x0100)            /*!<Last Bit Clock pulse                 */
#define  USART_CR2_CPHA                      ((uint16)0x0200)            /*!<Clock Phase                          */
#define  USART_CR2_CPOL                      ((uint16)0x0400)            /*!<Clock Polarity                       */
#define  USART_CR2_CLKEN                     ((uint16)0x0800)            /*!<Clock Enable                         */

#define  USART_CR2_STOP                      ((uint16)0x3000)            /*!<STOP[1:0] bits (STOP bits) */
#define  USART_CR2_STOP_0                    ((uint16)0x1000)            /*!<Bit 0 */
#define  USART_CR2_STOP_1                    ((uint16)0x2000)            /*!<Bit 1 */

#define  USART_CR2_LINEN                     ((uint16)0x4000)            /*!<LIN mode enable */

/******************  Bit definition for USART_CR3 register  *******************/
#define  USART_CR3_EIE                       ((uint16)0x0001)            /*!<Error Interrupt Enable      */
#define  USART_CR3_IREN                      ((uint16)0x0002)            /*!<IrDA mode Enable            */
#define  USART_CR3_IRLP                      ((uint16)0x0004)            /*!<IrDA Low-Power              */
#define  USART_CR3_HDSEL                     ((uint16)0x0008)            /*!<Half-Duplex Selection       */
#define  USART_CR3_NACK                      ((uint16)0x0010)            /*!<Smartcard NACK enable       */
#define  USART_CR3_SCEN                      ((uint16)0x0020)            /*!<Smartcard mode enable       */
#define  USART_CR3_DMAR                      ((uint16)0x0040)            /*!<DMA Enable Receiver         */
#define  USART_CR3_DMAT                      ((uint16)0x0080)            /*!<DMA Enable Transmitter      */
#define  USART_CR3_RTSE                      ((uint16)0x0100)            /*!<RTS Enable                  */
#define  USART_CR3_CTSE                      ((uint16)0x0200)            /*!<CTS Enable                  */
#define  USART_CR3_CTSIE                     ((uint16)0x0400)            /*!<CTS Interrupt Enable        */
#define  USART_CR3_ONEBIT                    ((uint16)0x0800)            /*!<USART One bit method enable */

/******************  Bit definition for USART_GTPR register  ******************/
#define  USART_GTPR_PSC                      ((uint16)0x00FF)            /*!<PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_PSC_0                    ((uint16)0x0001)            /*!<Bit 0 */
#define  USART_GTPR_PSC_1                    ((uint16)0x0002)            /*!<Bit 1 */
#define  USART_GTPR_PSC_2                    ((uint16)0x0004)            /*!<Bit 2 */
#define  USART_GTPR_PSC_3                    ((uint16)0x0008)            /*!<Bit 3 */
#define  USART_GTPR_PSC_4                    ((uint16)0x0010)            /*!<Bit 4 */
#define  USART_GTPR_PSC_5                    ((uint16)0x0020)            /*!<Bit 5 */
#define  USART_GTPR_PSC_6                    ((uint16)0x0040)            /*!<Bit 6 */
#define  USART_GTPR_PSC_7                    ((uint16)0x0080)            /*!<Bit 7 */

#define  USART_GTPR_GT                       ((uint16)0xFF00)            /*!<Guard time value */




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

#endif /* INC_USART1_REG_H_ */
