/********************************************************************
 **
 **
 ** file    		EEprom_Emulation.h
 ** author  		Ahmed Wasfy
 ** email   		ahmedessam0128@gmail.com
 ** date    		Dec 29, 2021
 ** Target  		STM32F4291-discoveryboard
 ** Version     	1.0.0
 **
 ** brief   		EEprom_Emulation.h
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

#ifndef INC_EEPROM_EMULATION_H_
#define INC_EEPROM_EMULATION_H_

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

/**
 * brief
 */
#include "stm32f4xx.h"
#include "Std_Types.h"
#include"HelpFun.h"

/* ==================================================================== */
/* ======================== Macros and Defines ======================== */
/* ==================================================================== */

/* #define and enum statements and macros go here */

/**
 * @brief   
 */
#define SECTIONNUMBER (14u)

#define SECTION14ADDRESS	(volatile uint32*)0x8108000

#define SECTION15ADDRESS	(volatile uint32*)0x810C000

#define SECTION23ADDRESS	(volatile uint32*)0x81E0000



#if (14 == SECTIONNUMBER)

#define SECTIONADDRESS  SECTION14ADDRESS

#elif(15 == SECTIONNUMBER)

#define SECTIONADDRESS  SECTION1ADDRESS

#elif(23 == SECTIONNUMBER)

#define SECTIONADDRESS  SECTION23ADDRESS

#else
#define SECTIONADDRESS  NULL

#endif

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

/**
 * brief  its a function to setup the parralism of the flashing and erasing
 * param   void
 * retval  void
 */

void EEpromEmulation_init();



/**
 * brief its a function emulates the eeprom in flash so it  saves variables in a bank
 * note	 there is 2 ideas 1.. to erase then write
 * 						  2.. to check if it's written if so write in the next and so on till you reach some threshold
 * param   data to write
 * retval  returnState OK or NOK
 */

returnState EEpromEmulation_write_variable1(uint32 data, uint32 *addr);
returnState EEpromEmulation_write_variable2(uint32 data);

/**
 * brief its a function emulates the eeprom in flash so it  Erase bank to write in it again
 * note
 * param   bank Address to erase
 * retval  returnState OK or NOK
 */

returnState EEpromEmulation_Erase_Sector(uint32 sector_num);

/**
 * brief its a function emulates the eeprom in flash so it  reads variables in a bank
 * note
 * param   Address of data we want to read
 * retval  data that you read from flash
 */

uint32 EEpromEmulation_read_variable1(uint32 *addr);

/**
 * brief its a function emulates the eeprom in flash so it  reads variables in a bank
 * note
 * param   Address of data we want to read , address where we want to save the data
 * retval  returnState OK or NOK
 */

uint32 EEpromEmulation_read_variable2(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /* INC_EEPROM_EMULATION_H_ */
