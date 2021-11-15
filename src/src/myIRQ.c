/*******************************************************************************
 * @file    irq.c
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   Some IRQs examples using NVIC
 * @note
 *

*******************************************************************************/

/* Includes */
#include "myIRQ.h"
#include"myGPIO.h"


/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @defgroup irq
 * @brief
 * @{
 */

/**
 * @defgroup irq_private_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_variables
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_function_prototypes
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_private_functions
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_exported_functions
 * @{
 */

/**
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   None
 * @retval  None
 */
void IRQ_Init(void)
{
	  /* Set priority group to 3
	   * bits[3:0] are the sub-priority,
	   * bits[7:4] are the pre-empt priority */
	  myNVIC_SetPriorityGrouping(5);

	  /* Set priority levels */
	  myNVIC_SetPriority(SysTick_IRQn, 0,5);
	  myNVIC_SetPriority(EXTI0_IRQn, 1,5);
	  //NVIC_SetPriority(GREEN_LED_OFF_IRQ, 1);
	  //NVIC_SetPriority(RED_LED_OFF_IRQ,   2);

	  //NVIC_SetPriority(GREEN_LED_ON_IRQ,  3);
	  //NVIC_SetPriority(RED_LED_ON_IRQ,    4);

	  /* Enable interrupts at NVIC */
	  myNVIC_EnableIRQ(EXTI0_IRQn);

	  //NVIC_EnableIRQ(GREEN_LED_OFF_IRQ);
	  //NVIC_EnableIRQ(RED_LED_OFF_IRQ);

	  //NVIC_EnableIRQ(GREEN_LED_ON_IRQ);
	  //NVIC_EnableIRQ(RED_LED_ON_IRQ);
}












/**
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   IRQ number , priority group , priority
 * @retval  None
 */
void myNVIC_IRQ_Init(IRQn_Type IRQ_number ,u8 priorty_group ,u8 priority){

	  /* Set priority group to 3
	   * bits[3:0] are the sub-priority,
	   * bits[7:4] are the pre-empt priority */
	  myNVIC_SetPriorityGrouping(3);


	  /* Set priority levels */
	//  u8 NVIC_reg_number=IRQ_number/32;
	 // u8 NVIC_bit_number=IRQ_number-(NVIC_reg_number*32);



	  /* Set priority levels */

	  myNVIC_SetPriority(SysTick_IRQn, 0,priorty_group);
	  myNVIC_SetPriority(IRQ_number, priority,priorty_group);
	  /*
	  myNVIC_SetPriority(GREEN_LED_OFF_IRQ, 1,3);
	  myNVIC_SetPriority(RED_LED_OFF_IRQ,   2,3);

	  myNVIC_SetPriority(GREEN_LED_ON_IRQ,  3,3);
	  myNVIC_SetPriority(RED_LED_ON_IRQ,    4,3);
*/
	  /* Enable interrupts at NVIC */
	  myNVIC_EnableIRQ(IRQ_number);


/*	  myNVIC_EnableIRQ(GREEN_LED_OFF_IRQ);
	  myNVIC_EnableIRQ(RED_LED_OFF_IRQ);

	  myNVIC_EnableIRQ(GREEN_LED_ON_IRQ);
	 myNVIC_EnableIRQ(RED_LED_ON_IRQ);
*/



}




/** \brief  Set Priority Grouping

  The function sets the priority grouping field using the required unlock sequence.
  The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
  Only values from 0..7 are used.
  In case of a conflict between priority grouping and available
  priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set.

    \param [in]      PriorityGroup  Priority grouping field.
 */
 void myNVIC_SetPriorityGrouping(u32 PriorityGroup)
{
  u32 reg_value;
  u32 PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07);               /* only values 0..7 are used          */

  reg_value  =  SCB_AIRCR;                                               /* read old register configuration    */
  reg_value &= ~((SCB_AIRCR_VECTKEY_Msk) | (SCB_AIRCR_PRIGROUP_Msk));            			 /* clear bits to change               */
  reg_value  =  (reg_value             					   |
                ((uint32_t)0x5FA << SCB_AIRCR_VECTKEY_Pos) |
                (PriorityGroupTmp << 8));                                /* Insert write key and priorty group */
  SCB_AIRCR =  reg_value;
}


/** \brief  Get Priority Grouping

  The function reads the priority grouping field from the NVIC Interrupt Controller.

    \return                Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */
 u32 myyNVIC_GetPriorityGrouping(void)
{
  return ((SCB_AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos);   /* read priority grouping field */
}


/**
 * @brief   NVIC IRQs enable global interrupt function
 * @note
 * @param   None
 * @retval  None
 */
void myNVIC_Enable_GlobalIRQ(){} // Enables an interrupt or exception.




/**
 * @brief   NVIC IRQs disable global interrupt function
 * @note
 * @param   None
 * @retval  None
 */
void myNVIC_Disable_GlobalIRQ(){} // disables an interrupt or exception.



/** \brief  Enable External Interrupt

    The function enables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */

void myNVIC_EnableIRQ(IRQn_Type IRQn){
	  u8 NVIC_reg_number=IRQn/32;
	  u8 NVIC_bit_number=IRQn-(NVIC_reg_number*32);

	/*  NVIC->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  enable interrupt */
	  //NVIC->ISER[(uint32_t)((int32_t)IRQn) >> 5] = (uint32_t)(1 << ((uint32_t)((int32_t)IRQn) & (uint32_t)0x1F)); /* enable interrupt */
	  //NVIC->ISER[(uint32_t)((int32_t)IRQn) >> 5] = (uint32_t)(1 << ((uint32_t)((int32_t)IRQn) & (uint32_t)0x1F)); /* enable interrupt */

	  bit_word_addr_NVIC(NVIC_ISERX,NVIC_reg_number) |= (u32)(1 << ((u32)((u32)NVIC_bit_number))); /* enable interrupt */




} // Enables an interrupt or exception.




/** \brief  Disable External Interrupt

    The function disables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
 void myNVIC_DisableIRQ(IRQn_Type IRQn){}




 /** \brief  Get Pending Interrupt

     The function reads the pending register in the NVIC and returns the pending bit
     for the specified interrupt.

     \param [in]      IRQn  Interrupt number.

     \return             0  Interrupt status is not pending.
     \return             1  Interrupt status is pending.
  */
 uint32_t myNVIC_GetPendingIRQ(IRQn_Type IRQn){}


 /** \brief  Set Pending Interrupt

     The function sets the pending bit of an external interrupt.

     \param [in]      IRQn  Interrupt number. Value cannot be negative.
  */
 void myNVIC_SetPendingIRQ(IRQn_Type IRQn){


	  //NVIC->ISPR[((u32)(IRQn) >> 5)] = (1 << ((u32)(IRQn) & 0x1F)); /* set interrupt pending */
	  NVIC_PORT_ADDR(NVIC_ISPRX,IRQn) |=(1 << NVIC_BIT_ADDR(IRQn));



 }

 /** \brief  Clear Pending Interrupt

     The function clears the pending bit of an external interrupt.

     \param [in]      IRQn  External interrupt number. Value cannot be negative.
  */
 void myNVIC_ClearPendingIRQ(IRQn_Type IRQn){}




 /** \brief  Get Active Interrupt

     The function reads the active register in NVIC and returns the active bit.

     \param [in]      IRQn  Interrupt number.

     \return             0  Interrupt status is not active.
     \return             1  Interrupt status is active.
  */
  uint32_t myNVIC_GetActive(IRQn_Type IRQn){}



 /** \brief  Set Interrupt Priority

     The function sets the priority of an interrupt.

     \note The priority cannot be set for every core interrupt.

     \param [in]      IRQn  Interrupt number.
     \param [in]  priority  Priority to set.
  */
  void myNVIC_SetPriority(IRQn_Type IRQn, uint32_t priority,u8 priorty_group){

	  u8 NVIC_reg_number=IRQn/4;
	  u8 NVIC_bit_number=IRQn-(NVIC_reg_number*4);
	  //u32 hamo= ((NVIC_bit_number)*8);
	  //u32 hamo2= (u32)((u32)priority << ((((u32)NVIC_bit_number)*8)+sub_priority+1));
	  //0x100000
	  if(IRQn < 0) {
	      SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff); } /* set Priority for Cortex-M  System Interrupts */
	  else {
		    //NVIC->IP[(uint32_t)(IRQn)] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff);      /* set Priority for device specific Interrupts  */
		    //*(volatile u32 *) (0xE000E404)|=hamo2;
		    //bit_word_addr_NVIC(NVIC_IPR0,NVIC_reg_number) |= hamo2;
		    bit_word_addr_NVIC(NVIC_IPR0,NVIC_reg_number) |=(u32)((u32)priority << ((((u32)NVIC_bit_number)*8)+priorty_group+1));

	  	  	}
	  }        /* set Priority for device specific Interrupts  */


 /** \brief  Get Interrupt Priority

     The function reads the priority of an interrupt. The interrupt
     number can be positive to specify an external (device specific)
     interrupt, or negative to specify an internal (core) interrupt.


     \param [in]   IRQn  Interrupt number.
     \return             Interrupt Priority. Value is aligned automatically to the implemented
                         priority bits of the microcontroller.
  */
  uint32_t myNVIC_GetPriority(IRQn_Type IRQn){}




 /** \brief  Encode Priority

     The function encodes the priority for an interrupt with the given priority group,
     preemptive priority value, and subpriority value.
     In case of a conflict between priority grouping and available
     priority bits (__NVIC_PRIO_BITS), the samllest possible priority group is set.

     \param [in]     PriorityGroup  Used priority group.
     \param [in]   PreemptPriority  Preemptive priority value (starting from 0).
     \param [in]       SubPriority  Subpriority value (starting from 0).
     \return                        Encoded priority. Value can be used in the function \ref NVIC_SetPriority().
  */
  uint32_t myNVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority){}



 /** \brief  Decode Priority

     The function decodes an interrupt priority value with a given priority group to
     preemptive priority value and subpriority value.
     In case of a conflict between priority grouping and available
     priority bits (__NVIC_PRIO_BITS) the samllest possible priority group is set.

     \param [in]         Priority   Priority value, which can be retrieved with the function \ref NVIC_GetPriority().
     \param [in]     PriorityGroup  Used priority group.
     \param [out] pPreemptPriority  Preemptive priority value (starting from 0).
     \param [out]     pSubPriority  Subpriority value (starting from 0).
  */
  void myNVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority){}



 /** \brief  System Reset

     The function initiates a system reset request to reset the MCU.
  */
 __STATIC_INLINE void myNVIC_SystemReset(void){}


 /** \brief  Enable IRQ Interrupts

   This function enables IRQ interrupts by clearing the I-bit in the CPSR.
   Can only be executed in Privileged modes.
  */
 /* Clear PRIMASK, enable IRQs */

 __attribute__( ( always_inline ) ) __STATIC_INLINE void my_NVIC_Enable_irq(void)
 {
   __ASM volatile ("cpsie i" : : : "memory");
 }













 /******************************************************************************/
 /*                 STM32F4xx Peripherals Interrupt Handlers                   */
 /*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
 /*  available peripheral interrupt handler's name please refer to the startup */
 /*  file (startup_stm32f40xx.s/startup_stm32f427x.s).                         */
 /******************************************************************************/

 /**
   * @brief  This function handles EXTI0 interrupt request.
   * @param  None
   * @retval None
   */

/*
 void EXTI0_IRQHandler(void)
 {
 	  GPIO_OUT_VALUE(PORTG, 14 ,  HIGH );
 	  SysTick_Delay(500);
   //NVIC_SetPendingIRQ(GREEN_LED_OFF_IRQ);
 }

*/

 /**
   * @brief  This function handles EXTI1 interrupt request.
   * @param  None
   * @retval None
   */
/*
 void EXTI1_IRQHandler(void)
 {
 	  GPIO_OUT_VALUE(PORTG, 13 ,  HIGH );
   SysTick_Delay(500);
   //NVIC_SetPendingIRQ(RED_LED_ON_IRQ);
 }
*/

 /**
   * @brief  This function handles EXTI2 interrupt request.
   * @param  None
   * @retval None
   */
/*
 void EXTI2_IRQHandler(void)
 {
   GPIO_OUT_VALUE(PORTG, 14 ,  LOW );
   SysTick_Delay(500);
   //NVIC_SetPendingIRQ(RED_LED_OFF_IRQ);
 }
*/

 /**
   * @brief  This function handles EXTI3 interrupt request.
   * @param  None
   * @retval None
   */
/*
 void EXTI3_IRQHandler(void)
 {
	  GPIO_OUT_VALUE(PORTG, 13 ,  LOW );
   SysTick_Delay(500);
   //NVIC_SetPendingIRQ(GREEN_LED_ON_IRQ);
 }
*/



 /**
   * @}
   */


/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
