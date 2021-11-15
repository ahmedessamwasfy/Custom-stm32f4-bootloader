
/*******************************************************************************
 * @file    rcc.c
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   RCC Examples
 * @note
 *

*******************************************************************************/

/* Includes */
#include "myRCC.h"
#include "SysTick.h"
#include "gpio.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup rcc
 * @brief
 * @{
 */

/**
 * @defgroup rcc_private_typedefs
 * @{
 */

/**
 * @brief   Reset sources
 */
typedef enum
{
  WINDOW_WATCHDG,
  INDEPENDENT_WATCHDOG,
  RESET_SOURCE_UNKNOWN,
  POWER_ON_POWER_DOWN,
  SOFTWARE_RESET,
  LOW_LEVEL_ON_NRST
} ResetSource_Type;

/**
 * @}
 */

/**
 * @defgroup rcc_private_defines
 * @{
 */
/**
 * @brief   AF PA8 pin mask
 */
#define GPIO_AFRH_AFRH8                      ((uint32_t) 0x0000000F)

/**
 * @}
 */

/**
 * @defgroup rcc_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_private_variables
 * @{
 */

/**
 * @brief   Reset source
 */
static ResetSource_Type resetSource = RESET_SOURCE_UNKNOWN;

/**
 * @}
 */

/**
 * @defgroup rcc_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_functions
 * @{
 */

/**
 * @brief   Perform system reset
 * @note
 * @param   None
 * @retval  None
 */
void RCC_SystemReset(void)
{
  /* Perform system reset */

  //NVIC_SystemReset();
	SCB_AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      |
                 (SCB_AIRCR & SCB_AIRCR_PRIGROUP_Msk) |
                 SCB_AIRCR_SYSRESETREQ_Msk);                   /* Keep priority group unchanged */
  while(1);
}

/**
 * @brief   Detect system reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_DetectResetSource(void)
{
  u16 tmp;

  /* Read RCC clock control & status register (RCC_CSR)
   * to detect reset source */
  tmp = RCC_clock_control_status_register;

  /* Detect reset source */
  if(RCC_CSR_SFTRSTF == (tmp & RCC_CSR_SFTRSTF))
  {
    /* Reset source is software request */
    resetSource = SOFTWARE_RESET;
  }
  else if(RCC_CSR_WDGRSTF == (tmp & RCC_CSR_PORRSTF))
  {
    /* Reset source is power on/down */
    resetSource = INDEPENDENT_WATCHDOG;
  }
  else if(RCC_CSR_WWDGRSTF == (tmp & RCC_CSR_PORRSTF))
  {
    /* Reset source is power on/down */
    resetSource = WINDOW_WATCHDG;
  }
  else if(RCC_CSR_PORRSTF == (tmp & RCC_CSR_PORRSTF))
  {
    /* Reset source is power on/down */
    resetSource = POWER_ON_POWER_DOWN;
  }
  else if(RCC_CSR_PADRSTF == (tmp & RCC_CSR_PADRSTF))
  {
    /* Reset source is low level on NRST pin */
    resetSource = LOW_LEVEL_ON_NRST;
  }
  else
  {
    /* Reset source unknown */
    resetSource = RESET_SOURCE_UNKNOWN;
  }

  /* Clear reset flag */
  RCC_clock_control_status_register |= RCC_CSR_RMVF;
}

/**
 * @brief   Turn on LEDs based on reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_ProcessReset(void)
{
  /* Check reset source */
  switch (resetSource)
  {
    case SOFTWARE_RESET:
      /* Blink green LED */
      GPIO_TurnON_LED(EVAL_GREEN_LED);
      SysTick_Delay(500);
      GPIO_TurnOFF_LED(EVAL_GREEN_LED);
      SysTick_Delay(500);
      break;

    case LOW_LEVEL_ON_NRST:
      /* Blink red LED */
      GPIO_TurnON_LED(EVAL_RED_LED);
      SysTick_Delay(500);
      GPIO_TurnOFF_LED(EVAL_RED_LED);
      SysTick_Delay(500);
      break;

    case POWER_ON_POWER_DOWN:
      /* Blink both LEDs */
      GPIO_TurnON_LED(EVAL_GREEN_LED);
      SysTick_Delay(500);
      GPIO_TurnOFF_LED(EVAL_GREEN_LED);
      GPIO_TurnON_LED(EVAL_RED_LED);
      SysTick_Delay(500);
      GPIO_TurnOFF_LED(EVAL_RED_LED);
      SysTick_Delay(500);
      break;

    default:
      break;
  }
}

/**
 * @brief   Setup clock output
 * @note    HSE (8MHz)  -> MCO1(PA8)
 * @param   None
 * @retval  None
 */
void RCC_ClockOut_Setup(void)
{
  /* Enable port A clock */
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

  /* Select alternate function mode */
  GPIOA->MODER &= ~GPIO_MODER_MODER8;
  GPIOA->MODER |= GPIO_MODER_MODER8_1;

  /* Select output speed medium */
  GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR8;
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_0;

  /* Select pull up */
  GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR8;
  GPIOA->PUPDR |= GPIO_PUPDR_PUPDR8_0;

  /* Select AF0 */
  GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH8;

  /* Select HSE as clock source for MCO1 */
  RCC->CFGR &= ~RCC_CFGR_MCO1;
  RCC->CFGR |= RCC_CFGR_MCO1_1;

  /* Select no prescaler for MCO1 */
  RCC->CFGR &= ~RCC_CFGR_MCO1PRE;
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
