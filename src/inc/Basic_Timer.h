

/*******************************************************************************
 * @file    Basic_Timer.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 27, 2019
 *
 * @brief   Basic_Timer.h example using ST virtual COM port (VCP)
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

/* Define to prevent recursive inclusion */
/*
 * Basic_Timer.h
 *
 *  Created on: Sep 27, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_BASIC_TIMER_H_
#define INC_BASIC_TIMER_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif



/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	





/* Includes */
#include"Std_Types.h"
#include"Timer_regesters.h"
#include"Basic_Timer_Cfg.h"
/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup Basic_Timer.h
 * @{
 */

/**
 * @defgroup Basic_Timer.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Basic_Timer.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Basic_Timer.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Basic_Timer.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Basic_Timer.h_exported_functions
 * @{
 */
/* ==================================================================== */
/* ============================ Timer 6 ================================= */
/* ==================================================================== */

/**
 * @brief   Timer6 initializer
 * @note
 * @param
 * @retval
 */
void Basic_Timer_TIM6_INIT(void);


/**
 * @brief   Timer6 Update Event
 * @note
 * @param
 * @retval
 */
void Basic_Timer_TIM6_Update_Event(void);


/**
 * @brief   Timer6 Set prescaler
 * @note
 * @param	the value of prescaler register to set
 * @retval
 */
void Basic_Timer_TIM6_Set_prescaler(uint16 prescaler);


/**
 * @brief   Timer6 Auto Reload Set
 * @note
 * @param	the value of auto reload register to set
 * @retval
 */
void Basic_Timer_TIM6_Auto_Reload_Set(uint16 value);



/* ==================================================================== */
/* ============================ Timer 7 ================================= */
/* ==================================================================== */


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_BASIC_TIMER_H_ */
