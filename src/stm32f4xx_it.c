/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Template/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    18-January-2013
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

//#include <USART1.h>

#include <nvic.h>
#include "stm32f4xx_it.h"
#include "SysTick.h"
#include "myUSART1.h"
#include "myEXIT.h"
//#include "gpio.h"
#include "myGPIO.h"
#include "myRCC.h"
#include "Flash_Hal.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  SysTick_IncrementTicks_cb();
}


/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
/******************************************************************************/

/**
  * @brief  This function handles EXTI0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
	  RCC_SystemReset();

}

/**
  * @brief  This function handles EXTI1 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI1_IRQHandler(void)
{

}

/**
  * @brief  This function handles EXTI2 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI2_IRQHandler(void)
{

}

/**
  * @brief  This function handles EXTI3 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI3_IRQHandler(void)
{

}

/**
  * @brief  This function handles DMA2 Stream0 interrupt request.
  * @param  None
  * @retval None
  */
void DMA2_Stream0_IRQHandler(void)
{
  /* Check transfer complete flag */
  if(DMA_LISR_TCIF0 == (DMA_LISR_TCIF0 & DMA2->LISR))
  {
    /* DMA transfer is complete, turn off green LED */
    myGPIO_TurnOFF_LED(myEVAL_GREEN_LED);

    /* Clear transfer complete flag */
    DMA2->LIFCR = DMA_LIFCR_CTCIF0;
  }
  else
  {
    /* Turn on red LED, this interrupt is not handled */
    myGPIO_TurnON_LED(myEVAL_RED_LED);
  }
}





/**
  * @brief  This function handles DMA2 Stream5 interrupt request.
  * @param  None
  * @retval None
  */
void DMA2_Stream5_IRQHandler(void)
{
	FLASH_USART1_RX_DMA_IRQ_Callback();
}

/**
  * @brief  This function handles DMA2 Stream7 interrupt request.
  * @param  None
  * @retval None
  */
void DMA2_Stream7_IRQHandler(void)
{
	FLASH_USART1_TX_DMA_IRQ_Callback();
}


/**
  * @brief  This function handles USART1 interrupt request.
  * @param  None
  * @retval None
  */




/**
  * @brief  This function handles USART1 interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
//	USART1_STR_Transmit("  Entered  the IRQ  ",20);

	//my_USART1_IRQ_Callback();
	//callBack_function_pointer();

	FLASH_USART1_IRQ_Callback();

}


void FLASH_IRQHandler (void)
{
	FLASH_IRQ_Callback();
	}

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
