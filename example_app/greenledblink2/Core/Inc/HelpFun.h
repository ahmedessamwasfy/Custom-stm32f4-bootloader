/********************************************************************
**
** 
** file    		HelpFun.h
** author  		Ahmed Wasfy
** email   		ahmedessam0128@gmail.com
** date    		Dec 5, 2021
** Target  		STM32F4291-discoveryboard
** Version     	1.0.0
**
** brief   		HelpFun.h 
** note
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
**
********************************************************************/



#ifndef INC_HELPFUN_H_
#define INC_HELPFUN_H_


/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

/* Inclusion of system and local header files goes here */

/**
 * @brief   
 */
#include "stm32f4xx.h"




/* ==================================================================== */
/* ======================== Macros and Defines ======================== */
/* ==================================================================== */

/* #define and enum statements and macros go here */

/**
 * @brief   
 */

#define ASSERT_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))

/**
 * @brief   Memory word access
 */
#define MEM32_ADDRESS(ADDRESS) ((*((volatile unsigned long *)(ADDRESS))))





/* ==================================================================== */
/* ========================== TypeDefines  ============================ */
/* ==================================================================== */

/* Struct and typedef go here */

/**
 * @brief   
 */



/* ==================================================================== */
/* ======================= Exported Variables ========================== */
/* ==================================================================== */

/* Global variables definitions go here */

/**
 * @brief   
 */




/* ==================================================================== */
/* ========================== private data ============================ */
/* ==================================================================== */

/* Definition of private datatypes go here */



/* ==================================================================== */
/* ====================== private functions =========================== */
/* ==================================================================== */

/* Function prototypes for private (static) functions go here */



/* ==================================================================== */
/* =================== Exported Public functions ====================== */
/* ==================================================================== */

/* Function prototypes for public (external) functions go here */

void Error_Handler(void);
void assert_failed(uint8_t *file, uint32_t line);


/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

 
#endif /* INC_HELPFUN_H_ */
