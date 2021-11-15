/*
 * myEXIT.h
 *
 *  Created on: Jul 6, 2019
 *      Author: HP
 */

#ifndef INC_MYEXIT_H_
#define INC_MYEXIT_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
//#include "stm32f4xx.h"
#include "myGPIO.h"

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
 * @brief   Enum for the trigger of the interrupt
 */


typedef enum {
	RISING ,
	FALLING,
	RISING_FALLING
	}EXIT_EDGE;

typedef enum{
	interrupt,
	event,
	interrupt_event
}EXIT_TYPE;


/**
 * @}
 */

/**
 * @defgroup exti_exported_defines
 * @{
 */

/**************************RCC REGISTERS*******************************/

//////////////////BASE
/**
 * @brief   Define Base address of RCC
 */
#define RCC_BASE 		0x40023800


//////////////////REGISTERS
/**
 * @brief   Define address of EXTI Interrupt mask register
 */
#define RCC_APB2ENR 		*((volatile u32 *) (0X44+RCC_BASE))


//////////////////VALUES
/**
 * @brief   Define Base address of RCC
 */
#define RCC_SYSCFG_ENABLE_VALUE 		0X00004000





/**************************SYSTCFG REGISTERS*******************************/

//////////////////BASE
/**
 * @brief   Define Base address of SYSTCFG
 */
#define SYSCFG_BASE 		0x40013800


/**
 * @brief   Define Base of SYSCFG external interrupt configuration register 1
 */
#define SYSCFG_EXTICR1 	*((volatile u32 *)	(0X08+SYSCFG_BASE))


/**
 * @brief   Define Base of SYSCFG external interrupt configuration register 2
 */
#define SYSCFG_EXTICR2 	*((volatile u32 *)	(0X0C+SYSCFG_BASE))


/**
 * @brief   Define Base of SYSCFG external interrupt configuration register 3
 */
#define SYSCFG_EXTICR3 	*((volatile u32 *)	(0X10+SYSCFG_BASE))


/**
 * @brief   Define Base of SYSCFG external interrupt configuration register 4
 */
#define SYSCFG_EXTICR4 	*((volatile u32 *)	(0X14+SYSCFG_BASE))





/**************************EXIT REGISTERS*******************************/


/**
 * @brief   Define Base address of EXIT
 */
#define EXTI_BASE 		0X40013C00


/**
 * @brief   Define address of EXTI Interrupt mask register // to enable the interrupt
 */
#define EXTI_IMR *((volatile u32 *) (0X00+EXTI_BASE))


/**
 * @brief   Define address of EXTI Event mask register //to enable the event
 */
#define EXTI_EMR  *((volatile u32 *) (0X04+EXTI_BASE))


/**
 * @brief   Define address of EXTI Rising trigger selection register
 */
#define EXTI_RTSR  *((volatile u32 *) (0X08+EXTI_BASE))


/**
 * @brief   Define address of EXTI Falling trigger selection register
 */
#define EXTI_FTSR  *((volatile u32 *) (0X0C+EXTI_BASE))


/**
 * @brief   Define address of  EXTI Software interrupt event register
 */
#define EXTI_SWIER  *((volatile u32 *) (0X10+EXTI_BASE))


/**
 * @brief   Define address of  EXTI Pending register
 */
#define EXTI_PR  *((volatile u32 *) (0X14+EXTI_BASE))







/**
 * @}
 */

/**
 * @defgroup exti_exported_macros
 * @{
 */

/***************************RCC MACROS*******************************/


/**************************SYSTCFG MACROS*******************************/


/**
 * @brief   MACRO to define the address of the alternative SYSCFG Address of EXIT
 */
#define SYSCFG_EXTICR(pin) 	*((volatile u32 *)	(0X08+SYSCFG_BASE+(4*(u32)(pin>>2))))



/**************************EXIT MACROS*******************************/




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
 * @param   port , pin , the edge , eternal interrupt type
 * @retval  None
 */
void EXTI_Init(GPIO_PORT port,u8 pin ,EXIT_EDGE edge ,EXIT_TYPE type );


/**
 * @brief   it enables the external interrupt
 * @note    there is two ways of the or more than two ways,
 *          of software enabling of the external interrupt
 * @param   exit pin
 * @retval  None
 */
void EXTI_SW_ENABLE(u8 pin );


/**
 * @brief   Push button EXTI initialization function
 * @note    one way
 * @param   External interrupt pin
 * @retval  None
 */
void EXTI_MUSKING(u8 pin );




/**
 * @brief   function for clearing the pending of the EXIT
 * @note    On-board push button connected to PA0,
 *          so it can use only EXTI0
 * @param   None
 * @retval  None
 */
void EXTI_CLEAR_PENDING(u8 pin );


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



#endif /* INC_MYEXIT_H_ */
