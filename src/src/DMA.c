/*
 * DMA.c
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#include"DMA_Implement.h"





/* ============================ STREAM 0  ================================= */


/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Init()
{
  /* Enable DMA clock in RCC */
	RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;


    /* DMA 2 stream 0 is enabled, shall be disabled first */
	DMA2_CR(7)&= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(7)))
    {
      /* Do nothing until EN bit is cleared */
    }


  /* Select the DMA channel CHSEL[2:0] in the DMA_SxCR.
   * (not needed when M->M). */
    DMA2_CR(7) |=DMA2_STREAM_0_Channel_Selection;

    /* Select Memmory brust */
    DMA2_CR(7)|=DMA2_STREAM_0_MBURST;

    /* Select perepheral brust */
    DMA2_CR(7)|=DMA2_STREAM_0_PBURST;


    /* Select Current target (only in double buffer mode)*/

	#if DMA2_STREAM_0_CT==TRUE
		DMA2_CR(7)|=DMA_SxCR_CT;
	#endif

	 /* Select DBM: Double buffer mode*/

	#if DMA2_STREAM_0_DBM==TRUE
		DMA2_CR(7)|=DMA_SxCR_DBM;
	#endif

  /* Select stream priority very high */
    DMA2_CR(7) |= DMA2_STREAM_0_PL;


   /* Select INCOS: Peripheral increment offset size*/

	#if DMA2_STREAM_0_PINCOS==TRUE
		DMA2_CR(7)|=DMA_SxCR_PINCOS;
	#endif

	/* Select memory and peripherals sizes */
	  DMA2_CR(7)  |= DMA2_STREAM_0_MSIZE;
	  DMA2_CR(7)  |= DMA2_STREAM_0_PSIZE;


	 /* Select  MINC: Memory increment mode*/

	#if DMA2_STREAM_0_MINC==TRUE
		DMA2_CR(7)|=DMA_SxCR_MINC;
	#endif

	/* Select  PINC: Peripheral increment mode*/

	#if DMA2_STREAM_0_PINC==TRUE
		DMA2_CR(7)|=DMA_SxCR_PINC;
	#endif


	/* Select  CIRC: Circular mode*/

	#if DMA2_STREAM_0_CIRC==TRUE
		DMA2_CR(7)|=DMA_SxCR_CIRC;
	#endif




  /* Select the data transfer direction memory to memory */
    DMA2_CR(7)  |= DMA2_STREAM_0_DIR;


    /* Select  PFCTRL: Peripheral flow controller*/

	#if DMA2_STREAM_0_PFCTRL==TRUE
		DMA2_CR(7)|=DMA_SxCR_PFCTRL;
	#endif



    /* Select TCIE: Transfer complete interrupt enable*/

	#if DMA2_STREAM_0_TCIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_TCIE;
	#endif



    /* Select   HTIE: Half transfer interrupt enable*/

	#if DMA2_STREAM_0_HTIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_HTIE;
	#endif


    /* Select  TEIE: Transfer error interrupt enable*/

	#if DMA2_STREAM_0_TEIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_TEIE;
	#endif



	/* Select  DMEIE: Direct mode error interrupt enable*/

	#if DMA2_STREAM_0_DMEIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_DMEIE;
	#endif



//# DMA_FCR			/*!< DMA stream x FIFO control register       */


		/* Select FEIE: FIFO error interrupt enable */

	DMA2_FCR(7) |= DMA2_STREAM_0_FIFO_Error_Interrupt_enable*DMA_SxFCR_FEIE;

  /* Select FIFO mode, it will be also set by hardware when stream enabled */
    DMA2_FCR(7) |= DMA2_STREAM_0_Direct_Mode_Disable*DMA_SxFCR_DMDIS;

  /* Select FIFO threshold level half FIFO */
    DMA2_FCR(7) |= DMA2_STREAM_0_FIFO_Threshold_Selection;



}



/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_0_Set_Addresses_M2M(const uint32 * src,
    uint32 * dst, const uint32 size)
{

  /* Set the source address to the peripheral port */
	DMA2_PAR(7)= (uint32)src;

  /* Set the destination address to the memory port */
	DMA2_M0AR(7)= (uint32)dst;

  /* Set number of data items */
	DMA2_NDTR(7) = size;
}


/**
 * @brief   DMA2 Stream0 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_0_Enable()
{
  /* Clear all interrupt flags */
	DMA2_LISR = (DMA_LIFCR_CFEIF0 | DMA_LIFCR_CDMEIF0 | DMA_LIFCR_CTEIF0
      | DMA_LIFCR_CHTIF0 | DMA_LIFCR_CTCIF0);

  /* Enable DMA 2 stream 0 */
	DMA2_CR(0) |= DMA_SxCR_EN;
}














/* ============================ STREAM 5 ================================= */








void DMA2_General_INIT(uint8 DMA_stream_selected){

	  /* Enable DMA clock in RCC */
		RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;


	    /* DMA 2 stream 0 is enabled, shall be disabled first */
		DMA2_CR(DMA_stream_selected)&= ~DMA_SxCR_EN;

	    /* Wait until EN bit is cleared */
	    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(DMA_stream_selected)))
	    {
	      /* Do nothing until EN bit is cleared */
	    }

}

void DMA2_Stream5_INIT(void){

	  /* Enable DMA clock in RCC */
		RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;


	    /* DMA 2 stream 0 is enabled, shall be disabled first */
		DMA2_CR(5)&= ~DMA_SxCR_EN;

	    /* Wait until EN bit is cleared */
	    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(5)))
	    {
	      /* Do nothing until EN bit is cleared */
	    }


	  /* Select the DMA channel CHSEL[2:0] in the DMA_SxCR.
	   * (not needed when M->M). */
	    DMA2_CR(5) |=DMA2_STREAM_5_Channel_Selection;

	    /* Select Memmory brust */
	    DMA2_CR(5)|=DMA2_STREAM_5_MBURST;

	    /* Select perepheral brust */
	    DMA2_CR(5)|=DMA2_STREAM_5_PBURST;


	    /* Select Current target (only in double buffer mode)*/

		#if DMA2_STREAM_5_CT==TRUE
			DMA2_CR(5)|=DMA_SxCR_CT;
		#endif

		 /* Select DBM: Double buffer mode*/

		#if DMA2_STREAM_5_DBM==TRUE
			DMA2_CR(5)|=DMA_SxCR_DBM;
		#endif

	  /* Select stream priority very high */
	    DMA2_CR(5) |= DMA2_STREAM_5_PL;


	   /* Select INCOS: Peripheral increment offset size*/

		#if DMA2_STREAM_5_PINCOS==TRUE
			DMA2_CR(5)|=DMA_SxCR_PINCOS;
		#endif

		/* Select memory and peripherals sizes */
		  DMA2_CR(5)  |= DMA2_STREAM_5_MSIZE;
		  DMA2_CR(5)  |= DMA2_STREAM_5_PSIZE;


		 /* Select  MINC: Memory increment mode*/

		#if DMA2_STREAM_5_MINC==TRUE
			DMA2_CR(5)|=DMA_SxCR_MINC;
		#endif

		/* Select  PINC: Peripheral increment mode*/

		#if DMA2_STREAM_5_PINC==TRUE
			DMA2_CR(5)|=DMA_SxCR_PINC;
		#endif


		/* Select  CIRC: Circular mode*/

		#if DMA2_STREAM_5_CIRC==TRUE
			DMA2_CR(5)|=DMA_SxCR_CIRC;
		#endif




	  /* Select the data transfer direction memory to memory */
	    DMA2_CR(5)  |= DMA2_STREAM_5_DIR;


	    /* Select  PFCTRL: Peripheral flow controller*/

		#if DMA2_STREAM_5_PFCTRL==TRUE
			DMA2_CR(5)|=DMA_SxCR_PFCTRL;
		#endif



	    /* Select TCIE: Transfer complete interrupt enable*/

		#if DMA2_STREAM_5_TCIE==TRUE
			DMA2_CR(5)|=DMA_SxCR_TCIE;
		#endif



	    /* Select   HTIE: Half transfer interrupt enable*/

		#if DMA2_STREAM_5_HTIE==TRUE
			DMA2_CR(5)|=DMA_SxCR_HTIE;
		#endif


	    /* Select  TEIE: Transfer error interrupt enable*/

		#if DMA2_STREAM_5_TEIE==TRUE
			DMA2_CR(5)|=DMA_SxCR_TEIE;
		#endif



		/* Select  DMEIE: Direct mode error interrupt enable*/

		#if DMA2_STREAM_5_DMEIE==TRUE
			DMA2_CR(5)|=DMA_SxCR_DMEIE;
		#endif



	//# DMA_FCR			/*!< DMA stream x FIFO control register       */


			/* Select FEIE: FIFO error interrupt enable */

		DMA2_FCR(5) |= DMA2_STREAM_5_FIFO_Error_Interrupt_enable*DMA_SxFCR_FEIE;

	  /* Select FIFO mode, it will be also set by hardware when stream enabled */
	    DMA2_FCR(5) |= DMA2_STREAM_5_Direct_Mode_Disable*DMA_SxFCR_DMDIS;

	  /* Select FIFO threshold level half FIFO */
	    DMA2_FCR(5) |= DMA2_STREAM_5_FIFO_Threshold_Selection;





}






void DMA2_Channel_Set(uint8 DMA_stream_selected,uint16 DMA_Channel_selected){

		DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_CHSEL);

		DMA2_CR(DMA_stream_selected)|=(DMA_Channel_selected<<25);
}

void DMA2_Transefere_direction_set(uint8 DMA_stream_selected, uint8 DMA_Transfere_direction_selected){

	DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_DIR);

	DMA2_CR(DMA_stream_selected)|=(DMA_Transfere_direction_selected<<6);

}

void DMA2_Address_Set(uint8 DMA_stream_selected,const uint32 * DMA_prepherial_address,const uint32 * DMA_memory_address){


	DMA2_PAR(DMA_stream_selected)=(uint32)DMA_prepherial_address;

	DMA2_M0AR(DMA_stream_selected)=(uint32)DMA_memory_address;

}

void DMA2_Memory2Memory_Address_Set(uint8 DMA_stream_selected,const uint32 * source ,const uint32 * distenation){


	DMA2_PAR(DMA_stream_selected)=(uint32)distenation ;

	DMA2_M0AR(DMA_stream_selected)=(uint32)source;



}

void DMA2_Item_Number_Set(uint8 DMA_stream_selected,uint16 DMA_number_of_items){

	DMA2_NDTR(DMA_stream_selected)=DMA_number_of_items;

}

void DMA2_Priority_Set(uint8 DMA_stream_selected,uint8 DMA_Priority_selected){


	DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_PL);

	DMA2_CR(DMA_stream_selected)|=(DMA_Priority_selected<<16);


}

void DMA2_Data_Size_Set(uint8 DMA_stream_selected,uint8 DMA_Memory_size,uint8 DMA_Peripherial_size){



	DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_PSIZE|DMA_SxCR_MSIZE);

	DMA2_CR(DMA_stream_selected)|=(DMA_Memory_size<<13);

	DMA2_CR(DMA_stream_selected)|=(DMA_Peripherial_size<<11);


}


void DMA2_Enable(uint8 DMA_stream_selected){


	  /* Clear all interrupt flags */
		DMA2_HISR |= (DMA_HIFCR_CFEIF5 | DMA_HIFCR_CDMEIF5 | DMA_HIFCR_CTEIF5
	      | DMA_HIFCR_CHTIF5 | DMA_HIFCR_CTCIF5);

	  /* Enable DMA 2 stream 7 */
		DMA2_CR(DMA_stream_selected) |= DMA_SxCR_EN;
}





void DMA2_Disable(uint8 DMA_stream_selected){


	    /* DMA 2 stream 0 is enabled, shall be disabled first */
		DMA2_CR(5)&= ~DMA_SxCR_EN;

	    /* Wait until EN bit is cleared */
	    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(5)))
	    {
	      /* Do nothing until EN bit is cleared */
	    }

}

void DMA2_Transefere_Mode_set(uint8 DMA_stream_selected, uint8 DMA_Transfere_Mode_selected){

	DMA2_FCR(DMA_stream_selected)&=~(DMA_SxFCR_DMDIS);

	DMA2_FCR(DMA_stream_selected)|=(DMA_Transfere_Mode_selected<<2);


}

void DMA2_Circular_Mode_Enable(uint8 DMA_stream_selected){

//	DMA2_CR(DMA_stream_selected)&=~(DMA_stream_selected);

	DMA2_CR(DMA_stream_selected)|=(DMA_SxCR_CIRC);


}

void DMA2_Double_Buffer_Mode_Enable(uint8 DMA_stream_selected,uint8 DMA_started_memory){

	DMA2_CR(DMA_stream_selected)|=(DMA_SxCR_DBM);

}

void DMA2_Interrupt_Mask_Set(uint8 DMA_stream_selected,uint8 DMA_Interrupt_Mask){

	DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_TCIE|DMA_SxCR_HTIE|DMA_SxCR_TEIE|DMA_SxCR_DMEIE);

	DMA2_FCR(DMA_stream_selected)&=~(DMA_SxFCR_FEIE);

	/*Bit 1 DMEIE: Direct mode error interrupt enable	*/
	DMA2_CR(DMA_stream_selected)|=((DMA_Interrupt_Mask / 1)<<1);

	/*Bit 2 TEIE: Transfer error interrupt enable		*/
	DMA2_CR(DMA_stream_selected)|=((DMA_Interrupt_Mask / 2)<<2);

	/*Bit 3 HTIE: Half transfer interrupt enable		*/
	DMA2_CR(DMA_stream_selected)|=((DMA_Interrupt_Mask / 4)<<3);

	/*Bit 4 TCIE: Transfer complete interrupt enable	*/
	DMA2_CR(DMA_stream_selected)|=((DMA_Interrupt_Mask / 8)<<4);

	/*Bit 7 FEIE: FIFO error interrupt enable			*/
	DMA2_FCR(DMA_stream_selected)|=((DMA_Interrupt_Mask / 16)<<7);



}

void DMA2_Interrupt_Mask_Clear(uint8 DMA_stream_selected,uint8 DMA_Interrupt_Mask){
	if(DMA_stream_selected<4){
		uint8 stream_offset=((DMA_stream_selected*6)+(4*(DMA_stream_selected/2)));

		/*Bits 27, 21, 11, 5 CTCIFx: Stream x clear transfer complete interrupt flag (x = 3..0)*/
		DMA2_HIFCR|=((DMA_Interrupt_Mask/8)<<(stream_offset<<5));

		/*Bits 26, 20, 10, 4 CHTIFx: Stream x clear half transfer interrupt flag (x = 3..0)*/
		DMA2_HIFCR|=((DMA_Interrupt_Mask/4)<<(stream_offset<<4));

		/*Bits 25, 19, 9, 3 CTEIFx: Stream x clear transfer error interrupt flag (x = 3..0)*/
		DMA2_HIFCR|=((DMA_Interrupt_Mask/2)<<(stream_offset<<3));

		/*Bits 24, 18, 8, 2 CDMEIFx: Stream x clear direct mode error interrupt flag*/
		DMA2_HIFCR|=((DMA_Interrupt_Mask/1)<<(stream_offset<<2));

		/*Bits 22, 16, 6, 0 CFEIFx: Stream x clear FIFO error interrupt flag (x = 3..0)*/
		DMA2_HIFCR|=((DMA_Interrupt_Mask/16)<<(stream_offset));


	}
	else{

		DMA_stream_selected%=4;

		uint8 stream_offset=((DMA_stream_selected*6)+(4*(DMA_stream_selected/2)));

		/*Bits 27, 21, 11, 5 CTCIFx: Stream x clear transfer complete interrupt flag (x = 3..0)*/
		DMA2_LIFCR|=((DMA_Interrupt_Mask/8)<<(stream_offset<<5));

		/*Bits 26, 20, 10, 4 CHTIFx: Stream x clear half transfer interrupt flag (x = 3..0)*/
		DMA2_LIFCR|=((DMA_Interrupt_Mask/4)<<(stream_offset<<4));

		/*Bits 25, 19, 9, 3 CTEIFx: Stream x clear transfer error interrupt flag (x = 3..0)*/
		DMA2_LIFCR|=((DMA_Interrupt_Mask/2)<<(stream_offset<<3));

		/*Bits 24, 18, 8, 2 CDMEIFx: Stream x clear direct mode error interrupt flag*/
		DMA2_LIFCR|=((DMA_Interrupt_Mask/1)<<(stream_offset<<2));

		/*Bits 22, 16, 6, 0 CFEIFx: Stream x clear FIFO error interrupt flag (x = 3..0)*/
		DMA2_LIFCR|=((DMA_Interrupt_Mask/16)<<(stream_offset));






	}



}






uint8 DMA2_Interrupt_Status_Raw_Check(uint8 DMA_stream_selected){
	uint8 Interrupt_Status_Raw=0;
	if(DMA_stream_selected<4){
		uint8 stream_offset=((DMA_stream_selected*6)+(4*(DMA_stream_selected/2)));

		Interrupt_Status_Raw=(DMA2_HISR>>stream_offset)&0x3F;


	}
	else{

		DMA_stream_selected%=4;

		uint8 stream_offset=((DMA_stream_selected*6)+(4*(DMA_stream_selected/2)));

		Interrupt_Status_Raw=(DMA2_HISR>>stream_offset)&0x3F;

	}

	return Interrupt_Status_Raw;
}

uint8 DMA2_Interrupt_Status_Check(uint8 DMA_stream_selected,uint8 DMA_Interrupt_Mask);


void DMA2_FIFO_Control(uint8 DMA_stream_selected,uint8 DMA_FIFO_Threshold_Selected){


		DMA2_FCR(DMA_stream_selected)&=~(DMA_SxFCR_FTH);

		DMA2_FCR(DMA_stream_selected)|=(DMA_FIFO_Threshold_Selected);


}


uint8 DMA2_FIFO_Status_Check(uint8 DMA_stream_selected)
{


			return ((DMA2_FCR(DMA_stream_selected)>>3)& 0x3);


}

void DMA2_Incrementation_Control(uint8 DMA_stream_selected,uint8 DMA_Perepherial_Increment_Mode_Selected,uint8 DMA_Perepherial_Increment_Offset_size_selected ,uint8 DMA_Memory_Increment_Mode_Selected){

	DMA2_CR(DMA_stream_selected)&=~(DMA_SxCR_PINC|DMA_SxCR_MINC|DMA_SxCR_PINCOS);

	DMA2_CR(DMA_stream_selected)|=(DMA_Memory_Increment_Mode_Selected<<10);

	DMA2_CR(DMA_stream_selected)|=(DMA_Perepherial_Increment_Mode_Selected<<9);

	DMA2_CR(DMA_stream_selected)|=(DMA_Perepherial_Increment_Offset_size_selected<<15);

}




void DMA2_Interrupt_HalfTransfere_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void) ){

	DMA2_Interrupt_HalfTransfere_ISR_Callback_PTR=fun_ptr;
}

void DMA2_Interrupt_TranseferComplete_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  ){

	DMA2_Interrupt_TranseferComplete_ISR_Callback_PTR=fun_ptr;


}

void DMA2_Interrupt_TransfereError_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  ){

	DMA2_Interrupt_TransfereError_ISR_Callback_PTR=fun_ptr;

}

void DMA2_Interrupt_FifoOverrun_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  ){

	DMA2_Interrupt_FifoOverrun_ISR_Callback_PTR=fun_ptr;

}

void DMA2_Interrupt_DirectModeError_ISR_Callback_set(uint8 DMA_stream_selected , void(*fun_ptr)(void)  ){

	DMA2_Interrupt_DirectModeError_ISR_Callback_PTR=fun_ptr;

}



void DMA2_Stream5_Interruptr_ISR(void ){

	uint8 Interrupt_Raw_Data=DMA2_Interrupt_Status_Raw_Check(5);

	if((Interrupt_Raw_Data&HALF_TRANSFERE_INTERRUPT)==HALF_TRANSFERE_INTERRUPT){

		DMA2_Interrupt_HalfTransfere_ISR_Callback_PTR();
	}
	if((Interrupt_Raw_Data&TRANSFERE_COMPLETE_INTERRUPT)==TRANSFERE_COMPLETE_INTERRUPT){

		DMA2_Interrupt_TranseferComplete_ISR_Callback_PTR();

		}
	if((Interrupt_Raw_Data&TRANSFERE_ERROR_INTERRUPT)==TRANSFERE_ERROR_INTERRUPT){

		DMA2_Interrupt_TransfereError_ISR_Callback_PTR();

		}
	if((Interrupt_Raw_Data&FIFO_OVERRUN_INTERRUPT)==FIFO_OVERRUN_INTERRUPT){

		DMA2_Interrupt_FifoOverrun_ISR_Callback_PTR();

		}
	if((Interrupt_Raw_Data&DIRECR_MODE_ERROR_INTERRUPT)==DIRECR_MODE_ERROR_INTERRUPT){

		DMA2_Interrupt_DirectModeError_ISR_Callback_PTR();

		}

}






























/* ============================ STREAM 7 ================================= */

/**
 * @brief   DMA2 Stream0 initialization function
 * @note    Used for data transfer between two memory buffers
 * @param   None
 * @retval  None
 */
void DMA2_Stream_7_Init()
{
  /* Enable DMA clock in RCC */
	RCC_AHB1ENR |= RCC_AHB1ENR_DMA2EN;


    /* DMA 2 stream 0 is enabled, shall be disabled first */
	DMA2_CR(7)&= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_CR(7)))
    {
      /* Do nothing until EN bit is cleared */
    }


  /* Select the DMA channel CHSEL[2:0] in the DMA_SxCR.
   * (not needed when M->M). */
    DMA2_CR(7) |=DMA2_STREAM_7_Channel_Selection;

    /* Select Memmory brust */
    DMA2_CR(7)|=DMA2_STREAM_7_MBURST;

    /* Select perepheral brust */
    DMA2_CR(7)|=DMA2_STREAM_7_PBURST;


    /* Select Current target (only in double buffer mode)*/

	#if DMA2_STREAM_7_CT==TRUE
		DMA2_CR(7)|=DMA_SxCR_CT;
	#endif

	 /* Select DBM: Double buffer mode*/

	#if DMA2_STREAM_7_DBM==TRUE
		DMA2_CR(7)|=DMA_SxCR_DBM;
	#endif

  /* Select stream priority very high */
    DMA2_CR(7) |= DMA2_STREAM_7_PL;


   /* Select INCOS: Peripheral increment offset size*/

	#if DMA2_STREAM_7_PINCOS==TRUE
		DMA2_CR(7)|=DMA_SxCR_PINCOS;
	#endif

	/* Select memory and peripherals sizes */
	  DMA2_CR(7)  |= DMA2_STREAM_7_MSIZE;
	  DMA2_CR(7)  |= DMA2_STREAM_7_PSIZE;


	 /* Select  MINC: Memory increment mode*/

	#if DMA2_STREAM_7_MINC==TRUE
		DMA2_CR(7)|=DMA_SxCR_MINC;
	#endif

	/* Select  PINC: Peripheral increment mode*/

	#if DMA2_STREAM_7_PINC==TRUE
		DMA2_CR(7)|=DMA_SxCR_PINC;
	#endif


	/* Select  CIRC: Circular mode*/

	#if DMA2_STREAM_7_CIRC==TRUE
		DMA2_CR(7)|=DMA_SxCR_CIRC;
	#endif




  /* Select the data transfer direction memory to memory */
    DMA2_CR(7)  |= DMA2_STREAM_7_DIR;


    /* Select  PFCTRL: Peripheral flow controller*/

	#if DMA2_STREAM_7_PFCTRL==TRUE
		DMA2_CR(7)|=DMA_SxCR_PFCTRL;
	#endif



    /* Select TCIE: Transfer complete interrupt enable*/

	#if DMA2_STREAM_7_TCIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_TCIE;
	#endif



    /* Select   HTIE: Half transfer interrupt enable*/

	#if DMA2_STREAM_7_HTIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_HTIE;
	#endif


    /* Select  TEIE: Transfer error interrupt enable*/

	#if DMA2_STREAM_7_TEIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_TEIE;
	#endif



	/* Select  DMEIE: Direct mode error interrupt enable*/

	#if DMA2_STREAM_7_DMEIE==TRUE
		DMA2_CR(7)|=DMA_SxCR_DMEIE;
	#endif



//# DMA_FCR			/*!< DMA stream x FIFO control register       */


		/* Select FEIE: FIFO error interrupt enable */

	DMA2_FCR(7) |= DMA2_STREAM_7_FIFO_Error_Interrupt_enable*DMA_SxFCR_FEIE;

  /* Select FIFO mode, it will be also set by hardware when stream enabled */
    DMA2_FCR(7) |= DMA2_STREAM_7_Direct_Mode_Disable*DMA_SxFCR_DMDIS;

  /* Select FIFO threshold level half FIFO */
    DMA2_FCR(7) |= DMA2_STREAM_7_FIFO_Threshold_Selection;



}



/**
 * @brief   DMA2 Stream0 set addresses function
 * @note    Sets the addresses of the memory and peripheral ports,
 *          and number of data items to be transfered.
 * @param   src, dst, size
 * @retval  None
 */
void DMA2_Stream_7_Set_Addresses(const uint32 * src,
    uint32 * dst, const uint32 size)
{
#if DMA2_STREAM_7_DIR==Memory_to_memory
	  /* Set the source address to the peripheral port */
		DMA2_PAR(7)= (uint32)src;

	  /* Set the destination address to the memory port */
		DMA2_M0AR(7)= (uint32)dst;

	  /* Set number of data items */
		DMA2_NDTR(7) = size;

#elif DMA2_STREAM_7_DIR==Memory_to_peripheral

	  /* Set the source address to the peripheral port */
		DMA2_M0AR(7)= (uint32)src;

	  /* Set the destination address to the memory port */
		DMA2_PAR(7)= (uint32)dst;

	  /* Set number of data items */
		DMA2_NDTR(7) = size;




#elif DMA2_STREAM_7_DIR==Peripheral_to_memory

		  /* Set the source address to the peripheral port */
			DMA2_PAR(7)= (uint32)src;

		  /* Set the destination address to the memory port */
			DMA2_M0AR(7)= (uint32)dst;

		  /* Set number of data items */
			DMA2_NDTR(7) = size;

	#endif
}


/**
 * @brief   DMA2 Stream7 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_7_Enable()
{
  /* Clear all interrupt flags */
	DMA2_HISR = (DMA_HIFCR_CFEIF7 | DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CTEIF7
      | DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTCIF7);

  /* Enable DMA 2 stream 7 */
	DMA2_CR(7) |= DMA_SxCR_EN;
}


/**
 * @brief   DMA2 Stream5 enable function
 * @note
 * @param   None
 * @retval  None
 */
void DMA2_Stream_5_Enable()
{
  /* Clear all interrupt flags */
	DMA2_HISR = (DMA_HIFCR_CFEIF5 | DMA_HIFCR_CDMEIF5 | DMA_HIFCR_CTEIF5
      | DMA_HIFCR_CHTIF5 | DMA_HIFCR_CTCIF5);

  /* Enable DMA 2 stream 7 */
	DMA2_CR(5) |= DMA_SxCR_EN;
//	DMA2_Stream5->CR |= DMA_SxCR_EN;
}

