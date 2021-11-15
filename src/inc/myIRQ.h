/*******************************************************************************
 * @file    irq.h
 * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   Some IRQs examples using NVIC
 * @note
 *
*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef INC_MYIRQ_H_
#define INC_MYIRQ_H_


/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include "datatype.h"
#include "MACROS.h"
//#include "vector_table.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup irq
 * @{
 */

/**
 * @defgroup irq_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup irq_exported_defines
 * @{
 */







/**
 * @brief   Define addres of Registers offset OF NVIC (From CORTEX M4 DATASHEET)
 */
#define NVIC_ISERX		((u32)(0xE000E100)) //4.2.2 Interrupt Set-enable Registers
#define NVIC_ICERX		((u32)(0xE000E180))	//4.2.3 Interrupt Clear-enable Registers
#define NVIC_ISPRX		((u32)(0xE000E200)) //4.2.4 Interrupt Set-pending Registers
#define NVIC_ICPRX		((u32)(0xE000E280))	//4.2.5 Interrupt Clear-pending Registers
#define NVIC_IABRX		((u32)(0xE000E300))	//4.2.6 Interrupt Active Bit Registers
#define NVIC_IPR0		((u32)(0xE000E400))	//4.2.7 Interrupt Priority Registers
#define NVIC_STIR		((u32)(0xE000EF00)) //4.2.8 Software Trigger Interrupt Register




/**
 * @brief   Define addres of System control block Registers offset OF NVIC (IN system control block) (From CORTEX M4 DATASHEET)
 */

#define SCB_ICSR		*((volatile u32*)(0xE000ED04)) // Interrupt Control and State Register on page 4-13
#define SCB_VTOR		*((volatile u32*)(0xE000ED08)) // Vector Table Offset Register
#define SCB_AIRCR		*((volatile u32*)(0xE000ED0C)) // Application Interrupt and Reset Control Register
#define SCB_SHCRS		*((volatile u32*)(0xE000ED24)) // System Handler Control and State Register



/**
 * @brief   Define addres of CORE Registers  (IN Core register) (From CORTEX M4 DATASHEET)
 */
#define primask	//to activate general inturrupt
#define faultmask //


/**
 * @}
 */

/**
 * @defgroup irq_exported_macros
 * @{
 */

#define bit_word_addr_NVIC(port,offset)  *(volatile u32 *) (port + (offset *4))
#define NVIC_PORT_ADDR(port,IRQ_NUM)  *(volatile u32 *) (port+(u32)(IRQ_NUM>>5))
#define NVIC_BIT_ADDR(IRQ_NUM)  ((u32)(IRQn) & 0x1F)


/**
 * @}
 */

/**
 * @defgroup irq_exported_constants
 * @{
 */

/**
 * @brief   LEDs IRQs
 */
enum MyIRQs_e
{
  GREEN_LED_ON_IRQ = EXTI0_IRQn,    /*!< EVAL green LED ON interrupt          */
  GREEN_LED_OFF_IRQ = EXTI1_IRQn,   /*!< EVAL green LED OFF interrupt         */
  RED_LED_ON_IRQ = EXTI2_IRQn,      /*!< EVAL red LED ON interrupt            */
  RED_LED_OFF_IRQ = EXTI3_IRQn      /*!< EVAL red LED OFF interrupt           */
} MyIRQs;

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

void IRQ_Init(void);



/**
 *
 *
 * @brief   NVIC IRQs initialization function
 * @note
 * @param   None
 * @retval  None
 */
void myNVIC_IRQ_Init(IRQn_Type IRQ_number ,u8 priorty_group ,u8 priority);



/**
 * @brief   NVIC IRQs enable global interrupt function
 * @note
 * @param   None
 * @retval  None
 */
void myNVIC_Enable_GlobalIRQ(); // Enables an interrupt or exception.




/**
 * @brief   NVIC IRQs disable global interrupt function
 * @note
 * @param   None
 * @retval  None
 */
void myNVIC_Disable_GlobalIRQ(); // disables an interrupt or exception.






/** \brief  Set Priority Grouping

  The function sets the priority grouping field using the required unlock sequence.
  The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
  Only values from 0..7 are used.
  In case of a conflict between priority grouping and available
  priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set.

    \param [in]      PriorityGroup  Priority grouping field.
 */
 void myNVIC_SetPriorityGrouping(u32 PriorityGroup);


 /** \brief  Get Priority Grouping

   The function reads the priority grouping field from the NVIC Interrupt Controller.

     \return                Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
  */
  u32 myyNVIC_GetPriorityGrouping(void);




/** \brief  Enable External Interrupt

    The function enables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */

void myNVIC_EnableIRQ(IRQn_Type IRQn); // Enables an interrupt or exception.




/** \brief  Disable External Interrupt

    The function disables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
 void myNVIC_DisableIRQ(IRQn_Type IRQn);




 /** \brief  Get Pending Interrupt

     The function reads the pending register in the NVIC and returns the pending bit
     for the specified interrupt.

     \param [in]      IRQn  Interrupt number.

     \return             0  Interrupt status is not pending.
     \return             1  Interrupt status is pending.
  */
 uint32_t myNVIC_GetPendingIRQ(IRQn_Type IRQn);


 /** \brief  Set Pending Interrupt

     The function sets the pending bit of an external interrupt.

     \param [in]      IRQn  Interrupt number. Value cannot be negative.
  */
 void myNVIC_SetPendingIRQ(IRQn_Type IRQn);

 /** \brief  Clear Pending Interrupt

     The function clears the pending bit of an external interrupt.

     \param [in]      IRQn  External interrupt number. Value cannot be negative.
  */
 void myNVIC_ClearPendingIRQ(IRQn_Type IRQn);




 /** \brief  Get Active Interrupt

     The function reads the active register in NVIC and returns the active bit.

     \param [in]      IRQn  Interrupt number.

     \return             0  Interrupt status is not active.
     \return             1  Interrupt status is active.
  */
  uint32_t myNVIC_GetActive(IRQn_Type IRQn);



 /** \brief  Set Interrupt Priority

     The function sets the priority of an interrupt.

     \note The priority cannot be set for every core interrupt.

     \param [in]      IRQn  Interrupt number.
     \param [in]  priority  Priority to set.
     \param[in]		the priority groupin order to know the offset to put my priority
  */
  void myNVIC_SetPriority(IRQn_Type IRQn, uint32_t priority,u8 priorty_group);


 /** \brief  Get Interrupt Priority

     The function reads the priority of an interrupt. The interrupt
     number can be positive to specify an external (device specific)
     interrupt, or negative to specify an internal (core) interrupt.


     \param [in]   IRQn  Interrupt number.
     \return             Interrupt Priority. Value is aligned automatically to the implemented
                         priority bits of the microcontroller.
  */
  uint32_t myNVIC_GetPriority(IRQn_Type IRQn);




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
  uint32_t myNVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority);



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
  void myNVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);



 /** \brief  System Reset

     The function initiates a system reset request to reset the MCU.
  */
 __STATIC_INLINE void NVIC_SystemReset(void);

 /* Clear PRIMASK, enable IRQs */

 __attribute__( ( always_inline ) ) __STATIC_INLINE void my_NVIC_Enable_irq(void);



/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_IRQ_H_ */
