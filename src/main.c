/*******************************************************************************
 * @file    main.c
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   main application called after startup
 * @note
 *
*******************************************************************************/

/* Includes */

#include "stm32f4xx.h"
#include "nvic.h"
#include "SysTick.h"
#include "gpio.h"
#include "Flash_Hal.h"

//#include"myRCC.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup main
 * @brief
 * @{
 */

/**
 * @defgroup main_private_typedefs
 * @{
 */

///**
//* @brief   USART1 current IRQ status
 //*/
extern USART1_IRQStatusType currentIRQStatus ;


 /* @brief   USART1 current state
 */
 extern USART1_StateType currentState ;

 /**
  * @brief   USART1 current error status
  */
  extern USART1_ErrorStatusType currentErrorStatus ;


extern char RxChar;
//
extern char RX_FLAG;



/*
 * @breif Result of the push button
 * */

volatile u8  PushButton_Result;
/**
 * @}
 */

/**
 * @defgroup main_private_defines
 * @{
 */
/**
 * @brief   Buffer array size
 */
#define BUFFER_SIZE     ((uint32) 500)

//extern char RxDMABuffer[MAX_BUFFER_LENGTH];

/**
 * @}
 */

/**
 * @defgroup main_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_private_variables
 * @{
 */






/**
 * @}
 */

/**
 * @defgroup main_private_function_prototypes
 * @{
 */
		void USART1_Recive_IRQ_Callback(void);
/**
 * @}
 */

/**
 * @defgroup main_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup main_exported_functions
 * @{
 */

/**
 * @brief   Main function
 * @note
 * @param   none
 * @retval  none
 */
int main(void)
{


	SysTick_Init();
	  NVIC_Init();
  //myGPIO_Init_LED(myEVAL_ALL_LEDs);


	  /* Clear PRIMASK, enable IRQs */
	  //__disable_irq();
	  __enable_irq();



	  Flash_USART1_GPIO_Config();
	  Flash_USART1_Init();
	  Flash_USART1_TX_DMA_Config();
	  Flash_USART1_RX_DMA_Config();
	  myUSART1_Enable();
//	  USART1_RECIEVE_CallBack_function_Set(USART1_Recive_IRQ_Callback);


	  Flash_Init();

	  SysTick_Init();
	  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
	                     SysTick_CTRL_TICKINT_Msk   |
	                     SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */


	  /*
	   * init the push button and LEDs
	   * */
	  GPIO_Init_LED(EVAL_ALL_LEDs);
	  GPIO_Init_PB();


	  GPIO_TurnON_LED(EVAL_GREEN_LED);

	  /* Delay for half second after initialization */
	  SysTick_Delay(3000);


	  /*
	   * 1. check the push button if checked
	   * */
	  PushButton_Result= GPIO_Result_PB();

	  /*
	   * 2. if checked jump to flash main
	   * */


	  if (1==PushButton_Result){
		    GPIO_TurnOFF_LED(EVAL_GREEN_LED);

		    Flash_Main();
	  }
	  else{
		  /*
		   * 3. if not checked check the validity of primary image if available boot it by calling jump function
		   * */
		   if(OK==Main_IMG_Available()){

			   Jump_To_Main_IMG();
		   }
		   /*
		    * 4. else check the secondary and boot it
		    * */
		   else if(OK==Secondary_IMG_Available()){
			   Jump_To_Secondary_IMG();
		   }
		   /*
		    * 5. else go into halt mode with RED led ON
		    * */
		   else{
			    GPIO_TurnON_LED(EVAL_RED_LED);
			    while(1);
		   }

	  }

	  /* Infinite loop */
	  while(1);

	  /*			things to do in flash.c
	   * 1. replace the jump option with boot img1 and boot img2
	   * 2. adding version to the boot-loader
	   *
	   * */



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



















void USART1_Recive_IRQ_Callback(void)
{

	//    /* Read character */
		  RxChar = USART1_DR;

	    /* Set IRQ status */
	    currentIRQStatus = USART1_CHAR_RECEIVED;
}
