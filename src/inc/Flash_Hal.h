

/*******************************************************************************
 * @file    Flash_Hal.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Jul 6, 2021
 *
 * @brief   Flash_Hal.h example using ST virtual COM port (VCP)
 * @note
 *
@verbatim
Copyright (C) Ahnmed Wasfy 2021

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
 * Flash_Hal.h
 *
 *  Created on: Jul 6, 2021
 *      Author: Ahmed Wasfy
 */

#ifndef INC_FLASH_HAL_H_
#define INC_FLASH_HAL_H_

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
#include "stm32f4xx.h"

#include "DMA_Implement.h"
#include "myUSART1.h"
#include "ImageHeader.h"
#include "crc.h"
#include "EEprom_Emulation.h"


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup Flash_Hal.h
 * @{
 */

/**
 * @defgroup Flash_Hal.h_exported_typedefs
 * @{
 */
typedef enum{
	NoISR,
	End_Of_Operation,
	Error_Of_Operation,
}Flash_Interrupt_State;


/**
 * @brief   FLASH states definition
 */
typedef enum
{
  FLASH_IDLE,
  FLASH_WAIT_FOR_CMD,
} FLASH_StateType;



/**
 * @brief   USART1 RX message buffer
 */
 char FlashRxBuffer[MAX_BUFFER_LENGTH];
 char FlashRxDMABuffer[MAX_BUFFER_LENGTH];
/**
 * @brief   USART1 RX message length
 */
 uint8_t FlashRxMessageLength;




  Flash_Interrupt_State Flash_ISR_State_Var;

 /**
  * @brief   Flash current state
  */
  FLASH_StateType Flash_currentState ;

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.h_exported_functions
 * @{
 */






/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_GPIO_Config(void);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_Init(void);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_TX_DMA_Config(void);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_RX_DMA_Config(void);

/**
 * @brief  
 * @note   
 * @param   void
 * @retval  void
 */
void Flash_USART1_Enable(void);

void Flash_USART1_Init(void);

void FLASH_USART1_IRQ_Callback(void);
void FLASH_USART1_TX_DMA_IRQ_Callback(void);
void FLASH_USART1_RX_DMA_IRQ_Callback(void);
void FLASH_IRQ_Callback(void);


/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_Init(void);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_Main(void);


/**
 * @brief used to check the if the first image is available
 * @note
 * @param   void
 * @retval  OK if stack pointer is correct NOT_OK if stack pointer is invalid
 */
u8 Main_IMG_Available();

/**
 * @brief used to check if the second image is available
 * @note
 * @param   void
 * @retval  OK if stack pointer is correct NOT_OK if stack pointer is invalid
 */
u8 Secondary_IMG_Available();


/**
 * @brief
 * @note
 * @param   void
 * @retval  uint32_t the image to be loaded
 */
void Jump_To_APP(uint32_t image);


/**
 * @brief
 * @note
 * @param   void
 * @retval  uint32_t the image to be valdated
 */
uint32_t CRC_validation(uint32_t image);

/**
 * @brief in case the crc is wrong we change the active image to the privious one
 * @note
 * @param   uint32 the current active image
 * @retval 	the new active image
 */
uint32_t Change_Active_Image(uint32_t currentActiveImage);


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_FLASH_HAL_H_ */
