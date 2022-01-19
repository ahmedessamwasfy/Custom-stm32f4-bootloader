/********************************************************************
**
** 
** file    		ImageHeader.h
** author  		Ahmed Wasfy
** email   		ahmedessam0128@gmail.com
** date    		Dec 29, 2021
** Target  		STM32F4291-discoveryboard
** Version     	1.0.0
**
** brief   		ImageHeader.h 
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



#ifndef INC_IMAGEHEADER_H_
#define INC_IMAGEHEADER_H_


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

#include  "stm32f4xx.h"



/* ==================================================================== */
/* ======================== Macros and Defines ======================== */
/* ==================================================================== */

/* #define and enum statements and macros go here */

/**
 * @brief   
 */

/* ==================================================================== */
/* ========================== TypeDefines  ============================ */
/* ==================================================================== */

/* Struct and typedef go here */

/**
 * @brief   
 */

typedef struct {
  uint32_t ImageVersion;
  uint32_t ImageID;
  uint32_t ImageStartAddr;
  uint32_t ImageEndAddr;
  uint32_t CRC32;
  uint32_t StackPointer;
  uint32_t EntryPointAddr;
  uint32_t VectorTableAddr;
  uint32_t ImageHeaderOffset;
  uint32_t ImageEnd;
  uint32_t ImageCRCStart;
} ImgHeader_t;



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

 
#endif /* INC_IMAGEHEADER_H_ */
