/*******************************************************************************
 * @file    SysTick.h
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   SysTick configuration header file
 * @note
 *

*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_SYSTICK_H_
#define __INC_SYSTICK_H_

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
 * @addtogroup SysTick
 * @{
 */

/**
 * @defgroup SysTick_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_exported_functions
 * @{
 */

/**
 * @brief   Increment SysTick counter callback
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_IncrementTicks_cb(void);

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void);

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms);

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void);

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

#endif /*__INC_SYSTICK_H_ */
