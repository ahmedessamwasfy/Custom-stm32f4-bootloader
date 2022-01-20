/*******************************************************************************
 * @file    Flash_Hal.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Jul 6, 2021
 *
 * @brief   Flash_Hal.c example using ST virtual COM port (VCP)
 * @note
 *
 @verbatim
 Copyright (C) Ahnmed Wasfy 2021

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
#include "Flash_Hal.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup Flash_Hal.c
 * @brief
 * @{
 */

/**
 * @defgroup Flash_Hal.c_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_defines
 * @{
 */
#define IMAGES_NO 4

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_constants
 * @{
 */

/**
 * @brief   USART1 messages to be transmitted
 */
static char hello[] = "Welcome to Flash Controller !";
static char select_cmd[] = "Select command from the following: ";
static char Lock[] = "1: Flash Lock";
static char unlock[] = "2: Flash Unlock";
static char write_data[] = "3: Write Data";
static char read_data[] = "4: Read Data";
static char erase[] = "5: Sector Erase";
static char write_protect[] = "6: Write Protection";
static char remove_write_protect[] = "7: Remove Write Protection";
static char ob_unlock[] = "8: Option Bytes Unlock";
static char ob_lock[] = "9: Option Bytes Lock";
static char jump[] = "10: Direct Jump";
static char line[] = "**********************************************";

static char error_PGSERR[] = "Programming sequence error";
static char error_PGPERR[] = "Programming parallelism error";
static char error_PGAERR[] = "Programming alignment error";
static char error_WRPERR[] = "Write protection error";

static char ACK[] = "ACK";
static char NACK[] = "NACK";
/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_variables
 * @{
 */

extern uint32_t _Image_0_Flash_Origin;
extern uint32_t _Image_1_Flash_Origin;
extern uint32_t _Image_2_Flash_Origin;

static uint32_t gImagesOrigin[IMAGES_NO] = { (uint32_t) &_Image_0_Flash_Origin,
		(uint32_t) &_Image_1_Flash_Origin, (uint32_t) &_Image_2_Flash_Origin, };
/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_function_prototypes
 * @{
 */

/**
 * @brief   Check flash errors
 * @param   none
 * @retval  none
 */
static void check_errors();

/**
 * @brief   Process flash command
 * @param   none
 * @retval  none
 */
static void process_command();

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup Flash_Hal.c_exported_functions
 * @{
 */

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_GPIO_Config(void) {
	myUSART1_GPIO_Config();
}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_Init(void) {
	// myUSART1_Init();

	/* Configure USART1 */
	/* Enable USART1 clock */
	RCC->APB2ENR = RCC_APB2ENR_USART1EN;

	/* Set baud rate = 115200 Bps
	 * USARTDIV = Fck / (16 * baud_rate)
	 *          = 90000000 / (16 * 115200) = 48.82
	 *
	 * DIV_Fraction = 16 * 0.82 = 13.12 = 13 = 0xD
	 * DIV_Mantissa = 48 = 0x30
	 *
	 * BRR          = 0x30D */
	USART1->BRR = 0x30D;

}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_TX_DMA_Config(void) {
	USART1_TX_DMA_Config();

}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_RX_DMA_Config(void) {
	//USART1_RX_DMA_Config();

	/* Enable DMA clock in RCC */
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	/* Make sure that the DMA2 stream 5 is disabled */
	if (DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream5->CR)) {
		/* DMA 2 stream 5 is enabled, shall be disabled first */
		DMA2_Stream5->CR &= ~DMA_SxCR_EN;

		/* Wait until EN bit is cleared */
		while (DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream5->CR)) {
			/* Do nothing until EN bit is cleared */
		}
	} else {
		/* Do nothing, stream 5 is not enabled */
	}

	/* Select the DMA channel 4 in CHSEL[2:0] in the DMA_SxCR */
	DMA2_Stream5->CR &= ~DMA_SxCR_CHSEL;
	DMA2_Stream5->CR |= DMA_SxCR_CHSEL_2;

	/* Select stream priority very high */
	DMA2_Stream5->CR |= DMA_SxCR_PL;

	/* Select the data transfer direction peripheral-to-memory */
	DMA2_Stream5->CR &= ~DMA_SxCR_DIR;

	/* Select memory and peripherals sizes byte (8-bit) */
	DMA2_Stream5->CR &= ~DMA_SxCR_MSIZE;
	DMA2_Stream5->CR &= ~DMA_SxCR_PSIZE;

	/* Select FIFO mode */
	DMA2_Stream5->FCR |= DMA_SxFCR_DMDIS;

	/* Select FIFO threshold level half FIFO */
	DMA2_Stream5->FCR |= (DMA_SxFCR_FTH_0 | DMA_SxFCR_FTH_1);

	/* Select memory incremented mode, peripheral shall has fixed address */
	DMA2_Stream5->CR |= DMA_SxCR_MINC;

	/* Enable DMA transfer complete interrupt */
	DMA2_Stream5->CR |= DMA_SxCR_TCIE;

	/* Set peripheral address */
	DMA2_Stream5->PAR = (uint32_t) &USART1->DR;

	/* Set memory address */
	DMA2_Stream5->M0AR = (uint32_t) FlashRxDMABuffer;

	/* Set number of data items */
	DMA2_Stream5->NDTR = MAX_BUFFER_LENGTH;
}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_USART1_Enable(void) {
	myUSART1_Enable();
}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_Init(void) {

	/* Write KEY1 */
	FLASH->KEYR = 0x45670123;

	/* Write KEY2 */
	FLASH->KEYR = 0xCDEF89AB;

	/* Select flash parallelism x32 */
	FLASH->CR &= ~FLASH_CR_PSIZE;
	FLASH->CR |= FLASH_CR_PSIZE_1;

	/* Write lock bit */
	FLASH->CR |= FLASH_CR_LOCK;

}

/**
 * @brief
 * @note
 * @param   void
 * @retval  void
 */
void Flash_Main(void) {
	switch (Flash_currentState) {

	case FLASH_IDLE:
		/* Transmit data */
		strTransmit_with_DMA(line, sizeof(line));
		strTransmit_with_DMA(hello, sizeof(hello));
		strTransmit_with_DMA(select_cmd, sizeof(select_cmd));
		strTransmit_with_DMA(line, sizeof(line));
		strTransmit_with_DMA(Lock, sizeof(Lock));
		strTransmit_with_DMA(unlock, sizeof(unlock));
		strTransmit_with_DMA(write_data, sizeof(write_data));
		strTransmit_with_DMA(read_data, sizeof(read_data));
		strTransmit_with_DMA(erase, sizeof(erase));
		strTransmit_with_DMA(write_protect, sizeof(write_protect));
		strTransmit_with_DMA(remove_write_protect,
				sizeof(remove_write_protect));
		strTransmit_with_DMA(ob_unlock, sizeof(ob_unlock));
		strTransmit_with_DMA(ob_lock, sizeof(ob_lock));
		strTransmit_with_DMA(jump, sizeof(jump));
		strTransmit_with_DMA(line, sizeof(line));
		/* Go to next state */
		Flash_currentState = FLASH_WAIT_FOR_CMD;
		break;

	case FLASH_WAIT_FOR_CMD:
		/* Check if new message received */
		if (0 != FlashRxMessageLength) {
			/* Process command */
			process_command();

			/* Check errors */
			check_errors();

			/* Reset message length */
			FlashRxMessageLength = 0;
		} else {
			/* Nothing received yet */
		}

		/* Go to next state */
		Flash_currentState = FLASH_WAIT_FOR_CMD;
		break;

	default:
		break;

	}

}

void FLASH_USART1_IRQ_Callback(void) {
	/* Check if idle line detected */
	if ((USART1->SR & USART_SR_IDLE) == USART_SR_IDLE) {
		/* Read data register to clear idle line flag */
		(void) USART1->DR;

		/* Disable DMA stream for RX */
		DMA2_Stream5->CR &= ~DMA_SxCR_EN;
	} else {
		/* No new data received */
	}

}

void FLASH_USART1_TX_DMA_IRQ_Callback(void) {
	/* Check transfer complete flag */
	if (DMA_HISR_TCIF7 == (DMA_HISR_TCIF7 & DMA2->HISR)) {
		/* Clear all interrupt flags */
		DMA2->HIFCR = (DMA_HIFCR_CFEIF7 | DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CTEIF7
				| DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTCIF7);
	} else {
		/* Do nothing, this interrupt is not handled */
	}

}

void FLASH_USART1_RX_DMA_IRQ_Callback(void) {
	/* Check transfer complete flag */
	if (DMA_HISR_TCIF5 == (DMA_HISR_TCIF5 & DMA2->HISR)) {
		/* Calculate amount of data received */
		FlashRxMessageLength = MAX_BUFFER_LENGTH - DMA2_Stream5->NDTR;

		for (int index = 0; index < FlashRxMessageLength; index++) {
			FlashRxBuffer[index] = FlashRxDMABuffer[index];
		}
		/* Clear all interrupt flags */
		DMA2->HIFCR = (DMA_HIFCR_CFEIF5 | DMA_HIFCR_CDMEIF5 | DMA_HIFCR_CTEIF5
				| DMA_HIFCR_CHTIF5 | DMA_HIFCR_CTCIF5);

		/* Enable DMA 2 stream 5 */
		DMA2_Stream5->CR |= DMA_SxCR_EN;
	} else {
		/* Do nothing, this interrupt is not handled */

	}

}

void FLASH_IRQ_Callback(void) {

}

/**
 * @brief   Check flash errors
 * @param   none
 * @retval  none
 */
static void check_errors() {

	if (FLASH_SR_PGSERR == (FLASH->SR & FLASH_SR_PGSERR)) {
		/* Programming sequence error */
		strTransmit_with_DMA(NACK, sizeof(NACK));
		strTransmit_with_DMA(error_PGSERR, sizeof(error_PGSERR));
		strTransmit_with_DMA(line, sizeof(line));

		/* Clear */
		FLASH->SR |= FLASH_SR_PGSERR;
	} else if (FLASH_SR_PGPERR == (FLASH->SR & FLASH_SR_PGPERR)) {
		/* Programming parallelism error */
		strTransmit_with_DMA(NACK, sizeof(NACK));
		strTransmit_with_DMA(error_PGPERR, sizeof(error_PGPERR));
		strTransmit_with_DMA(line, sizeof(line));

		/* Clear */
		FLASH->SR |= FLASH_SR_PGPERR;
	}

	else if (FLASH_SR_PGAERR == (FLASH->SR & FLASH_SR_PGAERR)) {
		/* Programming alignment error */
		strTransmit_with_DMA(NACK, sizeof(NACK));
		strTransmit_with_DMA(error_PGAERR, sizeof(error_PGAERR));
		strTransmit_with_DMA(line, sizeof(line));

		/* Clear */
		FLASH->SR |= FLASH_SR_PGAERR;
	}

	else if (FLASH_SR_WRPERR == (FLASH->SR & FLASH_SR_WRPERR)) {
		/* Write protection error */
		strTransmit_with_DMA(NACK, sizeof(NACK));
		strTransmit_with_DMA(error_WRPERR, sizeof(error_WRPERR));
		strTransmit_with_DMA(line, sizeof(line));

		/* Clear */
		FLASH->SR |= FLASH_SR_WRPERR;
	} else {
		/* No Error */
		strTransmit_with_DMA(ACK, sizeof(ACK));

	}
}

/**
 * @brief   Process flash command
 * @param   none
 * @retval  none
 */
static void process_command() {

	u32 command_address = 0;
	u32 command_data = 0;
	u32 command_result = 0;
	u32 sector_num = 0;
	/* Process received command */
	switch (FlashRxBuffer[0]) {
	case 1: /*flash lock*/
		/* Write lock bit */
		FLASH->CR |= FLASH_CR_LOCK;

		break;
	case 2: /*flash Unlock*/

		/* Write KEY1 */
		FLASH->KEYR = 0x45670123;

		/* Write KEY2 */
		FLASH->KEYR = 0xCDEF89AB;

		break;
	case 3: /*Write Data*/
		/*example 0x081E0000 put 41 48 4d 45    * 03 00 00 1E 08  41 48 4d 45 *  */
		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}

		/* Enable flash programming */
		FLASH->CR |= FLASH_CR_PG;

		/* Write data into flash */
		command_address = *(u32*) &FlashRxBuffer[1]; // bygeeb awl el address(value in RxBuffre[1]) w ba3den bygeed el address bta3o w ba3den by3mlo cast L 32 34an ya5do kolo ba3d kda by3mlo derefrence 34an ygeb kol el address)
//		        command_data = *(u32*) & FlashRxBuffer[5];

		for (u8 idx = 0; idx < 4; ++idx) {

			command_data = *(u32*) &FlashRxBuffer[5 + (idx * 4)];

			*((volatile uint32_t*) (command_address) + idx) = command_data;

			while (0 != (FLASH->SR & FLASH_SR_BSY)) {
				/* Waiting */
			}

		}

		/* Disable flash programming */
		FLASH->CR &= ~FLASH_CR_PG;

		break;

		break;
	case 4: /*Read Data*/
		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}
		/*example 0x081E0000      * 04 00 00 1E 08 *  note we use little endian so   last byte will be the first to reead    */

		command_address = *(u32*) &FlashRxBuffer[1];
		command_result = *(u32*) command_address;
		strTransmit_with_DMA((char*) &command_result, sizeof(command_result));

		break;
	case 5: /*Sector Erase*/
		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}
		/* example erase sector 17	 		* 5 17 *    */
		/* Enable flash Sector Erase */
		FLASH->CR |= FLASH_CR_SER;

		/* Select sector to erase */
		/* Check sector number for bank 2 */
		sector_num = FlashRxBuffer[1];
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
		break;
		break;
	case 6: /*Write Protection*/
		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}

		/* Check sector number */
		sector_num = FlashRxBuffer[1];
		if (12 <= sector_num) {
			/* Bank 2 */
			sector_num = sector_num - 12;
			FLASH->OPTCR1 &= ~((1 << sector_num) << 16);
		} else {
			/* Bank 2 */
			FLASH->OPTCR &= ~((1 << sector_num) << 16);
		}

		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;

		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}
		break;
	case 7: /*Remove write protection*/
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {

			/* Waiting */
		}

		sector_num = FlashRxBuffer[1];
		if (12 <= sector_num) {
			/* Bank 2 */
			sector_num = sector_num - 12;
			FLASH->OPTCR1 |= ((1 << sector_num) << 16);
		} else {
			/* Bank 2 */
			FLASH->OPTCR |= ((1 << sector_num) << 16);
		}

		/* Start sector write protection */
		FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;

		/* Wait bsy flag */
		while (0 != (FLASH->SR & FLASH_SR_BSY)) {
			/* Waiting */
		}

		break;
	case 8: /* Option Bytes Unlock */
		/* Write OPTKEY1 */
		FLASH->OPTKEYR = 0x08192A3B;

		/* Write OPTKEY2 */
		FLASH->OPTKEYR = 0x4C5D6E7F;

		break;
	case 9:/* Option Bytes Lock */
		/* Write lock bit */
		FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;

		break;

	case 10: /* Jump */
		/* get jump address */
		command_address = *(u32*) &FlashRxBuffer[1];
		command_data = *(u32*) command_address;/* the stack pointer*/

		strTransmit_with_DMA((char*) command_data, sizeof(NACK));
		strTransmit_with_DMA((char*) command_address, sizeof(NACK));

		/*check if it's a valid stack pointer in Ram*/
		if ((command_data & 0x20000000) == 0x20000000) {

			/*Disable interrupts*/
			__disable_irq();

			/*Reset Gpio and DMA*/
			RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOARST | RCC_AHB1RSTR_DMA2RST);

			/* Release reset */
			RCC->AHB1RSTR = 0;

			/* Reset USART1 */
			RCC->APB2RSTR = RCC_APB2RSTR_USART1RST;

			/* Release reset */
			RCC->APB2RSTR = 0;

			/* Reset RCC */
			/* Set HSION bit to the reset value */
			RCC->CR |= RCC_CR_HSION;

			/*wait till HSI is ready*/
			while ((RCC_CR_HSIRDY) != ((RCC->CR) & RCC_CR_HSIRDY)) {

				/*Waiting*/

			}

			/* Set HSITRIM[4:0] bits to the reset value */
			RCC->CR |= RCC_CR_HSITRIM_4;

			/* Reset CFGR register */
			RCC->CFGR = 0;

			/* Wait till clock switch is ready and
			 * HSI oscillator selected as system clock */
			while (0 != (RCC_CFGR_SWS & RCC->CFGR)) {
				/* Waiting */
			}

			/* Clear HSEON, HSEBYP and CSSON bits */
			RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP | RCC_CR_CSSON);

			/* Wait till HSE is disabled */
			while (0 != (RCC_CR_HSERDY & RCC->CR)) {
				/* Waiting */
			}

			/* Clear PLLON bit */
			RCC->CR &= ~RCC_CR_PLLON;

			/* Wait till PLL is disabled */
			while (0 != (RCC_CR_PLLRDY & RCC->CR)) {
				/* Waiting */
			}
			/*STM32F429*/
			/* Reset PLLCFGR register to default value */
			RCC->PLLCFGR = RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLN_6
					| RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLQ_2;

			RCC->PLLI2SCFGR = 0x24003000;

			RCC->PLLSAICFGR = 0x24003000;
			/*Disable all interrupt*/
			RCC->CIR = 0x00;

			/* Clear LSION bit */
			RCC->CSR &= ~RCC_CSR_LSION;

			/* Reset all CSR flags */
			RCC->CSR &= ~RCC_CSR_RMVF;

			/* Update the SystemCoreClock global variable */
			SystemCoreClock = HSI_VALUE;

			/* Reset SysTick */
			SysTick->CTRL = 0;
			SysTick->LOAD = 0;
			SysTick->VAL = 0;
			/* Check Jump address */
			if (0x1FFF0000 == command_address) /* if want to  jump to system bootloader */
			{

			} else /* if  want to jump to some image in flash*/
			{
				/* Vector Table Relocation in Internal FLASH */
				__DMB();
				SCB->VTOR = command_address;
				__DSB();
			}

			/**/
			void (*jump_address)(
					void)=(void *)(*((uint32_t *)(command_address + 4)));
			/* Set stack pointer */
			__set_MSP(command_data);

			/* Jump */
			jump_address();

		} else {
			/*Send NACK*/
			strTransmit_with_DMA(NACK, sizeof(NACK));
		}
		break;
	case 11: /* update eeprom with new image */
			command_address = *(u32*) &FlashRxBuffer[1];
			command_data = *(u32*) command_address;/* the stack pointer*/
			/* use eeprom emulation through flash to write the new version */
			EEpromEmulation_write_variable2(command_data);
		break;
	default:
		break;

	}

}

/**
 * @brief used to check the if the first image is available
 * @note
 * @param   void
 * @retval  OK if stack pointer is correct NOT_OK if stack pointer is invalid
 */
u8 Main_IMG_Available() {
	u8 result = NOT_OK;

	u32 Img_address = 0x080E0000;
	u32 address = *(u32*) &Img_address;
	u32 data = *(u32*) address;/* the stack pointer*/

	if ((data & 0x20000000) == 0x20000000)
		result = OK;

	return result;
}

/**
 * @brief used to check if the second image is available
 * @note
 * @param   void
 * @retval  OK if stack pointer is correct NOT_OK if stack pointer is invalid
 */
u8 Secondary_IMG_Available() {
	u8 result = NOT_OK;

	u32 Img_address = 0x081E0000;
	u32 address = *(u32*) &Img_address;
	u32 data = *(u32*) address;/* the stack pointer*/
	if ((data & 0x20000000) == 0x20000000)
		result = OK;

	return result;
}

/*
 * jump function
 *  args vector table adress
 *
 * process to jump to primary or secondry app image
 *
 * */

/**
 * @brief
 * @note
 * @param   void
 * @retval  uint32_t the image to be loaded
 */
void Jump_To_APP(uint32_t image) {

	ImgHeader_t *ImagHeader;
	uint32_t image_origin;


	u32 crcvalid = 0;

	switch (image) {
	case 1:
		image_origin = (uint32_t) &_Image_0_Flash_Origin;
		break;
	case 2:
		image_origin = (uint32_t) &_Image_1_Flash_Origin;
		break;
	case 3:
		image_origin = (uint32_t) &_Image_2_Flash_Origin;
		break;
	}

	ImagHeader = (ImgHeader_t*) image_origin;

	crcvalid = CRC_validation(image_origin);
	if (!crcvalid) {
		/* CHANGE THE ACTIVE VERSION */
		Change_Active_Image(image);
		while (1)
			;
	}
	/*check if it's a valid stack pointer in Ram*/
	if (((*((uint32_t*) ImagHeader->ImageStartAddr))
			& (((uint32_t) ImagHeader->StackPointer)))
			== (((uint32_t) ImagHeader->StackPointer))) {

		/*Disable interrupts*/
		__disable_irq();

		/*Reset Gpio and DMA*/
		RCC->AHB1RSTR |= (RCC_AHB1RSTR_GPIOARST | RCC_AHB1RSTR_DMA2RST);

		/* Release reset */
		RCC->AHB1RSTR = 0;

		/* Reset USART1 */
		RCC->APB2RSTR = RCC_APB2RSTR_USART1RST;

		/* Release reset */
		RCC->APB2RSTR = 0;

		/* Reset RCC */
		/* Set HSION bit to the reset value */
		RCC->CR |= RCC_CR_HSION;

		/*wait till HSI is ready*/
		while ((RCC_CR_HSIRDY) != ((RCC->CR) & RCC_CR_HSIRDY)) {

			/*Waiting*/

		}

		/* Set HSITRIM[4:0] bits to the reset value */
		RCC->CR |= RCC_CR_HSITRIM_4;

		/* Reset CFGR register */
		RCC->CFGR = 0;

		/* Wait till clock switch is ready and
		 * HSI oscillator selected as system clock */
		while (0 != (RCC_CFGR_SWS & RCC->CFGR)) {
			/* Waiting */
		}

		/* Clear HSEON, HSEBYP and CSSON bits */
		RCC->CR &= ~(RCC_CR_HSEON | RCC_CR_HSEBYP | RCC_CR_CSSON);

		/* Wait till HSE is disabled */
		while (0 != (RCC_CR_HSERDY & RCC->CR)) {
			/* Waiting */
		}

		/* Clear PLLON bit */
		RCC->CR &= ~RCC_CR_PLLON;

		/* Wait till PLL is disabled */
		while (0 != (RCC_CR_PLLRDY & RCC->CR)) {
			/* Waiting */
		}
		/*STM32F429*/
		/* Reset PLLCFGR register to default value */
		RCC->PLLCFGR = RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLN_6
				| RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLQ_2;

		RCC->PLLI2SCFGR = 0x24003000;

		RCC->PLLSAICFGR = 0x24003000;
		/*Disable all interrupt*/
		RCC->CIR = 0x00;

		/* Clear LSION bit */
		RCC->CSR &= ~RCC_CSR_LSION;

		/* Reset all CSR flags */
		RCC->CSR &= ~RCC_CSR_RMVF;

		/* Update the SystemCoreClock global variable */
		SystemCoreClock = HSI_VALUE;

		/* Reset SysTick */
		SysTick->CTRL = 0;
		SysTick->LOAD = 0;
		SysTick->VAL = 0;

		/* Check Jump address */

		/* Vector Table Relocation in Internal FLASH */
		__DMB();
		SCB->VTOR = ImagHeader->VectorTableAddr;
		__DSB();

		/**/
		void (*jump_main2)(
				void)=(void *)(*((uint32_t *)(ImagHeader->EntryPointAddr)));
		/* Set stack pointer */
		__set_MSP((*((uint32_t*) ImagHeader->StackPointer)));

		/* Jump */
		jump_main2();

	}

}

/**
 * @brief
 * @note
 * @param   uint32_t is the image is valid
 * @retval  uint32_t the image to be valdated
 */
uint32_t CRC_validation(uint32_t image_origin) {

	crc_t crc;

	u32 result = 0;

	ImgHeader_t *ImagHeader = (ImgHeader_t*) image_origin;

	uint32_t imageCRCpassed = ImagHeader->CRC32;

	//ImagHeader=(ImgHeader_t*) gImagesOrigin[image];
	/* the flash we need to crc check */
	volatile uint32_t *Flash_used;

	//		Flash_used=((uint32_t *)(0x8000250));
	/* the start of the checked crc calculations after the image header */
	Flash_used = ((uint32_t*) (ImagHeader + ImagHeader->ImageHeaderOffset));

	uint32_t imageLength = (uint32_t) ((ImagHeader->ImageEnd)
			- ImagHeader->ImageCRCStart);

	/*initialize the crc library*/
	crc = crc_init();

	//crc=crc_update(crc,Flash_used,0x7f0);
	/* calculate the new crc */
	crc = crc_update(crc, Flash_used, imageLength);

	if (crc == imageCRCpassed)
		result = 1;

	return result;
}

uint32_t Change_Active_Image(uint32_t currentActiveImage) {
	uint32_t newActiveImage = 0;
	uint32_t image_origin = 0;
	uint8_t terminate = 0, i = 0;

	while (terminate == 0 && i < 3) {

		switch (currentActiveImage) {
		case 1:
			currentActiveImage = 3;
			image_origin = _Image_2_Flash_Origin;
			break;
		case 2:
			currentActiveImage = 1;
			image_origin = _Image_0_Flash_Origin;
			break;
		case 3:
			currentActiveImage = 2;
			image_origin = _Image_1_Flash_Origin;
			break;
		}
		if ((*(uint32_t*) image_origin) == 0x20000000) {
			terminate = 1;
		}
		i++;
	}

	newActiveImage = currentActiveImage;
	EEpromEmulation_write_variable2(newActiveImage);

	return newActiveImage;
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
