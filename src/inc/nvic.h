/*******************************************************************************
 * @file    nvic.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   NVIC examples
 * @note
 *

*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_NVIC_H_
#define __INC_NVIC_H_

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
 * @addtogroup nvic
 * @{
 */

/**
 * @defgroup nvic_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_exported_functions
 * @{
 */

/**
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   None
 * @retval  None
 */
void NVIC_Init(void);

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

#endif /*__INC_IRQ_H_ */
