

/*******************************************************************************
 * @file    USART1_PRIV.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 17, 2019
 *
 * @brief   USART1_PRIV.h example using ST virtual COM port (VCP)
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
 * USART1_PRIV.h
 *
 *  Created on: Sep 17, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_USART1_PRIV_H_
#define INC_USART1_PRIV_H_

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


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup USART1_PRIV.h
 * @{
 */

/**
 * @defgroup USART1_PRIV.h_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_PRIV.h_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_PRIV.h_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_PRIV.h_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1_PRIV.h_exported_functions
 * @{
 */

/**
 * @brief   Configure GPIO with AF7, USART1 connected to APB2 with 90MHz clock
 * @note    PA9 -> USART1_TX, PA10 -> USART1_RX
 * @param   None
 * @retval  None
 */
void myUSART1_GPIO_Config(void);


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* INC_USART1_PRIV_H_ */
