/********************************************************************
**
** 
** file    		ImageHeader.c
** author  		Ahmed Wasfy
** email   		ahmedessam0128@gmail.com
** date    		Jan 16, 2022
** Target  		STM32F4291-discoveryboard
** Version     	1.0.0
**
** brief   		ImageHeader.c 
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


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

/* Inclusion of system and local header files goes here */

/**
 * brief   
 */

#include "ImageHeader.h"


/* ==================================================================== */
/* ======================== Macros and Defines ======================== */
/* ==================================================================== */

/* #define and enum statements and macros go here */

/**
 * brief   
 */


/* ==================================================================== */
/* ======================= Exported Variables ========================== */
/* ==================================================================== */

/* Global variables definitions go here */

/**
 * brief  
 */




/* ==================================================================== */
/* ========================== private data ============================ */
/* ==================================================================== */

/* Definition of private datatypes go here */

extern uint32_t _sidata;
extern uint32_t Reset_Handler;

/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

/* Function prototypes for public (external) functions go here */



/* ==================================================================== */
/* ====================== private functions =========================== */
/* ==================================================================== */

/* Function prototypes for private (static) functions go here */



/* ==================================================================== */
/* =================== Exported Public functions ====================== */
/* ==================================================================== */

/* Function prototypes for public (external) functions go here */


/**
 * brief
 * note
 * param   void
 * retval  void
 */
//static sectiontry __attribute__ ((section(".try_section"))) sectiontry1 = {
//		 5,
//		"AHMED WASFY",
//		1,
//		0X22,
//			'Z'
//};


static volatile const ImgHeader_t __attribute__ ((section(".image_header")))  ImagHeader =
{
   .ImageVersion=0x1,
   .ImageID=0x1254,
   .ImageStartAddr=0x08040000,
   .CRC32=0xced299eb,
   .StackPointer=0x20030000,
   .EntryPointAddr=((uint32_t) &Reset_Handler ),
   .VectorTableAddr=0x08040000,
   .ImageHeaderOffset=0x200,
   .ImageEnd=((uint32_t) &_sidata ),//7f0 -250 = 0x5A0,
   .ImageCRCStart=0x08040250,

} ;
