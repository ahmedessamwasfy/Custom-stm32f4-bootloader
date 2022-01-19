/*******************************************************************************
 * @file    SysTick.c
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   SysTick configuration source file
 * @note    
 *

*******************************************************************************/

/* Includes */
#include "SysTick.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup SysTick
 * @brief
 * @{
 */

/**
 * @defgroup SysTick_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_private_variables
 * @{
 */

/**
 * @brief   Variable to store millisecond ticks
 */
volatile uint32_t SysTickCounter = 0;

/**
 * @}
 */

/**
 * @defgroup SysTick_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup SysTick_private_functions
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
void SysTick_IncrementTicks_cb(void)
{
  ++SysTickCounter;
}

/**
 * @brief   Return current SysTick counter
 * @note
 * @param   None
 * @retval  SysTickCounter
 */
uint32_t SysTick_GetCurrentTick(void)
{
  return(SysTickCounter);
}

/**
 * @brief   Delay function based on SysTick
 * @note    SysTick will be update with IRQ callback
 * @param   Waiting time in milliseconds
 * @retval  None
 */
void SysTick_Delay(uint32_t wait_time_ms)
{
  /* Store start tick */
  uint32_t startTick = SysTickCounter;

  /* Loop until timeout */
  while((SysTickCounter - startTick) < wait_time_ms)
  {

  }
}

/**
 * @brief   SysTick initial configuration
 * @note
 * @param   None
 * @retval  None
 */
void SysTick_Init(void)
{
  uint32_t returnCode;

  /* Update clock configuration */
  SystemCoreClockUpdate();

  /* Check clock configuration */
  if(SystemCoreClock != (uint32_t) 180000000)
  {
    /* Clock configuration is not OK */
    while(1)
    {

    }
  }
  else
  {
    /* Clock configuration is OK */
  }

  /* Configure SysTick to generate an interrupt every millisecond */
  returnCode = SysTick_Config(SystemCoreClock / 1000);

  /* Check return code for errors */
  if (returnCode != 0)
  {
    /* SysTick configuration failed */
    while(1)
    {

    }
  }
  else
  {
    /* Do nothing, SysTick configuration OK */
  }
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
