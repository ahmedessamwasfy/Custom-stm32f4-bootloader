/*******************************************************************************
 * @file    myGPIO.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    27.06.2019
 *
 * @brief   Some examples on how to use STM32 GPIOs
 *
 * @note    Example: calculate the bit band address of the green LED
 *                   connected to PG13
 *
 *          General equation:
 *          bit_word_addr = bit_band_base + (byte_offset * 32) + (bit_number * 4)
 *
 *          peripheral_base_address = 0x40000000 (Fixed for all ARM Cortex-M4)
 *          bit_band_base           = 0x42000000 (Fixed for all ARM Cortex-M4)
 *          port_G_address          = 0x40021800 (From STM32F4 datasheet)
 *          register_ODR_offset     = 0x14       (From STM32F4 reference manual)
 *
 *          byte_offset = port_G_address + register_ODR_offset - peripheral_base_address
 *                      = 0x40021800 + 0x14 - 0x40000000
 *                      = 0x00021814
 *
 *          bit_number  = 13 (Green LED connected to PG13)
 *
 *          bit_word_addr = 0x42000000 + (0x00021814 * 32) + (13 * 4)
 *                        = 0x42000000 + 0x00430280 + 0x34
 *                        = 0x424302B4
 *
*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_MYGPIO_H_
#define __INC_MYGPIO_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include "datatype.h"
#include "MACROS.h"


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup gpio
 * @{
 */

/**
 * @defgroup gpio_exported_typedefs
 * @{
 */
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,
	PORTI,
	PORTJ,
	PORTK
} GPIO_PORT;

/**
 * @brief  Modes of gpio
 */


typedef enum
{
	gpio_input,
	gpio_output,
	gpio_alternative,
	gpio_analog
}gpio_mode;


/**
 * @brief   On-board LEDs
 */
/*
typedef enum
{
  EVAL_GREEN_LED,
  EVAL_GREEN_LED_BITBAND,
  EVAL_RED_LED,
  EVAL_ALL_LEDs
} Led_Type;
*/


/**
 * @brief   On-board LEDs
 */
typedef enum
{
  myEVAL_GREEN_LED,
  myEVAL_GREEN_LED_BITBAND,
  myEVAL_RED_LED,
  myEVAL_ALL_LEDs
} myLed_Type;


/**
 * @brief  output type of gpio
 */


typedef enum
{
	push_pull,
	open_drain
}gpio_output_type;


/**
 * @brief  pull up / pull downof gpio
 */


typedef enum
{
	no_up_no_down,
	pull_up,
	pull_down
}gpio_pulling;


/**
 * @brief  output speed of gpio
 */


typedef enum
{
	low_speed, 			// 8   MHZ
	medium_speed,		// 50  MHZ
	fast_speed,			// 100 MHZ
	very_fast_speed		// 180 MHZ
}gpio_output_speed;


/**
 * @brief  output value of gpio
 */



typedef enum
{
	low,
	high
}gpio_output_value;






/**
 * @brief  configuration lock of gpio
 */

typedef enum
{
	no_lock,
	lock
}gpio_config_lock;


typedef enum
{
	HIGH,
	LOW
}gpio_output_state;













/**
 * @defgroup gpio_exported_defines
 *
 * @{
 */


/**
 * @brief   Define address of Rcc enable  of SYSCFG
 */
#define  SYSCFG_CMPCR						*((volatile u32 *)(0X40013820))

 /******************  Bit definition for SYSCFG_CMPCR register  ****************/
#define SYSCFG_CMPCR_CMP_PD             	((u32)0x00000001) /*!<Compensation cell power-down */
#define SYSCFG_CMPCR_READY              	((u32)0x00000100) /*!<Compensation cell ready flag */

/**

*/
/**
 * @brief   Define address of Rcc enable  of SYSCFG
 */
#define  RCC_APB2ENR  						*((volatile u32 *)(0X40023844))
#define  RCC_APB2LPENR_SYSCFGLPEN            ((u32)0x00004000)

/**






/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define  RCC_AHB1ENR_GPIOAEN                 ((u32)0x00000001)
#define  RCC_AHB1ENR_GPIOBEN                 ((u32)0x00000002)
#define  RCC_AHB1ENR_GPIOCEN                 ((u32)0x00000004)
#define  RCC_AHB1ENR_GPIODEN                 ((u32)0x00000008)
#define  RCC_AHB1ENR_GPIOEEN                 ((u32)0x00000010)
#define  RCC_AHB1ENR_GPIOFEN                 ((u32)0x00000020)
#define  RCC_AHB1ENR_GPIOGEN                 ((u32)0x00000040)
#define  RCC_AHB1ENR_GPIOHEN                 ((u32)0x00000080)
#define  RCC_AHB1ENR_GPIOIEN                 ((u32)0x00000100)
#define  RCC_AHB1ENR_GPIOJEN                 ((u32)0x00000200)
#define  RCC_AHB1ENR_GPIOKEN                 ((u32)0x00000400)







/**
 * @brief   Define address of Rcc enable  of gpio ports
 */
#define RCC_AHB1ENR  *((volatile u32 *)(0X40023830))

/**


/**
 * @brief   Define base address of peripheral bit-band (Fixed for all ARM Cortex-M4)
 */
#define ALIAS_PERI_BASE  ((u32)(0x40000000))

/**
 * @brief   Define base address of peripheral alias band (Fixed for all ARM Cortex-M4)
 */
#define BITBAND_PERI_BASE ((u32)(0x42000000))

/**
 * @brief   Define address of GPIO (From STM32F4 datasheet) (Memory mapping)
 */
#define myGPIOA_BASE ((u32)(0x40020000))
#define myGPIOB_BASE ((u32)(0x40020400))
#define myGPIOC_BASE ((u32)(0x40020800))
#define myGPIOD_BASE ((u32)(0x40020C00))
#define myGPIOE_BASE ((u32)(0x40021000))
#define myGPIOF_BASE ((u32)(0x40021400))
#define myGPIOG_BASE ((u32)(0x40021800))
#define myGPIOH_BASE ((u32)(0x40021C00))
#define myGPIOI_BASE ((u32)(0x40022000))
#define myGPIOJ_BASE ((u32)(0x40022400))
#define myGPIOK_BASE ((u32)(0x40022800))

/**
 * @brief   Define addres of segisters offset (From STM32F4 reference manual)
 */

#define GPIOx_MODER 	((u32)(0x00)) 	//MODE REGISTER
#define GPIOx_OTYPER	((u32)(0x04)) 	//OUTPUT TYPE REGISTER
#define GPIOx_OSPEEDR	((u32)(0x08))		//OUTPUT SPEED RIGESTER
#define GPIOx_PUPDR 	((u32)(0x0C))		//PULL UP / PULL DOWN
#define GPIOx_IDR 		((u32)(0x10))		//INPUT DATA REGISTER
#define GPIOx_ODR 		((u32)(0x14))		//OTPUT DATA REGISTER
#define GPIOx_BSRRS 	((u32)(0x18))		//BIT SET/RESET REFISTER A
#define GPIOx_BSRRR 	((u32)(0x1A))		//BIT SET/RESET REFISTER b
#define GPIOx_LCKR 		((u32)(0x1C))		// PORT CONFIGURATION LOCK REGISTER
#define GPIOx_AFRL 		((u32)(0x20))		//ALTENATE FUNCTION LOW REGISTER
#define GPIOx_AFRH 		((u32)(0x24))		//ALTENATE FUNCTION HIGH REGISTER








/**
 * @brief   Convert PERI address to alias region
 */
//#define BITBAND_PERI(reg_address, bit_number) ((ALIAS_PERI_BASE + \
 //               (reg_address - BITBAND_PERI_BASE) * 32 + (bit_number * 4)))

/**
 * @brief   Green LED connected to GPIOG bit 13
 */
//#define GREEN_LED_BITBAND *((volatile uint32_t *)(BITBAND_PERI(GPIOG_ODR, 13)))

/**
 * @}
 */

/**
 * @defgroup gpio_exported_macros
 * @{
 */

#define byte_offset(port,reg)  ((u32)((port) + (reg) - ALIAS_PERI_BASE))

//#define bit_word_addr(port,reg,bit)  *(volatile u32 *) (ALIAS_PERI_BASE + ((byte_offset(port,reg)) * 32) /*+(bit * 4)*/)
#define bit_word_addr(port,reg,bit)  *(volatile u32 *) (port + reg /*+(bit * 4)*/)





/* @brief   Define address of GPIOG
*/
#define GPIOG_ODR 0x40021814

#define GREEN_LED_BITBAND *((volatile uint32_t *)(BITBAND_PERI(GPIOG_ODR, 13)))

/**
 * @}
 */

/**
 * @defgroup gpio_exported_constants
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
 * @brief   Any GPIO Pin Output initialization function Alternative / Normal
 * @note
 * @param	Port Name , bit Number , Mode, Alternative function , output type/ ,output speed, pull up / pull down
 * @retval
 */
void GPIO_OUT_INIT(GPIO_PORT port_name , u8 bit_number , gpio_mode mode, u8 AL_fun ,gpio_output_type out_type , gpio_output_speed speed, gpio_pulling  pull_type  );

/**
 * @brief   Any GPIO Pin Output value whether high or low
 * @note
 * @param	Port Name , bit Number , desired state
 * @retval
 */
void GPIO_OUT_VALUE(GPIO_PORT port_name , u8 bit_number ,   gpio_output_state  state  );


/**
 * @brief   Any GPIO Pin input initialization function Alternative / Normal
 * @note
 * @param	Port Name , bit Number , Mode  , Alternative function, pull up_pull down
 * @retval
 */

void GPIO_IN_INIT(GPIO_PORT port_name , u8 bit_number , gpio_mode mode, u8 AL_fun ,gpio_pulling pull_type);



/**
 * @brief   Any GPIO Pin read the input value
 * @note
 * @param	Port Name , bit Number
 * @retval	the input value
 */

u8 GPIO_IN_value(GPIO_PORT port_name , u8 bit_number );



/**
 * @brief   Any GPIO Pin ANALOG initialization functioN
 * @note
 * @param
 * @retval
 */


void GPIO_ANALOG_INIT();


/**
 * @brief   On-board LEDs initialization function
 * @note    EVAL_GREEN_LED -> PG13
 * @param
 * @retval
 */
void myGPIO_Init_LED(myLed_Type led);

/**
 * @brief   Turns on-board LED on
 * @note    EVAL_GREEN_LED -> PG13
 * @param   Led_Type led
 * @retval
 */
void myGPIO_TurnON_LED(myLed_Type led);

/**
 * @brief   Turns on-board LED off
 * @note    EVAL_GREEN_LED -> PG13
 * @param   Led_Type led
 * @retval
 */
void myGPIO_TurnOFF_LED(myLed_Type led);

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

#endif /*__INC_MYGPIO_H_ */
