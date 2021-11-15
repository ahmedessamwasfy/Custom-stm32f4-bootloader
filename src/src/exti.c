/*******************************************************************************
 * @file    exti.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *          
 * @brief   EXTI examples
 * @note    
 *
*******************************************************************************/

/* Includes */
#include "exti.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup exti
 * @brief
 * @{
 */

/**
 * @defgroup exti_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup exti_private_functions
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
void EXTI_Init_PB()
{
  /* Enable SYSCFG clock */
  RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

  /* Map PA0 to EXT0 */
  SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

  /* Enable rising edge trigger */
  EXTI->RTSR |= EXTI_RTSR_TR0;

  /* Disable falling edge trigger */
  EXTI->FTSR &= ~(EXTI_FTSR_TR0);

  /* Enable interrupt line */
  EXTI->IMR |= EXTI_IMR_MR0;

  /* Enable event line */
  EXTI->EMR |= EXTI_EMR_MR0;
}

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
