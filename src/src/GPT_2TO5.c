

/*******************************************************************************
 * @file    GPT_2TO5.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Nov 18, 2019
 *
 * @brief   GPT_2TO5.c example using ST virtual COM port (VCP)
 * @note
 *
@verbatim
Copyright (C) Ahnmed Wasfy 2019

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

//* Includes */
//* Includes */
#include "GPT_2TO5.h"


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup GPT_2TO5.c
 * @brief
 * @{
 */

/**
 * @defgroup GPT_2TO5.c_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.c_exported_functions
 * @{
 */



/**
 * @brief  it initialize the settings of  general purpos timer 3
 * @note   the setting are precompiled
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Init(void){

	// Activate the timer clock
	RCC_APB1ENR|=RCC_APB1ENR_TIM3EN;

	//start configure timer control register 1
	TIMER3_CR1|=TIMER3_CR1_CKD|(TIMER3_CR1_ARPE)|(TIMER3_CR1_DIR*TIM_CR1_DIR)\
			    |(TIMER3_CR1_OPM*TIM_CR1_OPM)|(TIMER3_CR1_URS*TIM_CR1_URS)|(TIMER3_CR1_UDIS*TIM_CR1_UDIS);

	//start configure timer control register 2

	TIMER3_CR2|=TIMER3_CR2_MMS|(TIMER3_CR2_CCDS*TIM_CR2_CCDS)|(TIMER3_CR2_TI1S*TIM_CR2_TI1S);

	//start configure timer slave mode control  register
	TIMER3_SMCR|=(TIMER3_SMCR_ETP*TIM_SMCR_ETP)|(TIMER3_SMCR_ECE*TIM_SMCR_ECE)|TIMER3_SMCR_ETPS\
				 |TIMER3_SMCR_ETPS|(TIMER3_SMCR_MSM*TIM_SMCR_MSM)|TIMER3_SMCR_TS|TIMER3_SMCR_TS;

	//start configure timer DMA/INTERRUPT ENABLE register
	TIMER3_DIER|=(TIMER3_DIER_TDE*TIM_DIER_TDE)|(TIMER3_DIER_CC4DE*TIM_DIER_CC4DE)|(TIMER3_DIER_CC3DE*TIM_DIER_CC3DE)\
				 |(TIMER3_DIER_CC2DE*TIM_DIER_CC2DE)|(TIMER3_DIER_CC1DE*TIM_DIER_CC1DE)|(TIMER3_DIER_UDE*TIM_DIER_UDE)\
				 |(TIMER3_DIER_TIE*TIM_DIER_TIE)|(TIMER3_DIER_CC4IE*TIM_DIER_CC4IE)|(TIMER3_DIER_CC3IE*TIM_DIER_CC3IE)\
				 |(TIMER3_DIER_CC2IE*TIM_DIER_CC2IE)|(TIMER3_DIER_CC1IE*TIM_DIER_CC1IE)|(TIMER3_DIER_UIE*TIM_DIER_UIE);

	//start configure EVENT GENETATION  register
	TIMER3_EGR|=(0);


	/* Set timer Prescaler, bus clock = 45 MHz, fCK_PSC / (PSC[15:0] + 1)
	 * CK_CNT = 45000000 / (44999 + 1) -> 1000 Hz -> time base = 1 ms */
	TIMER3_PSC=TIMER3_PSC_PSC;


	  /* Set timer reload value */

	TIMER3_ARR=TIMER3_ARR_ARR;

}


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Enable(void){

	TIMER3_CR1|=TIM_CR1_CEN;

}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Set_Prescaler(uint16 prescaler){

	TIMER3_PSC=prescaler;
	//TIMER3_CNT=0;


}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Auto_Reload_Set(uint16 value){

	TIMER3_ARR|=value;
	//TIMER3_CNT=0;
}



/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

uint16 GPT_Timer_3_Get_counter(void){

	return TIMER3_CNT;
}









/**
 * @brief  it initialize the settings of  general purpos timer 3
 * @note   the setting are precompiled
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Init(void){

	// Activate the timer clock
	RCC_APB1ENR|=RCC_APB1ENR_TIM4EN;

	//start configure timer control register 1
	TIMER4_CR1|=TIMER4_CR1_CKD|(TIMER4_CR1_ARPE)|(TIMER4_CR1_DIR*TIM_CR1_DIR)|TIMER3_CR1_CMS\
			    |(TIMER4_CR1_OPM*TIM_CR1_OPM)|(TIMER4_CR1_URS*TIM_CR1_URS)|(TIMER4_CR1_UDIS*TIM_CR1_UDIS);

	//start configure timer control register 2

	TIMER4_CR2|=TIMER4_CR2_MMS|(TIMER4_CR2_CCDS*TIM_CR2_CCDS)|(TIMER4_CR2_TI1S*TIM_CR2_TI1S);

	//start configure timer slave mode control  register
	TIMER4_SMCR|=(TIMER4_SMCR_ETP*TIM_SMCR_ETP)|(TIMER4_SMCR_ECE*TIM_SMCR_ECE)|TIMER4_SMCR_ETPS\
				 |TIMER4_SMCR_ETPS|(TIMER4_SMCR_MSM*TIM_SMCR_MSM)|TIMER4_SMCR_TS|TIMER4_SMCR_TS;

	//start configure timer DMA/INTERRUPT ENABLE register
	TIMER4_DIER|=(TIMER4_DIER_TDE*TIM_DIER_TDE)|(TIMER4_DIER_CC4DE*TIM_DIER_CC4DE)|(TIMER4_DIER_CC3DE*TIM_DIER_CC3DE)\
				 |(TIMER4_DIER_CC2DE*TIM_DIER_CC2DE)|(TIMER4_DIER_CC1DE*TIM_DIER_CC1DE)|(TIMER4_DIER_UDE*TIM_DIER_UDE)\
				 |(TIMER4_DIER_TIE*TIM_DIER_TIE)|(TIMER4_DIER_CC4IE*TIM_DIER_CC4IE)|(TIMER4_DIER_CC3IE*TIM_DIER_CC3IE)\
				 |(TIMER4_DIER_CC2IE*TIM_DIER_CC2IE)|(TIMER4_DIER_CC1IE*TIM_DIER_CC1IE)|(TIMER4_DIER_UIE*TIM_DIER_UIE);

	//start configure EVENT GENETATION  register
	TIMER4_EGR|=(0);


	/* Set timer Prescaler, bus clock = 45 MHz, fCK_PSC / (PSC[15:0] + 1)
	 * CK_CNT = 45000000 / (44999 + 1) -> 1000 Hz -> time base = 1 ms */
	TIMER4_PSC=TIMER4_PSC_PSC;


	  /* Set timer reload value */

	TIMER4_ARR=TIMER4_ARR_ARR;

}


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Enable(void){

	TIMER4_CR1|=TIM_CR1_CEN;

}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Set_Prescaler(uint16 prescaler){

	TIMER4_PSC=prescaler;
	//TIMER4_CNT=0;


}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Auto_Reload_Set(uint16 value){

	TIMER4_ARR|=value;
	//TIMER4_CNT=0;
}



/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

uint16 GPT_Timer_4_Get_counter(void){

	return TIMER4_CNT;
}







/**
 * @brief   
 * @note    
 *          
 * @param   None
 * @retval  None
 */


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
