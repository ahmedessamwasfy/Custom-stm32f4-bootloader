/********************************************************************
 **
 **
 ** file    		EEprom_Emulation.c
 ** author  		Ahmed Wasfy
 ** email   		ahmedessam0128@gmail.com
 ** date    		Dec 29, 2021
 ** Target  		STM32F4291-discoveryboard
 ** Version     	1.0.0
 **
 ** brief   		EEprom_Emulation.c
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

#include "EEprom_Emulation.h"

/* ==================================================================== */
/* ======================== Macros and Defines ======================== */
/* ==================================================================== */

/* #define and enum statements and macros go here */

/**
 * brief Max number of elements that can be write before erasing
 */
#define MAX_INDEX_WRITE		(uint32)10

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

volatile uint32 CurrentIndexWrite;

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
 * brief  its a function to setup the parralism of the flashing and erasing
 * param   void
 * retval  void
 */

void EEpromEmulation_init(){
	  /* Write KEY1 */
	  FLASH->KEYR = 0x45670123;

	  /* Write KEY2 */
	  FLASH->KEYR = 0xCDEF89AB;

	  /* Select flash parallelism x32 */
	  FLASH->CR &= ~FLASH_CR_PSIZE;
	  FLASH->CR |= FLASH_CR_PSIZE_1;

	  /* Enable End of operation Interrupt */
	 // FLASH->CR |= FLASH_CR_EOPIE;

	  /* Enable Error Interrupt */
	 // FLASH->CR |= FLASH_CR_ERIE;

	  /* Write lock bit */
	  FLASH->CR |= FLASH_CR_LOCK;


}





/**
 * brief its a function emulates the eeprom in flash so it  saves variables in a bank
 * note	 there is 2 ideas 1.. to erase then write
 * 						  2.. to check if it's written if so write in the next and so on till you reach some threshold
 * param   data to write
 * retval  returnState OK or NOK
 */

returnState EEpromEmulation_write_variable1(uint32 data, uint32 *addr) {

	/*Check the parameters*/
//	ASSERT_param(addr!=NULL);
//	ASSERT_param(data!=NULL);

	/* unlock the Addressed section */

	returnState ReturnState = E_NOK;

	return ReturnState;

}
returnState EEpromEmulation_write_variable2(uint32 data) {
	/*Check the parameters*/
//	ASSERT_param(addr!=NULL);
	//ASSERT_param(data!=NULL);

	returnState ReturnState = E_NOK;

	uint8 terminate = 0;

	volatile uint32  sectionAddress = SECTIONADDRESS;

	uint32 result = 0;

	/*Unlock the Flash for writing*/
	/* Write KEY1 */
	FLASH->KEYR = 0x45670123;
	/* Write KEY2 */
	FLASH->KEYR = 0xCDEF89AB;

	/* Start writing  */
	while (terminate == 0) {

		if (CurrentIndexWrite >= 10) {
			/*Erase protocol*/
			EEpromEmulation_Erase_Sector(SECTIONNUMBER);
			CurrentIndexWrite = 0;
		}

		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}
		/* read the current indexed address */
		result = *((uint32 *)sectionAddress + CurrentIndexWrite);

		/* check if it is Free address to write */
		if (result == (0xFFFFFFFF)) {

			while (0 != (FLASH->SR & FLASH_SR_BSY)) {
				/* Waiting */
			}

			/* Enable flash programming */
			FLASH->CR |= FLASH_CR_PG;


			/* write the data in the address */
			MEM32_ADDRESS(sectionAddress + (CurrentIndexWrite*4)) = data;


			while (0 != (FLASH->SR & FLASH_SR_BSY)) {
				/* Waiting */
			}
			/* Disable flash programming */
			FLASH->CR &= ~FLASH_CR_PG;

			/* increment the Index of writing for the next writing request */
			CurrentIndexWrite++;
			terminate = 1;
			ReturnState = E_OK;
		}

		else {
			/* look for the next address */
			CurrentIndexWrite++;

		}

	}

	/* Write lock bit */
	FLASH->CR |= FLASH_CR_LOCK;

	return ReturnState;
}

/**
 * brief its a function emulates the eeprom in flash so it  Erase bank to write in it again
 * note
 * param   bank Address to erase
 * retval  returnState OK or NOK
 */

returnState EEpromEmulation_Erase_Sector(uint32 sector_num) {
	/*Check the parameters*/
	//ASSERT_param(sector_num!=NULL);

	returnState ReturnState = E_NOK;

	uint32 result=0;


	/* Write lock bit */
	FLASH->CR |= FLASH_CR_LOCK;

	/*Unlock the Flash for writing*/
	/* Write KEY1 */
	FLASH->KEYR = 0x45670123;
	/* Write KEY2 */
	FLASH->KEYR = 0xCDEF89AB;

	/* Wait bsy flag */
	while (0 != (FLASH->SR & FLASH_SR_BSY)) {
		/* Waiting */
	}


    /* Enable flash Sector Erase */
    FLASH->CR |= FLASH_CR_SER;

	/* Select sector to erase */
	/* Check sector number for bank 2 */
	if (12 <= sector_num) {
		/* Bank 2 */
		sector_num = sector_num + 4;
	} else {

	}

	/* Write sector number */
	FLASH->CR |= (FLASH_CR_SNB & (sector_num << 3));

	/* Start sector erase */
	FLASH->CR |= FLASH_CR_STRT;

	/* Wait bsy flag */
	while (0 != (FLASH->SR & FLASH_SR_BSY)) {
		/* Waiting */
	}

	/* Disable sector erase */
	FLASH->CR &= ~FLASH_CR_SER;

	CurrentIndexWrite=0;

	/* read the current indexed address */
	result = *(SECTIONADDRESS);

	/*Check if its really erased*/
	if(result==0xFFFFFFFF) {

		/*Return OK*/
		ReturnState=E_OK;
	}



	return ReturnState;
}

/**
 * brief its a function emulates the eeprom in flash so it  reads variables in a bank
 * note
 * param   Address of data we want to read
 * retval  data that you read from flash
 */

uint32 EEpromEmulation_read_variable1(uint32 *addr) {
	/*Check the parameters*/
	ASSERT_param(addr!=NULL);

	returnState ReturnState = E_NOK;

	return 0;
}

/**
 * brief its a function emulates the eeprom in flash so it  reads variables in a bank
 * note
 * param   Address of data we want to read , address where we want to save the data
 * retval  returnState OK or NOK
 */

uint32 EEpromEmulation_read_variable2(void) {

	/*Check the parameters*/
	//ASSERT_param(SECTIONADDRESS!=NULL);
	volatile uint32  sectionAddress = SECTIONADDRESS;

	uint8 terrminator=0;
	uint32 result=0;
	uint32  tempResult=0;
	  	/* Wait bsy flag */
    while(0 != (FLASH->SR & FLASH_SR_BSY))
    {
      /* Waiting */
    }

    while(terrminator==0){


		if (CurrentIndexWrite >= 10) {
			/*Erase protocol*/
			EEpromEmulation_Erase_Sector(SECTIONNUMBER);
			CurrentIndexWrite = 0;
		}

    	/* read the current indexed address */
    	result = *((uint32 *)sectionAddress+(CurrentIndexWrite-1));
    	tempResult=*((uint32 *)sectionAddress+CurrentIndexWrite);
    	if(result==0xFFFFFFFF&&tempResult==0xFFFFFFFF){
    		/*its first iteration of the Bootloader overall
    		 * or we just erased then read so in both we will go to
    		 * bootloader to check if there is image or not */
    		result=0;
    		terrminator=1;
    		break;
    	}
    	/*Check if this is the last written data */
    	if(tempResult==(0xFFFFFFFF)){
    		/*this is the last written data*/
    		terrminator=1;
    		break;
    	}
    	CurrentIndexWrite++;
    }

    returnState ReturnState = E_NOK;

	return result;
}

