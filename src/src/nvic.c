/*******************************************************************************
 * @file    nvic.c
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   NVIC examples
 * @note    
 *

*******************************************************************************/

/* Includes */
#include "nvic.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup nvic
 * @brief
 * @{
 */

/**
 * @defgroup nvic_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup nvic_private_functions
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
void NVIC_Init(void)
{
  /* Set priority group to 3
   * bits[3:0] are the sub-priority,
   * bits[7:4] are the pre-empt priority (0-15) */
  NVIC_SetPriorityGrouping(3);

  /* Set priority levels */
  NVIC_SetPriority(SysTick_IRQn, 0);
  NVIC_SetPriority(EXTI0_IRQn, 1);
  NVIC_SetPriority(DMA1_Stream0_IRQn, 1);
  NVIC_SetPriority(DMA1_Stream2_IRQn, 1);
  NVIC_SetPriority(DMA1_Stream4_IRQn, 1);
  NVIC_SetPriority(DMA1_Stream6_IRQn, 1);
  NVIC_SetPriority(DMA1_Stream7_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream0_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream3_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream4_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream5_IRQn, 1);
  NVIC_SetPriority(DMA2_Stream7_IRQn, 1);
  NVIC_SetPriority(USART1_IRQn, 1);
  NVIC_SetPriority(UART5_IRQn, 1);
  NVIC_SetPriority(TIM4_IRQn, 1);
  NVIC_SetPriority(TIM8_UP_TIM13_IRQn, 1);
  NVIC_SetPriority(TIM8_TRG_COM_TIM14_IRQn, 1);
  NVIC_SetPriority(ADC_IRQn, 1);

  /* Enable interrupts at NVIC */
  NVIC_EnableIRQ(EXTI0_IRQn);
  NVIC_EnableIRQ(DMA1_Stream0_IRQn);
  NVIC_EnableIRQ(DMA1_Stream2_IRQn);
  NVIC_EnableIRQ(DMA1_Stream4_IRQn);
  NVIC_EnableIRQ(DMA1_Stream6_IRQn);
  NVIC_EnableIRQ(DMA1_Stream7_IRQn);
  NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  NVIC_EnableIRQ(DMA2_Stream3_IRQn);
  NVIC_EnableIRQ(DMA2_Stream4_IRQn);
  NVIC_EnableIRQ(DMA2_Stream5_IRQn);
  NVIC_EnableIRQ(DMA2_Stream7_IRQn);
  NVIC_EnableIRQ(USART1_IRQn);
  NVIC_EnableIRQ(UART5_IRQn);
  NVIC_EnableIRQ(TIM4_IRQn);
  NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn);
  NVIC_EnableIRQ(TIM8_TRG_COM_TIM14_IRQn);
  NVIC_EnableIRQ(ADC_IRQn);
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
