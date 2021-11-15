/*******************************************************************************
 * @file    timer.h
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   Timer examples
 * @note

*******************************************************************************/

/* Define to prevent recursive inclusion */

#ifndef INC_MYGENERAL_PURPOSE_TIMER_T2_T5_H_
#define INC_MYGENERAL_PURPOSE_TIMER_T2_T5_H_


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
 * @addtogroup timer
 * @{
 */

/**
 * @defgroup timer_exported_typedefs
 * @{
 */

///////////////////////type define and enums of the data





/**
 * @}
 */

/**
 * @defgroup timer_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup timer_exported_functions
 * @{
 */
/**
 * @brief   Timer6 as up counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM6_UpCount_Config(void);

/**
 * @brief   Timer3 as down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM3_DownCount_Config(void);

/**
 * @brief   Timer4 as up down counter Configuration function
 * @note
 * @param
 * @retval
 */
void TIM4_UpDownCount_Config(void);

/**
 * @brief   Timer4 IRQ callback function
 * @note
 * @param
 * @retval
 */
void TIM4_IRQ_Callback(void);

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

#endif /* INC_MYGENERAL_PURPOSE_TIMER_T2_T5_H_ */
