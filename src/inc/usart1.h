/*******************************************************************************
 * @file    usart1.h
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   USART1 example using ST virtual COM port (VCP)
 * @note
 *

*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_USART1_H_
#define __INC_USART1_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup usart1
 * @{
 */

/**
 * @defgroup usart1_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup usart1_exported_functions
 * @{
 */

/**
 * @brief   Configure GPIO with AF7, USART1 connected to APB2 with 90MHz clock
 * @note    PA9 -> USART1_TX, PA10 -> USART1_RX
 * @param   None
 * @retval  None
 */
void USART1_GPIO_Config(void);

/**
 * @brief   Configure USART1 for ST virtual COM port (VCP)
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Init(void);

/**
 * @brief   Enable USART1 transmitter and receiver
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Enable(void);

/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */
void USART1_IRQ_Callback(void);

/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Process(void);

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_USART1_H_ */
