/*******************************************************************************
 * @file    exti.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   EXTI examples
 * @note
 *
*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_EXTI_H_
#define __INC_EXTI_H_

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
 * @addtogroup exti
 * @{
 */

/**
 * @defgroup exti_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_exported_functions
 * @{
 */

/**
 * @brief   Push button EXTI initialization function
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_Init_PB();

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

#endif /*__INC_EXTI_H_ */
