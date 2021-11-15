/*******************************************************************************
 * @file    rcc.h
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   RCC Examples
 * @note

*******************************************************************************/

/*					system reset notes
 *
 * 1) there is three types of resrt :- system,power,backup domain
 * 	and the subcategories to intiate reset is  a)low level on NRST pin (external reset)
 * 	b)window watchdog  reset				   c) independent watchdog reset
 * 	d)Software reset 						   e)Low-power mangment reset
 * 	we will deal with software reset and low prower reset only here
 *
 *
 *
 *
 *
 *
 * */








/* Define to prevent recursive inclusion */
#ifndef INC_MYRCC_H_
#define INC_MYRCC_H_


/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include "datatype.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup rcc
 * @{
 */

/**
 * @defgroup rcc_exported_typedefs
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_defines
 * @{
 */
///***************************RCC reset registers*******************///

//////////////////////////	cortex m4	registers

/**
 * @brief   this is System_control_block_Application_Interrupt_and_Reset_Control_Register
 * 			i am  using it to request software reaet
 */
#define SCB_AIRCR	*((volatile u32*)0xE000ED0C)

#define SCB_AIRCR_VECTKEY_Pos              16      /*!< SCB AIRCR: VECTKEY Position */


#define SCB_AIRCR_PRIGROUP_Pos              8                                             /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */


#define SCB_AIRCR_SYSRESETREQ_Pos           2                                             /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */







//////////////////////////	stm32f429	registers

/**
 * @brief   this is the register to detect the source of the reset
 * 			and to reset the source detection flag
 * @note 	i made it 16 bit because the first 16 bit has things about clock prepheral
 */
#define RCC_clock_control_status_register	*((volatile u16*)0x40023876) // $$$ error expectation

/********************  Bit definition for RCC_CSR register  *******************/


#define  RCC_CSR_RMVF                        ((u16)0x0100)
#define  RCC_CSR_BORRSTF                     ((u16)0x0200)
#define  RCC_CSR_PADRSTF                     ((u16)0x0400)
#define  RCC_CSR_PORRSTF                     ((u16)0x0800)
#define  RCC_CSR_SFTRSTF                     ((u16)0x1000)
#define  RCC_CSR_WDGRSTF                     ((u16)0x2000)
#define  RCC_CSR_WWDGRSTF                    ((u16)0x4000)
#define  RCC_CSR_LPWRRSTF                    ((u16)0x8000)


/**
 * @}
 */

/**
 * @defgroup rcc_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup rcc_exported_functions
 * @{
 */
////************************************************Reset functions**************************///

/**
 * @brief   Perform system reset
 * @note
 * @param   None
 * @retval  None
 */
void RCC_SystemReset(void);
/**
 * @brief   Detect system reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_DetectResetSource(void);

/**
 * @brief   Turn on LEDs based on reset source
 * @note
 * @param   None
 * @retval  None
 */
void RCC_ProcessReset(void);


////************************************************Clock functions**************************///

void RCC_ClockOut_Setup(void);

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


#endif /* INC_MYRCC_H_ */
