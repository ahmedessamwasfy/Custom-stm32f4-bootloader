

/*******************************************************************************
 * @file    GPT_2TO5.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 28, 2019
 *
 * @brief   GPT_2TO5.h example using ST virtual COM port (VCP)
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
 * GPT_2TO5.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_GPT_2TO5_H_
#define INC_GPT_2TO5_H_

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
#include"GPT_2TO5_Cfg.h"


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup GPT_2TO5.h
 * @{
 */

/**
 * @defgroup GPT_2TO5.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup GPT_2TO5.h_exported_functions
 * @{
 */



/**
 * @brief  it initialize the settings of  general purpos timer 3
 * @note   the setting are precompiled
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Init(void);


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Enable(void);


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Update_Event(void);


/**
 * @brief  
 * @note   
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Set_Prescaler(uint16 prescaler);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_Auto_Reload_Set(uint16 value);



/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

uint16 GPT_Timer_3_Get_counter(void);




/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_3_IRQ_Callback(void);









/**
 * @brief  it initialize the settings of  general purpos timer 3
 * @note   the setting are precompiled
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Init(void);


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Enable(void);


/**
 * @brief  it Enable
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Update_Event(void);


/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Set_Prescaler(uint16 prescaler);

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_Auto_Reload_Set(uint16 value);



/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

uint16 GPT_Timer_4_Get_counter(void);




/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

void GPT_Timer_4_IRQ_Callback(void);





/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_GPT_2TO5_H_ */
