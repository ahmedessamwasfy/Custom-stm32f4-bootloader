

/*******************************************************************************
 * @file    USART1.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 16, 2019
 *
 * @brief   USART1.h example using ST virtual COM port (VCP)
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

#ifndef INC_MYUSART1_H_
#define INC_MYUSART1_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif



/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	





/* Includes */

#include"Std_Types.h"
#include"myGPIO.h"

#include"USART1_Reg.h"
#include"USART1_PRIV.h"
#include"USART1_Cfg.h"
#include "DMA_Implement.h"




/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup USART1.h
 * @{
 */
//typedef enum
//{
//  USART1_NO_IRQ,
//  USART1_CHAR_RECEIVED,
//  USART1_PARITY_ERROR,
//} USART1_IRQStatusType;
//

//
//
//USART1_IRQStatusType currentIRQStatus = USART1_NO_IRQ;
//
// char RxChar = 0;
//
//

/**
 * @brief   USART1 states definition
 */
typedef enum
{
  USART1_IDLE,
  USART1_WAIT_FOR_RESPONCE,
  USART1_ASK_FOR_NAME,
  USART1_WAIT_FOR_NAME,
  USART1_WAIT_FOR_COMMAND,
} USART1_StateType;



///**
// * @brief   USART1 IRQ status definition
// */
typedef enum
{
  USART1_NO_IRQ,
  USART1_CHAR_RECEIVED,
  USART1_PARITY_ERROR,
} USART1_IRQStatusType;



/**
 * @brief   Return type
 */
typedef enum
{
  STR_NOT_EQUAL,
  STR_EQUAL
} strCmpReturnType;




typedef enum
{
  USART1_NO_ERROR,
  USART1_PARITY_ERROR_With_DMA
} USART1_ErrorStatusType;



///**
//* @brief   USART1 current IRQ status
//*/
 USART1_IRQStatusType currentIRQStatus ;


 /* @brief   USART1 current state
 */
  USART1_StateType currentState ;

  /**
   * @brief   USART1 current error status
   */
   USART1_ErrorStatusType currentErrorStatus;



 char RxChar;

char RX_FLAG;
/**
 * @brief   Maximum USART reception buffer length
 */
#define MAX_BUFFER_LENGTH         ((uint32_t) 128u)


uint8 RxDMABuffer[MAX_BUFFER_LENGTH];


 /**
 * @brief   USART1 message buffer
 */
uint8 RxBuffer[MAX_BUFFER_LENGTH+1 ];

 /**
 * @brief   USART1 message length
 */
 uint8_t RxMessageLength ;



 char TxDMABuffer[MAX_BUFFER_LENGTH];

 uint8_t TxMessageLength ;



/*
 * @brief the Pointer to functions  in order to call in ISR
 * */

//
//
 void (* USART1_RECIEVE_callBack_function_pointer)(void);

 void (*USART1_TRANSMIT_DATA_EMPTY_callBack_function_pointer)(void);

 void (*USART1_CTS_callBack_function_pointer)(void);

 void (*USART1_TRANSMIT_COMPLETE_callBack_function_pointer)(void);

 void (*USART1_OVERRUN_ERROR_callBack_function_pointer)(void);

 void (*USART1_IDLE_LINE_DETECT_callBack_function_pointer)(void);

 void (*USART1_PARITY_ERROR_callBack_function_pointer)(void);

 void (*USART1_BREAK_FLAG_callBack_function_pointer)(void);



/**
 * @defgroup USART1.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.h_exported_functions
 * @{
 */


//int x;

 void  USART1_RECIEVE_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_TRANSMIT_DATA_EMPTY_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_CTS_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_TRANSMIT_COMPLETE_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_OVERRUN_ERROR_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_IDLE_LINE_DETECT_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_PARITY_ERROR_CallBack_function_Set(void (*fun_ptr)(void));


 void  USART1_BREAK_FLAG_CallBack_function_Set(void (*fun_ptr)(void));


 /**
  * @brief   Configure DMA for USART TX
  * @note    USART1_TX -> DMA2_Stream7 (Channel 4)
  * @param   None
  * @retval  None
  */
 void USART1_TX_DMA_Config(void);

 /**
  * @brief   Configure DMA for USART RX
  * @note    USART1_RX -> DMA2_Stream5 (Channel 4)
  * @param   None
  * @retval  None
  */
 void USART1_RX_DMA_Config(void);



/**
 * @brief   Configure USART1 for ST virtual COM port (VCP)
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Init(void);

/**
 * @brief   Enable USART1 transmitter and receiver
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Enable(void);


/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Process(void);

/**
 * @brief   USART1 transmit and receive data in DMA Example
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Process_with_DMA(void);


void strTransmit_with_DMA(const char * str, uint8_t size);

void USART1_STR_Transmit(const char * str, uint8 size);

void USART1_CHAR_Transmit(const char  CHAR);
/**
 * @brief   String receive
 * @note
 * @param   None
 * @retval  None
 */
uint32 USART_Receive(void);


u8 USART1_CHAR_Receive(void);



void USART_transmit_complete_checker(void);
uint32 USART_error_checker(void);
void USART_DATA_REG_checker(void);



void USART_Send_sring(u8 * data);

void USART1_IRQ_Callback(void);


/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_TX_DMA_IRQ_Callback(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_RX_DMA_IRQ_Callback(void);

/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_DMA_Process(void);





/*****Functions TO DO***/

void USART1_Init_V2(void);

void USART1_Send(void);

 void USART1_Recuve(void);

 void USART1_FIFO_EN(void);

 void USART1_FIFO_DIS(void);

 void USART1_EN(void);

 void USART1_Dis(void);

 void USART1_TX_EN(void);

 void USART1_TX_Dis(void);

 void USART1_RX_EN(void);

 void USART1_RX_Dis(void);

 void USART1_CLK_SET(void);

 void USART1_CLK_GET(void);

 void USART1_Interrupt_MASK_Set(void);

 void USART1_Interrupt_MASK_Get(void);

 void USART1_Interrupt_Clear(void);

 void USART1_Line_Control(void);

/* @}
 */
/**
 * @}
 */
/**
 * @}
 */



#endif /* INC_MYUSART1_H_ */
