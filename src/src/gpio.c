/*******************************************************************************
 * @file    gpio.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *          
 * @brief   Some examples on how to use STM32 GPIOs
 * @note    
 *
*******************************************************************************/

/* Includes */
#include "gpio.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup gpio
 * @brief
 * @{
 */

/**
 * @defgroup gpio_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup gpio_exported_functions
 * @{
 */

/**
 * @brief   On-board LEDs initialization function
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_Init_LED(Led_Type led)
{
  /* Check LED type, please */
  switch (led)
  {
    case EVAL_ALL_LEDs:

      /* Enable port G clock */
      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

      /* Reset mode */
      GPIOG->MODER &= ~(GPIO_MODER_MODER13 | GPIO_MODER_MODER14);

      /* Select output mode for pin 13, pin 14 */
      GPIOG->MODER |= GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0;

      /* Select output type push-pull */
      GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_13 | GPIO_OTYPER_OT_14);

      /* Select output speed very high */
      GPIOG->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR13_0 | GPIO_OSPEEDER_OSPEEDR13_1
          | GPIO_OSPEEDER_OSPEEDR14_0 | GPIO_OSPEEDER_OSPEEDR14_1);

      /* Enable SYSCFG clock */
      RCC->APB2ENR |= RCC_APB2LPENR_SYSCFGLPEN;

      /* Enable compensation cell */
      SYSCFG->CMPCR |= SYSCFG_CMPCR_CMP_PD;

      /* Wait till compensation cell is ready */
      while((SYSCFG->CMPCR & SYSCFG_CMPCR_READY) != SYSCFG_CMPCR_READY)
      {

      }

      /* Select no pull */
      GPIOG->PUPDR &= ~(GPIO_PUPDR_PUPDR13 | GPIO_PUPDR_PUPDR14);

      break;

    default:
      break;
  }
}

/**
 * @brief   Push button GPIO initialization function
 * @note    On-board push button connected to PA0
 * @param   None
 * @retval  None
 */
void GPIO_Init_PB()
{
  /* Enable post GPIOA clock in RCC */
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

  /* Select input mode for PA0 */
  GPIOA->MODER &= ~(GPIO_MODER_MODER0);

  /* Select no pull up because it has external pull down */
  GPIOA->PUPDR |= ~(GPIO_PUPDR_PUPDR0);
}

/**
 * @brief   Push button GPIO get output value function
 * @note    On-board push button connected to PA0
 * @param   None
 * @retval  None
 */
u8 GPIO_Result_PB(){
	volatile u8 result;

 result = (GPIOA->IDR)&(GPIO_IDR_IDR_0);
 return result;
}


/**
 * @brief   Turns on-board LED on
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_TurnON_LED(Led_Type led)
{
  switch (led)
  {
    case EVAL_GREEN_LED:
      GPIOG->BSRRL = GPIO_BSRR_BS_13;
      break;

    case EVAL_RED_LED:
      GPIOG->BSRRL = GPIO_BSRR_BS_14;
      break;

    case EVAL_GREEN_LED_BITBAND:
      GREEN_LED_BITBAND = 1;
      break;

    default:
      break;
  }
}

/**
 * @brief   Turns on-board LED off
 * @note    EVAL_GREEN_LED -> PG13
 *          EVAL_RED_LED -> PG14
 * @param   Led_Type led
 * @retval  None
 */
void GPIO_TurnOFF_LED(Led_Type led)
{
  switch (led)
  {
    case EVAL_GREEN_LED:
      GPIOG->BSRRH = GPIO_BSRR_BS_13;
      break;

    case EVAL_RED_LED:
      GPIOG->BSRRH = GPIO_BSRR_BS_14;
      break;

    case EVAL_GREEN_LED_BITBAND:
      GREEN_LED_BITBAND = 0;
      break;

    default:
      break;
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
