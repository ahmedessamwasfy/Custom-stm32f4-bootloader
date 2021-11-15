/*
 * DMA_Implement.h
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_DMA_IMPLEMENT_H_
#define INC_DMA_IMPLEMENT_H_

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
#include"Std_Types.h"
#include"DMA_Reg.h"
#include"DMA_Cfg.h"

/* Inclusion of system and local header files goes here */



/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */



/* ============================ DEfines ================= */

/* 	Interrupt Error MAsks				 */

#define	HALF_TRANSFERE_INTERRUPT		0x01

#define	TRANSFERE_COMPLETE_INTERRUPT	0x02

#define	TRANSFERE_ERROR_INTERRUPT		0x04

#define	FIFO_OVERRUN_INTERRUPT			0x08

#define	DIRECR_MODE_ERROR_INTERRUPT		0x10




/* ==================================================================== */
/* ============================ Pointer to ISR Functions ================= */
/* ==================================================================== */



void(*DMA2_Interrupt_HalfTransfere_ISR_Callback_PTR)(void) ;

void(*DMA2_Interrupt_TranseferComplete_ISR_Callback_PTR)(void) ;

void(*DMA2_Interrupt_TransfereError_ISR_Callback_PTR)(void) ;

void(*DMA2_Interrupt_FifoOverrun_ISR_Callback_PTR)(void) ;

void(*DMA2_Interrupt_DirectModeError_ISR_Callback_PTR)(void) ;







/* ==================================================================== */
/* ============================ DMA 2 ================================= */
/* ==================================================================== */

/* ============================ STREAM 0 ================================= */

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Init(void);

/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_0_Set_Addresses_M2M(const uint32 * src,
    uint32 * dst, const uint32 size);

/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Enable();



/**
 * @brief   DMA2 Stream0 Change Channel function
 * @note    Used to change the channel
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Change_Channel(void);


/* #define and enum statements go here */








/* ============================ STREAM 5 ================================= */




void DMA2_General_INIT(uint8 DMA_stream_selected);

void DMA2_Stream5_INIT(void);

void DMA2_Transefere_direction_set(uint8 DMA_stream_selected, uint8 DMA_Transfere_direction_selected);

void DMA2_Channel_Set(uint8 DMA_stream_selected,uint16 DMA_Channel_selected);

void DMA2_Address_Set(uint8 DMA_stream_selected,const uint32 * DMA_prepherial_address,const uint32 * DMA_memory_address);

void DMA2_Memory2Memory_Address_Set(uint8 DMA_stream_selected,const uint32 * DMA_memory_0_address,const uint32 * DMA_memory_1_address);

void DMA2_Item_Number_Set(uint8 DMA_stream_selected,uint16 DMA_number_of_items);

void DMA2_Priority_Set(uint8 DMA_stream_selected,uint8 DMA_Priority_selected);

void DMA2_Data_Size_Set(uint8 DMA_stream_selected,uint8 DMA_Memory_size,uint8 DMA_Peripherial_size);

void DMA2_Enable(uint8 DMA_stream_selected);

void DMA2_Disable(uint8 DMA_stream_selected);

void DMA2_Transefere_Mode_set(uint8 DMA_stream_selected, uint8 DMA_Transfere_Mode_selected);

void DMA2_Circular_Mode_Enable(uint8 DMA_stream_selected);

void DMA2_Double_Buffer_Mode_Enable(uint8 DMA_stream_selected,uint8 DMA_started_memory);

void DMA2_Interrupt_Mask_Set(uint8 DMA_stream_selected,uint8 DMA_Interrupt_Mask);


uint8 DMA2_Interrupt_Status_Raw_Check(uint8 DMA_stream_selected);

uint8 DMA2_Interrupt_Status_Check(uint8 DMA_stream_selected,uint8 DMA_Interrupt_Mask);

void DMA2_FIFO_Control(uint8 DMA_stream_selected,uint8 DMA_FIFO_Threshold_Selected);

uint8 DMA2_FIFO_Status_Check(uint8 DMA_stream_selected);

void DMA2_Incrementation_Control(uint8 DMA_stream_selected,uint8 DMA_Perepherial_Increment_Mode_Selected,uint8 DMA_Perepherial_Increment_Offset_size_selected ,uint8 DMA_Memory_Increment_Mode_Selected);

void DMA2_Interrupt_HalfTransfere_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void) );

void DMA2_Interrupt_TranseferComplete_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  );

void DMA2_Interrupt_TransfereError_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  );

void DMA2_Interrupt_FifoOverrun_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  );

void DMA2_Interrupt_DirectModeError_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  );


void DMA2_Interruptr_ISR(void );



		/**	Future Function	**/
void DMA2_Brust_Mode(void);
void DMA2_Hardware_Flow_Mode(void);

























/* ============================ STREAM 7 ================================= */

/**
 * @brief   DMA2 Stream7 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_7_Init(void);

/**
 * @brief   DMA2 Stream7 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_7_Set_Addresses(const uint32 * src,
    uint32 * dst, const uint32 size);

/**
 * @brief   DMA2 Stream7 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_7_Enable();

/**
 * @brief   DMA2 Stream5 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_5_Enable();


/**
 * @brief   DMA2 Stream7 Change Channel function
 * @note    Used to change the channel
 * @param   None
 * @retval  None
 */
void DMA2_Stream_7_Change_Channel(void);


/* #define and enum statements go here */



/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */

/* Global variables definitions go here */



/* ==================================================================== */
/* ============================== data ================================ */
/* ==================================================================== */

/* Definition of datatypes go here */



/* ==================================================================== */
/* ==================== function prototypes =========================== */
/* ==================================================================== */

/* Function prototypes for public (external) functions go here */


/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	

#endif /* INC_DMA_IMPLEMENT_H_ */
