

/*******************************************************************************
 * @file    Bassic_Timer.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 28, 2019
 *
 * @brief   Bassic_Timer.c example using ST virtual COM port (VCP)
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
#include "Basic_Timer.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup Bassic_Timer.c
 * @brief
 * @{
 */

/**
 * @defgroup Bassic_Timer.c_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Bassic_Timer.c_exported_functions
 * @{
 */


/**
 * @brief   Timer6 initializer
 * @note
 * @param
 * @retval
 */
void Basic_Timer_TIM6_INIT(void){

	  /* Enable TIM6 clock */
  RCC_APB1ENR|=RCC_APB1ENR_TIM6EN;


	//# TIMER6_CR1			/*!< TIM control register 1      */
  TIMER6_CR1|=(TIMER6_CR1_ARPE*TIM_CR1_ARPE)|(TIMER6_CR1_OPM*TIM_CR1_OPM)|\
				(TIMER6_CR1_URS*TIM_CR1_URS)|(TIMER6_CR1_UDIS*TIM_CR1_UDIS)|\
				(TIMER6_CR1_CEN*TIM_CR1_UDIS);

	//# TIMER6_CR2			/*!< TIM control register 2      */
  TIMER6_CR2|=TIMER6_CR2_MMS;


    //# TIMER6_DIER			/*!< TIM control register 2      */
  TIMER6_DIER|=(TIMER6_DIER_UDE*TIM_DIER_UDE)|(TIMER6_DIER_UIE*TIM_DIER_UIE);


    //# TIMER6_EGR			/*!< TIM control register 2      */
  TIMER6_EGR|=TIMER6_EGR_UG*TIMER6_EGR;


   //# TIMER6_PSC			/*!< TIM control register 2      */
  TIMER6_PSC= TIMER6_PSC_PSC;


   //# TIMER6_ARR			/*!< TIM control register 2      */
  TIMER6_ARR|=TIMER6_ARR_ARR;
}


/**
 * @brief   Timer6 Update Event
 * @note
 * @param
 * @retval
 */
void Basic_Timer_TIM6_Update_Event(void){

	TIMER6_EGR|=TIM_EGR_UG;
}


/**
 * @brief   Timer6 Set prescaler
 * @note
 * @param	the value of prescaler register to set
 * @retval
 */
void Basic_Timer_TIM6_Set_prescaler(uint16 prescaler){

	TIMER6_PSC=prescaler;
	Basic_Timer_TIM6_Update_Event();

}


/**
 * @brief   Timer6 Auto Reload Set
 * @note
 * @param	the value of auto reload register to set
 * @retval
 */
void Basic_Timer_TIM6_Auto_Reload_Set(uint16 value){

	TIMER6_ARR=value;
	Basic_Timer_TIM6_Update_Event();


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
