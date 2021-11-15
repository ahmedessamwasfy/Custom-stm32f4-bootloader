

/*******************************************************************************
 * @file    USART1.c
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @website 
 * @date    Sep 18, 2019
 *
 * @brief   USART1.c example using ST virtual COM port (VCP)
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

//* Includes */

#include <myUSART1.h>
#include <stddef.h>
//#include "stm32f4xx.h"
/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup USART1.c
 * @brief
 * @{
 */

/**
 * @defgroup USART1.c_private_typedefs
 * @{
 */



/*

 * @}
 */

/**
 * @defgroup USART1.c_private_defines
 * @{
 */

/**
 * @brief   Maximum USART reception buffer length
 */
//#define MAX_BUFFER_LENGTH                     ((uint32_t) 128u)

/**
 * @}
 */

/**
 * @defgroup USART1.c_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.c_private_constants
 * @{
 */
static const char hello_world[]        = "Hello Boy !";
static const char ask_for_name[]       = "What is your name?";
static const char hi[]                 = "Hi,";
static const char ask_for_command[]    = "Please, send command";
static const char ask_for_command_ex[] = "Action[turn_on / turn_off] Led[green_led / red_led]";
static const char turn_on_green_led[]  = "turn_on green_led";
static const char turn_on_red_led[]    = "turn_on red_led";
static const char turn_off_green_led[] = "turn_off green_led";
static const char turn_off_red_led[]   = "turn_off red_led";
static const char done[]               = "Done";
static const char wrong_command[]      = "Wrong Command";
static const char parity_error[]       = "Parity Error";
/**
 * @}
 */

/**
 * @defgroup USART1.c_private_variables
 * @{
 */

/**
 * @brief   USART1 message buffer
 */
//extern uint8 RxBuffer[MAX_BUFFER_LENGTH+1 ];

/**
 * @brief   USART1 Char Recieved
 */
//extern char RxChar;












/**
 * @}
 */

/**
 * @defgroup USART1.c_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup USART1.c_private_functions
 * @{
 */



/**
 * @brief   Compare two strings
 * @note    take the size of the predefined string
 * @param   str1, str2, size
 * @retval  strCmpReturnType
 */
static strCmpReturnType strCmp(const char * str1, const char * str2,
    const uint8_t size)
{
  /* Compare status */
  strCmpReturnType cmpStatus = STR_EQUAL;

  /* Check null pointers */
  if((NULL != str1) && (NULL != str2))
  {
    /* Start comparing */
    for (int idx = 0; idx < size; idx++)
    {
      /* When not equal set the return status */
      if(str1[idx] != str2[idx])
      {
        cmpStatus = STR_NOT_EQUAL;
      }
      else
      {
        /* Do nothing */
      }
    }
  }
  else
  {
    /* Null pointers, do nothing */
  }
  return cmpStatus;
}

/**
 * @brief   String transmit
 * @note
 * @param   str, size
 * @retval  None
 */
 void USART1_STR_Transmit(const char * str, uint8 size)
{
	  /* Check null pointers */
	  if(NULL != str)
	  {
	    /* Send all string characters */
	    for(uint8 idx = 0; idx < size; idx++)
	    {
	      USART1_CHAR_Transmit(str[idx]);
	    }
	    ///* Send end of line aka new line */
		  //USART1_CHAR_Transmit('\n');

	  }
	  else
	  {
	    /* Null pointers, do nothing */
	  }


}



 /**
  * @brief   DMA string transmit
  * @note
  * @param   str, size
  * @retval  None
  */
  void strTransmit_with_DMA(const char * str, uint8_t size)
 {
   /* Check null pointers */
   if(NULL != str)
   {
     /* Wait until DMA2 stream 7 is disabled */
     while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream7->CR))
     {
       /* Do nothing, the enable flag shall reset
        * when DMA transfer complete */
     }

     /* Set memory address */
     DMA2_Stream7->M0AR = (uint32_t)str;

     /* Set number of data items */
     DMA2_Stream7->NDTR = size;

     /* Clear all interrupt flags */
     DMA2->HIFCR = (DMA_HIFCR_CFEIF7 | DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CTEIF7
         | DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTCIF7);

     /* Enable DMA2 stream 7 */
     DMA2_Stream7->CR |= DMA_SxCR_EN;
   }
   else
   {
     /* Null pointers, do nothing */
   }
 }





 /**
  * @brief   CHAR transmit
  * @note
  * @param   str,
  * @retval  None
  */
  void USART1_CHAR_Transmit(const char  CHAR_To_Send)
 {

     /* Send all string characters */
       /* Check USART status register */
       while(!(USART1_SR & USART_SR_TXE))
       {
         /* Wait for transmission buffer empty flag */
       }

       /* Write data into transmit data register */
       USART1_DR = CHAR_To_Send;

 }





  /**
   * @brief   String receive
   * @note
   * @param   None
   * @retval  None
   */
   void strReceive(void)
  {
	 //  while(RX_FLAG!= TRUE);
    /* Local string buffer */
     static char RxLocalBuffer[MAX_BUFFER_LENGTH]="";

    /* Current reception index */
     static uint32 RxIndex = 0;

    if(RxChar=='\0'){
        /* Check if string data was received before */
        if (RxIndex != 0){

        	 /* Copy string data from local buffer */
        	      for(int idx = 0; idx < RxIndex; idx++)
        	      {
        	        RxBuffer[idx] = RxLocalBuffer[idx];
        	      }
        	      /* Add terminating NULL at the end */
        	         RxBuffer[RxIndex] = 0;

        	         /* Set message length */
        	         RxMessageLength = RxIndex + 1;

        	         /* Reset current index */
        	         RxIndex = 0;
        }
        else
                {
                  /* String buffer already empty */
                }
    }
    else {
    	/* Char data was received, Check for buffer overflow */
    	    if (MAX_BUFFER_LENGTH == RxIndex)
    	    {
    	      /* Reset the reception buffer */
    	      RxIndex = 0;
    	    }
    	    else
    	    {
    	      /* Do nothing, No overflow */
    	    }

    	    /* Copy char data into string buffer */
    	    RxLocalBuffer[RxIndex] = RxChar;

    	    /* Increment current index for the next char reception */
    	    RxIndex++;
    	  }
    }


  /**
   * @brief   CHAR receive
   * @note
   * @param   None
   * @retval  None
   */
   uint8 USART1_CHAR_Receive(void){
	    uint8 CharRecived =-1;
	    /* Check USART receiver and wait till recived */
	      while((USART1->SR & USART_SR_RXNE) != USART_SR_RXNE);

	        /* Read character */
	      	      CharRecived = USART1->DR;
	      //CharRecived='L';
	        /* Set IRQ status */
	       // currentIRQStatus = USART1_CHAR_RECEIVED;

	     // else CharRecived='N';
	      return CharRecived;

   }

/**
 * @}
 */

/**
 * @defgroup USART1.c_exported_functions
 * @{
 */
/*
  void  USART1_RECIEVE_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_RECIEVE_callBack_function_pointer=fun_ptr;

  }



  void  USART1_TRANSMIT_DATA_EMPTY_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_TRANSMIT_DATA_EMPTY_callBack_function_pointer=fun_ptr;

  }


  void  USART1_CTS_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_CTS_callBack_function_pointer=fun_ptr;

  }


  void  USART1_TRANSMIT_COMPLETE_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_TRANSMIT_COMPLETE_callBack_function_pointer=fun_ptr;

  }


  void  USART1_OVERRUN_ERROR_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_OVERRUN_ERROR_callBack_function_pointer=fun_ptr;

  }


  void  USART1_IDLE_LINE_DETECT_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_IDLE_LINE_DETECT_callBack_function_pointer=fun_ptr;

  }


  void  USART1_PARITY_ERROR_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_PARITY_ERROR_callBack_function_pointer=fun_ptr;

  }


  void  USART1_BREAK_FLAG_CallBack_function_Set(void (*fun_ptr)(void)){

	  USART1_BREAK_FLAG_callBack_function_pointer=fun_ptr;

  }

*/











/**
 * @brief   Configure USART1 for ST virtual COM port (VCP)
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Init(void)
{
	  // USART1_GPIO_Config();
  /* Configure USART1 */
  /* Enable USART1 clock */
  RCC_APB2ENR|= RCC_APB2ENR_USART1EN;

  ///////////////////control register 1

  /* Select oversampling by 16 mode */
  USART1_CR1 |= USART_CR1_OVER8*USART1_OVER8;
  USART1_CR1 |= USART_CR1_UE*USART1_UE;
  /* Select 1 Start bit, 9 Data bits, n Stop bit */
  USART1_CR1 |= USART_CR1_M*USART1_M;
  /* Enable parity control */
  USART1_CR1 |= USART_CR1_PCE*USART1_PCE;

  /* Select odd parity */
  USART1_CR1 |= USART_CR1_PS*USART1_PS;

  USART1_CR1 |= USART_CR1_PEIE*USART1_PEIE;
  USART1_CR1 |= USART_CR1_TXEIE*USART1_TXEIE;
  USART1_CR1 |= USART_CR1_TCIE*USART1_TCIE;
  USART1_CR1 |= USART_CR1_RXNEIE*USART1_RXNEIE;
  USART1_CR1 |= USART_CR1_IDLEIE*USART1_IDLEIE;
  USART1_CR1 |= USART_CR1_TE*USART1_TE;
  USART1_CR1 |= USART_CR1_RE*USART1_RE;
  USART1_CR1 |= USART_CR1_RWU*USART1_RWU;
  USART1_CR1 |= USART_CR1_SBK*USART1_SBK;

  ///////////////////control register 2
  /* Select 1 stop bit */
  USART1_CR2|=USART1_STOP;
  USART1_CR2|=USART_CR2_CLKEN*USART1_CLKEN;
  USART1_CR2|=USART_CR2_CPOL*USART1_CPOL;
  USART1_CR2|=USART_CR2_CPHA*USART1_CPHA;
  USART1_CR2|=USART_CR2_LBCL*USART1_LBCL;
  USART1_CR2|=USART_CR2_LBDL*USART1_LBDL;

  ///////////////////control register 3
  USART1_CR3|=USART_CR3_ONEBIT*USART1_ONEBIT;
  USART1_CR3|=USART_CR3_CTSIE*USART1_CTSIE;
  USART1_CR3|=USART_CR3_CTSE*USART1_CTSE;
  USART1_CR3|=USART_CR3_RTSE*USART1_RTSE;
  USART1_CR3|=USART_CR3_DMAT*USART1_DMAT;
  USART1_CR3|=USART_CR3_DMAR*USART1_DMAR;
  USART1_CR3|=USART_CR3_SCEN*USART1_SCEN;
  USART1_CR3|=USART_CR3_NACK*USART1_NACK;
  USART1_CR3|=USART_CR3_HDSEL*USART1_HDSEL;
  USART1_CR3|=USART_CR3_IRLP*USART1_IRLP;
  USART1_CR3|=USART_CR3_IREN*USART1_IREN;
  USART1_CR3|=USART_CR3_EIE*USART1_EIE;


  /* Set baud rate = 115200 Bps
   * USARTDIV = Fck / (16 * baud_rate)
   *          = 90000000 / (16 * 115200) = 48.82
   *
   * DIV_Fraction = 16 * 0.82 = 13.12 = 13 = 0xD
   * DIV_Mantissa = 48 = 0x30
   *
   * BRR          = 0x30D */
  USART1_BRR = 0x30D;




//	  /* Configure USART1 */
//	  /* Enable USART1 clock */
//	  RCC->APB2ENR = RCC_APB2ENR_USART1EN;
//
//	  /* Select oversampling by 16 mode */
//	  USART1->CR1 &= ~USART_CR1_OVER8;
//
//	  /* Select one sample bit method */
//	  USART1->CR3 |= USART_CR3_ONEBIT;
//
//	  /* Select 1 Start bit, 9 Data bits, n Stop bit */
//	  USART1->CR1 |= USART_CR1_M;
//
//	  /* Select 1 stop bit */
//	  USART1->CR2 &= ~USART_CR2_STOP;
//
//	  /* Enable parity control */
//	  USART1->CR1 |= USART_CR1_PCE;
//
//	  /* Select odd parity */
//	  USART1->CR1 |= USART_CR1_PS;
//
//	  /* Set baud rate = 115200 Bps
//	   * USARTDIV = Fck / (16 * baud_rate)
//	   *          = 90000000 / (16 * 115200) = 48.82
//	   *
//	   * DIV_Fraction = 16 * 0.82 = 13.12 = 13 = 0xD
//	   * DIV_Mantissa = 48 = 0x30
//	   *
//	   * BRR          = 0x30D */
//	  USART1->BRR = 0x30D;
//
//
//










#if USART1_DMAT ==TRUE

#endif

#if USART1_DMAR ==TRUE
#endif
}

/**
 * @brief   Configure GPIO with AF7, USART1 connected to APB2 with 90MHz clock
 * @note    PA9 -> USART1_TX, PA10 -> USART1_RX
 * @param   None
 * @retval  None
 */
void myUSART1_GPIO_Config(void){

	//RCC_APB1ENR|=RCC_AHB1ENR_GPIOAEN;
	GPIO_OUT_INIT(USART1_TX_PORT  , USART1_TX_PIN , gpio_alternative, 7 ,push_pull , medium_speed, pull_up  );
	GPIO_OUT_INIT(USART1_RX_PORT  , USART1_RX_PIN , gpio_alternative, 7 ,push_pull , medium_speed, pull_up  );
#if (USART1_RTSE&&USART1_CTSE)==TRUE
	GPIO_OUT_INIT(USART1_RTS_PORT  , USART1_RTS_PIN , gpio_alternative, 7 ,push_pull , medium_speed, pull_up  );
	GPIO_OUT_INIT(USART1_CTS_PORT  , USART1_CTS_PIN , gpio_alternative, 7 ,push_pull , medium_speed, pull_up  );
	#endif

#if USART_CLKEN==TRUE
	GPIO_OUT_INIT(USART1_CK_PORT  , USART1_CK_PIN , gpio_alternative, 7 ,push_pull , medium_speed, pull_up  );
#endif
}


/**
 * @brief   Enable USART1 transmitter and receiver
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Enable(void)
{
  /* Enable USART1 */
  USART1_CR1 |= USART_CR1_UE;

  /* Enable transmitter */
  USART1_CR1 |= USART_CR1_TE;

  /* Enable receiver */
  USART1_CR1 |= USART_CR1_RE;


  /* Enable reception buffer not empty flag interrupt */
//  USART1_CR1 |= USART_CR1_RXNEIE;

  /* Enable parity error interrupt */
//  USART1_CR1 |= USART_CR1_PEIE;

  /* Enable idle line detection interrupt */ /* in order to know when massage ended*/
   USART1->CR1 |= USART_CR1_IDLEIE;

  /* Enable DMA mode for transmitter and receiver */
  USART1->CR3 |= USART_CR3_DMAT;
  USART1->CR3 |= USART_CR3_DMAR;

  /*Enable DMA2 Stream 5 which is  RX using DMA*/
  DMA2_Stream_5_Enable();

  /* Clear all DMA interrupt flags for RX */
 /* DMA2->HIFCR = (DMA_HIFCR_CFEIF5 | DMA_HIFCR_CDMEIF5 | DMA_HIFCR_CTEIF5
      | DMA_HIFCR_CHTIF5 | DMA_HIFCR_CTCIF5);
*/
  /* Enable DMA2 stream 5 for RX */
  //DMA2_Stream5->CR |= DMA_SxCR_EN;
}




/**
 * @brief   Configure DMA for USART TX
 * @note    USART1_TX -> DMA2_Stream7 (Channel 4)
 * @param   None
 * @retval  None
 */
void USART1_TX_DMA_Config(void)
{
  /* Enable DMA clock in RCC */
  RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

  /* Make sure that the DMA2 stream 7 is disabled */
  if(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream7->CR))
  {
    /* DMA 2 stream 7 is enabled, shall be disabled first */
    DMA2_Stream7->CR &= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream7->CR))
    {
      /* Do nothing until EN bit is cleared */
    }
  }
  else
  {
    /* Do nothing, stream 7 is not enabled */
  }

  /* Select the DMA channel 4 in CHSEL[2:0] in the DMA_SxCR */
  DMA2_Stream7->CR &= ~DMA_SxCR_CHSEL;
  DMA2_Stream7->CR |= DMA_SxCR_CHSEL_2;

  /* Select stream priority very high */
  DMA2_Stream7->CR |= DMA_SxCR_PL;

  /* Select the data transfer direction memory-to-peripheral */
  DMA2_Stream7->CR &= ~DMA_SxCR_DIR;
  DMA2_Stream7->CR |= DMA_SxCR_DIR_0;

  /* Select memory and peripherals sizes byte (8-bit) */
  DMA2_Stream7->CR &= ~DMA_SxCR_MSIZE;
  DMA2_Stream7->CR &= ~DMA_SxCR_PSIZE;

  /* Select FIFO mode */
  DMA2_Stream7->FCR |= DMA_SxFCR_DMDIS;

  /* Select FIFO threshold level half FIFO */
  DMA2_Stream7->FCR |= (DMA_SxFCR_FTH_0 | DMA_SxFCR_FTH_1);

  /* Select memory incremented mode, peripheral shall has fixed address and memory increment */
  DMA2_Stream7->CR |= DMA_SxCR_MINC;

  /* Enable DMA transfer complete interrupt */
  DMA2_Stream7->CR |= DMA_SxCR_TCIE;

  /* Set peripheral address */
  DMA2_Stream7->PAR = (uint32_t)&USART1->DR;
}

/**
 * @brief   Configure DMA for USART RX
 * @note    USART1_RX -> DMA2_Stream5 (Channel 4)
 * @param   None
 * @retval  None
 */
void USART1_RX_DMA_Config(void)
{
  /* Enable DMA clock in RCC */
  RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

  /* Make sure that the DMA2 stream 5 is disabled */
  if(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream5->CR))
  {
    /* DMA 2 stream 5 is enabled, shall be disabled first */
    DMA2_Stream5->CR &= ~DMA_SxCR_EN;

    /* Wait until EN bit is cleared */
    while(DMA_SxCR_EN == (DMA_SxCR_EN & DMA2_Stream5->CR))
    {
      /* Do nothing until EN bit is cleared */
    }
  }
  else
  {
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

  /* Select memory incremented mode, peripheral shall has fixed address and memory increment */
  DMA2_Stream5->CR |= DMA_SxCR_MINC;

  /* Enable DMA transfer complete interrupt */
  DMA2_Stream5->CR |= DMA_SxCR_TCIE;

  /* Set peripheral address */
  DMA2_Stream5->PAR = (uint32_t)&USART1->DR;

  /* Set memory address */
  DMA2_Stream5->M0AR = (uint32_t)RxDMABuffer;

  /* Set number of data items */
  DMA2_Stream5->NDTR = MAX_BUFFER_LENGTH;
}







/**
 * @brief   IRQ callback function
 * @note
 * @param   None
 * @retval  None
 */

void USART1_IRQ_Callback(void)
{
  /* Check if parity error detected */
  if((USART1_SR & USART_SR_PE) == USART_SR_PE)
  {
    while((USART1_SR & USART_SR_RXNE) != USART_SR_RXNE)
    {
      /* Wait for RXNE flag to be set */
    }

    /* Read data register to clear parity error */
    USART1_DR;

    /* Set parity error */
    //currentIRQStatus = USART1_PARITY_ERROR;
    /* Set parity error in DMA Example*/
    currentErrorStatus = USART1_PARITY_ERROR_With_DMA;

    /* Disable DMA stream for RX */
    DMA2_Stream5->CR &= ~DMA_SxCR_EN;
  }
  else
  {
    /* No parity error */
  }

  /* Check if idle line detected */
   if((USART1->SR & USART_SR_IDLE) == USART_SR_IDLE)
   {
     /* Read data register to clear idle line flag */
     (void)USART1->DR;

     /* Disable DMA stream for RX */
     DMA2_Stream5->CR &= ~DMA_SxCR_EN;
   }
   else
   {
     /* No new data received */
   }

  /* Check USART receiver */
  if((USART1_SR & USART_SR_RXNE) == USART_SR_RXNE)
  {
//	  (*USART1_RECIEVE_callBack_function_pointer)();

  }
  else
  {
    /* No new data received */
  }
}











/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void myUSART1_Process(void)
{
  /* Check error status */
  switch (currentIRQStatus)
  {
    case USART1_PARITY_ERROR:
      /* Transmit parity error */
      USART1_STR_Transmit(parity_error, sizeof(parity_error));

      /* Reset USART1 state */
      currentState = USART1_IDLE;

      /* Reset IRQ status */
      currentIRQStatus = USART1_NO_IRQ;
      break;

    case USART1_CHAR_RECEIVED:
      /* Receive string data */
      strReceive();

      /* Reset IRQ status */
      currentIRQStatus = USART1_NO_IRQ;
      break;

    case USART1_NO_IRQ:
      break;

    default:
      break;
  }

  /* Check current USART state */
  switch (currentState)
  {
    case USART1_IDLE:
      /* Transmit data */
      USART1_STR_Transmit(hello_world, sizeof(hello_world));

      /* Go to next state */
      currentState = USART1_WAIT_FOR_RESPONCE;
      break;

    case USART1_WAIT_FOR_RESPONCE:
      /* Check if new message received */
      if(0 != RxMessageLength)
      {
        /* Reset message length */
        RxMessageLength = 0;

        /* Go to next state */
        currentState = USART1_ASK_FOR_NAME;
      }
      else
      {
        /* Nothing received yet */
      }
      break;

    case USART1_ASK_FOR_NAME:
      /* Transmit data */
    	USART1_STR_Transmit(ask_for_name, sizeof(ask_for_name));

      /* Go to next state */
      currentState = USART1_WAIT_FOR_NAME;
      break;

    case USART1_WAIT_FOR_NAME:
      /* Check if new message received */
      if(0 != RxMessageLength)
      {
        /* Transmit data */
    	  USART1_STR_Transmit(hi, sizeof(hi));
    	  USART1_STR_Transmit(RxBuffer, RxMessageLength);
    	  USART1_STR_Transmit(ask_for_command, sizeof(ask_for_command));
    	  USART1_STR_Transmit(ask_for_command_ex, sizeof(ask_for_command_ex));

        /* Reset message length */
        RxMessageLength = 0;

        /* Go to next state */
        currentState = USART1_WAIT_FOR_COMMAND;
      }
      else
      {
        /* Nothing received yet */
      }
      break;

    case USART1_WAIT_FOR_COMMAND:
      /* Check if new message received */
      if(0 != RxMessageLength)
      {
        /* Reset message length */
        RxMessageLength = 0;

        /* String compare results */
        strCmpReturnType isMatch_01 = STR_NOT_EQUAL;
        strCmpReturnType isMatch_02 = STR_NOT_EQUAL;
        strCmpReturnType isMatch_03 = STR_NOT_EQUAL;
        strCmpReturnType isMatch_04 = STR_NOT_EQUAL;

        /* Compare with turn on green led command */
        isMatch_01 =  strCmp(turn_on_green_led, RxBuffer,
            sizeof(turn_on_green_led));

        /* Check return status */
        if(STR_EQUAL == isMatch_01)
        {
          /* Turn on green led */
          myGPIO_TurnON_LED(myEVAL_GREEN_LED);

          /* Transmit data */
          USART1_STR_Transmit(done, sizeof(done));
        }
        else
        {
          /* Compare with turn on red led command */
          isMatch_02 =  strCmp(turn_on_red_led, RxBuffer,
              sizeof(turn_on_red_led));
        }

        /* Check return status */
        if(STR_EQUAL == isMatch_02)
        {
          /* Turn on red led */
          myGPIO_TurnON_LED(myEVAL_RED_LED);

          /* Transmit data */
          USART1_STR_Transmit(done, sizeof(done));
        }
        else if(STR_NOT_EQUAL == isMatch_01)
        {
          /* Compare with turn off green led command */
          isMatch_03 =  strCmp(turn_off_green_led, RxBuffer,
              sizeof(turn_off_green_led));
        }
        else
        {
          /* Do nothing */
        }

        /* Check return status */
        if(STR_EQUAL == isMatch_03)
        {
          /* Turn off green led */
          myGPIO_TurnOFF_LED(myEVAL_GREEN_LED);

          /* Transmit data */
          USART1_STR_Transmit(done, sizeof(done));
        }
        else if((STR_NOT_EQUAL == isMatch_02)
            && (STR_NOT_EQUAL == isMatch_01))
        {
          /* Compare with turn off red led command */
          isMatch_04 =  strCmp(turn_off_red_led, RxBuffer,
              sizeof(turn_off_red_led));
        }
        else
        {
          /* Do nothing */
        }

        /* Check return status */
        if(STR_EQUAL == isMatch_04)
        {
          /* Turn off red led */
          myGPIO_TurnOFF_LED(myEVAL_RED_LED);

          /* Transmit data */
          USART1_STR_Transmit(done, sizeof(done));
        }
        else if((STR_NOT_EQUAL == isMatch_03)
            && (STR_NOT_EQUAL == isMatch_02)
            && (STR_NOT_EQUAL == isMatch_01))
        {
          /* Transmit data */
        	USART1_STR_Transmit(wrong_command, sizeof(wrong_command));
        }
        else
        {
          /* Do nothing */
        }
      }
      else
      {
        /* Nothing received yet */
      }
      break;

    default:
      break;
  }
}



/**
 * @brief   USART1 transmit and receive data
 * @note
 * @param   None
 * @retval  None
 */
void USART1_Process_with_DMA(void)
{
  /* Check error status */
  if(USART1_NO_ERROR == currentErrorStatus)
  {
    /* Check current USART state */
    switch (currentState)
    {
      case USART1_IDLE:
        /* Transmit data */
    	  strTransmit_with_DMA(hello_world, sizeof(hello_world));

        /* Go to next state */
        currentState = USART1_WAIT_FOR_RESPONCE;
        break;

      case USART1_WAIT_FOR_RESPONCE:
        /* Check if new message received */
        if(0 != RxMessageLength)
        {
          /* Reset message length */
          RxMessageLength = 0;

          /* Go to next state */
          currentState = USART1_ASK_FOR_NAME;
        }
        else
        {
          /* Nothing received yet */
        }
        break;

      case USART1_ASK_FOR_NAME:
        /* Transmit data */
    	  strTransmit_with_DMA(ask_for_name, sizeof(ask_for_name));

        /* Go to next state */
        currentState = USART1_WAIT_FOR_NAME;
        break;

      case USART1_WAIT_FOR_NAME:
        /* Check if new message received */
        if(0 != RxMessageLength)
        {
          /* Transmit data */
        	strTransmit_with_DMA(hi, sizeof(hi));
        	strTransmit_with_DMA(RxBuffer, RxMessageLength);
        	strTransmit_with_DMA(ask_for_command, sizeof(ask_for_command));
        	strTransmit_with_DMA(ask_for_command_ex, sizeof(ask_for_command_ex));

          /* Reset message length */
          RxMessageLength = 0;

          /* Go to next state */
          currentState = USART1_WAIT_FOR_COMMAND;
        }
        else
        {
          /* Nothing received yet */
        }
        break;

      case USART1_WAIT_FOR_COMMAND:
        /* Check if new message received */
        if(0 != RxMessageLength)
        {
          /* Reset message length */
          RxMessageLength = 0;

          /* String compare results */
          strCmpReturnType isMatch_01 = STR_NOT_EQUAL;
          strCmpReturnType isMatch_02 = STR_NOT_EQUAL;
          strCmpReturnType isMatch_03 = STR_NOT_EQUAL;
          strCmpReturnType isMatch_04 = STR_NOT_EQUAL;

          /* Compare with turn on green led command */
          isMatch_01 = strCmp(turn_on_green_led, RxBuffer,
              sizeof(turn_on_green_led));

          /* Check return status */
          if(STR_EQUAL == isMatch_01)
          {
            /* Turn on green led */
            myGPIO_TurnON_LED(myEVAL_GREEN_LED);

            /* Transmit data */
            strTransmit_with_DMA(done, sizeof(done));
          }
          else
          {
            /* Compare with turn on red led command */
            isMatch_02 = strCmp(turn_on_red_led, RxBuffer,
                sizeof(turn_on_red_led));
          }

          /* Check return status */
          if(STR_EQUAL == isMatch_02)
          {
            /* Turn on red led */
            myGPIO_TurnON_LED(myEVAL_RED_LED);

            /* Transmit data */
            strTransmit_with_DMA(done, sizeof(done));
          }
          else if(STR_NOT_EQUAL == isMatch_01)
          {
            /* Compare with turn off green led command */
            isMatch_03 = strCmp(turn_off_green_led, RxBuffer,
                sizeof(turn_off_green_led));
          }
          else
          {
            /* Do nothing */
          }

          /* Check return status */
          if(STR_EQUAL == isMatch_03)
          {
            /* Turn off green led */
            myGPIO_TurnOFF_LED(myEVAL_GREEN_LED);

            /* Transmit data */
            strTransmit_with_DMA(done, sizeof(done));
          }
          else if((STR_NOT_EQUAL == isMatch_02)
              && (STR_NOT_EQUAL == isMatch_01))
          {
            /* Compare with turn off red led command */
            isMatch_04 = strCmp(turn_off_red_led, RxBuffer,
                sizeof(turn_off_red_led));
          }
          else
          {
            /* Do nothing */
          }

          /* Check return status */
          if(STR_EQUAL == isMatch_04)
          {
            /* Turn off red led */
            myGPIO_TurnOFF_LED(myEVAL_RED_LED);

            /* Transmit data */
            strTransmit_with_DMA(done, sizeof(done));
          }
          else if((STR_NOT_EQUAL == isMatch_03)
              && (STR_NOT_EQUAL == isMatch_02)
              && (STR_NOT_EQUAL == isMatch_01))
          {
            /* Transmit data */
        	  strTransmit_with_DMA(wrong_command, sizeof(wrong_command));
          }
          else
          {
            /* Do nothing */
          }
        }
        else
        {
          /* Nothing received yet */
        }
        break;

      default:
        break;
    }
  }
  else if(USART1_PARITY_ERROR_With_DMA == currentErrorStatus)
  {
    /* Transmit parity error */
	  strTransmit_with_DMA(parity_error, sizeof(parity_error));

    /* Clear error status */
    currentErrorStatus = USART1_NO_ERROR;
  }
  else
  {
    /* No error detected */
  }
}




/**
 * @brief   USART1 Set the CallBack Function For the ISR of Recive shift register not empty
 * @note
 * @param   pointer to function given by user to call in ISR
 * @retval  None
 * @purpos  Set the call back function to make it modularized and isolate the user from the source file
 */


void  USART1_RECIEVE_CallBack_function_Set(void (*fun_ptr)(void)){
	USART1_RECIEVE_callBack_function_pointer=fun_ptr;
}



















/************************new version***********************/

/*


void USART1_EN(void){

	USART1->CR1|=USART_CR1_UE;
}

 void USART1_Dis(void){


		USART1->CR1&=(~USART_CR1_UE);
 }



 void USART1_TX_EN(void){


		USART1->CR1|=USART_CR1_TE;
 }

 void USART1_TX_Dis(void){

	 USART1->CR1&=(~USART_CR1_TE);
 }



 void USART1_RX_EN(void){
	 USART1->CR1|=USART_CR1_RE;
 }

 void USART1_RX_Dis(void){
	 USART1->CR1&=(~USART_CR1_RE);
 }
*/










 /*Temp fun*/

 void USART1_TX_DMA_IRQ_Callback(void){

	  /* Check transfer complete flag */
	  if(DMA_HISR_TCIF7 == (DMA_HISR_TCIF7 & DMA2->HISR))
	  {
	    /* Clear all interrupt flags */
	    DMA2->HIFCR = (DMA_HIFCR_CFEIF7 | DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CTEIF7
	        | DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTCIF7);
	  }
	  else
	  {
	    /* Do nothing, this interrupt is not handled */
	  }


 }

 void USART1_RX_DMA_IRQ_Callback(void)
 {

	 /* Check transfer complete flag */
	   if(DMA_HISR_TCIF5 == (DMA_HISR_TCIF5 & DMA2->HISR))
	   {
	     /* Calculate amount of data received */
	     RxMessageLength = MAX_BUFFER_LENGTH - DMA2_Stream5->NDTR;

	     /* Copy data into RX buffer */
	     for(int idx = 0; idx < RxMessageLength; idx++)
	     {
	       RxBuffer[idx] = RxDMABuffer[idx];
	     }

	     /* Check error status */
	     if(USART1_NO_ERROR != currentErrorStatus)
	     {
	       /* Error detected, discard the received data */
	       RxMessageLength = 0;
	     }
	     else
	     {
	       /* No error detected */
	     }

	     /* Clear all interrupt flags */
	     DMA2->HIFCR = (DMA_HIFCR_CFEIF5 | DMA_HIFCR_CDMEIF5 | DMA_HIFCR_CTEIF5
	         | DMA_HIFCR_CHTIF5 | DMA_HIFCR_CTCIF5);

	     /* Enable DMA 2 stream 5 */
	     DMA2_Stream5->CR |= DMA_SxCR_EN;
	   }
	   else
	   {
	     /* Do nothing, this interrupt is not handled */
	   }


 }




/*
 * */

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
