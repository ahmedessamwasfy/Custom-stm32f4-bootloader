/*
 * Timer_regesters.h
 *
 *  Created on: Jul 24, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_TIMER_REGESTERS_H_
#define INC_TIMER_REGESTERS_H_




#include "Std_Types.h"

/* ==================================================================== */
/* ========================== RCC Regesters =========================== */
/* ==================================================================== */



/********************   RCC_APB1ENR register  ***************/


#define  RCC_APB1ENR                 *((volatile uint32 *)(0x40203840))


#define  RCC_APB1ENR_TIM2EN                  ((uint32)0x00000001)
#define  RCC_APB1ENR_TIM3EN                  ((uint32)0x00000002)
#define  RCC_APB1ENR_TIM4EN                  ((uint32)0x00000004)
#define  RCC_APB1ENR_TIM5EN                  ((uint32)0x00000008)
#define  RCC_APB1ENR_TIM6EN                  ((uint32)0x00000010)
#define  RCC_APB1ENR_TIM7EN                  ((uint32)0x00000020)
#define  RCC_APB1ENR_TIM12EN                 ((uint32)0x00000040)
#define  RCC_APB1ENR_TIM13EN                 ((uint32)0x00000080)
#define  RCC_APB1ENR_TIM14EN                 ((uint32)0x00000100)


/********************   RCC_APB2ENR register  ***************/

#define  RCC_APB2ENR                 *((volatile uint32 *)(0x40203844))

#define  RCC_APB2ENR_TIM1EN                  ((uint32)0x00000001)
#define  RCC_APB2ENR_TIM8EN                  ((uint32)0x00000002)
#define  RCC_APB2ENR_TIM9EN                  ((uint32)0x00010000)
#define  RCC_APB2ENR_TIM10EN                 ((uint32)0x00020000)
#define  RCC_APB2ENR_TIM11EN                 ((uint32)0x00040000)

/* ==================================================================== */
/* ========================== Timer Regesters =========================== */
/* ==================================================================== */


/**
  * @brief TIMER Bases
  */
#define APB1PERIPH_BASE       ((uint32)0x40000000)

#define TIM3_BASE            (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000)

#define APB1PERIPH_BASE       ((uint32)0x40010000)

#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800)


/**
  * @brief TIMER offsets for all timers
  */

#define	TIMERx_CR1      0x00    /*!< TIM control register 1,              Address offset: 0x00 */

#define TIMERx_CR2      0x04    /*!< TIM control register 2,              Address offset: 0x04 */

#define TIMERx_SMCR     0x08    /*!< TIM slave mode control register,     Address offset: 0x08 */

#define TIMERx_DIER     0x0C    /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */

#define TIMERx_SR       0x10    /*!< TIM status register,                 Address offset: 0x10 */

#define TIMERx_EGR      0x14    /*!< TIM event generation register,       Address offset: 0x14 */

#define TIMERx_CCMR1    0x18    /*!< TIM capture/compare mode register 1, Address offset: 0x18 */

#define TIMERx_CCMR2    0x1C    /*!< TIM capture/compare mode register 2, Address offset: 0x1C */

#define TIMERx_CCER     0x20    /*!< TIM capture/compare enable register, Address offset: 0x20 */

#define TIMERx_CNT      0x24    /*!< TIM counter register,                Address offset: 0x24 */

#define TIMERx_PSC      0x28    /*!< TIM prescaler,                       Address offset: 0x28 */


#define TIMERx_ARR      0x2C    /*!< TIM auto-reload register,            Address offset: 0x2C */  //u32

#define TIMERx_RCR      0x30    /*!< TIM repetition counter register,     Address offset: 0x30 */

#define TIMERx_CCR1     0x34    /*!< TIM capture/compare register 1,      Address offset: 0x34 */ //u32

#define TIMERx_CCR2     0x38    /*!< TIM capture/compare register 2,      Address offset: 0x38 */	//u32

#define TIMERx_CCR3     0x3C    /*!< TIM capture/compare register 3,      Address offset: 0x3C */	//u32

#define TIMERx_CCR4     0x40    /*!< TIM capture/compare register 4,      Address offset: 0x40 */	//u32

#define TIMERx_BDTR     0x44    /*!< TIM break and dead-time register,    Address offset: 0x44 */

#define TIMERx_DCR      0x48    /*!< TIM DMA control register,            Address offset: 0x48 */

#define TIMERx_DMAR     0x4C    /*!< TIM DMA address for full transfer,   Address offset: 0x4C */

#define TIMERx_OR       0x50    /*!< TIM option register,                 Address offset: 0x50 */



/**
  * @brief Each Timer registers
  */

/******************************	TIMER 1	**********************/

#define	TIMER1_CR1 		*((volatile uint32*)(TIMERx_CR1+TIM1_BASE))
#define	TIMER1_CR2 		*((volatile uint32*)(TIMERx_CR2+TIM1_BASE))
#define	TIMER1_SMCR 	*((volatile uint32*)(TIMERx_SMCR+TIM1_BASE))
#define	TIMER1_DIER 	*((volatile uint32*)(TIMERx_DIER+TIM1_BASE))
#define	TIMER1_SR 		*((volatile uint32*)(TIMERx_SR+TIM1_BASE))
#define	TIMER1_EGR 		*((volatile uint32*)(TIMERx_EGR+TIM1_BASE))
#define	TIMER1_CCMR1 	*((volatile uint32*)(TIMERx_CCMR1 +TIM1_BASE))
#define	TIMER1_CCMR2 	*((volatile uint32*)(TIMERx_CCMR2 +TIM1_BASE))
#define	TIMER1_CCER 	*((volatile uint32*)(TIMERx_CCER+TIM1_BASE))
#define	TIMER1_CNT 		*((volatile uint32*)(TIMERx_CNT+TIM1_BASE))
#define	TIMER1_PSC 		*((volatile uint32*)(TIMERx_PSC+TIM1_BASE))
#define	TIMER1_ARR 		*((volatile uint32*)(TIMERx_ARR+TIM1_BASE))
#define	TIMER1_RCR 		*((volatile uint32*)(TIMERx_RCR+TIM1_BASE))
#define	TIMER1_CCR1 	*((volatile uint32*)(TIMERx_CCR1+TIM1_BASE))
#define	TIMER1_CCR2 	*((volatile uint32*)(TIMERx_CCR2+TIM1_BASE))
#define	TIMER1_CCR3 	*((volatile uint32*)(TIMERx_CCR3+TIM1_BASE))
#define	TIMER1_CCR4 	*((volatile uint32*)(TIMERx_CCR4+TIM1_BASE))
#define	TIMER1_BDTR 	*((volatile uint32*)(TIMERx_BDTR+TIM1_BASE))
#define	TIMER1_DCR  	*((volatile uint32*)(TIMERx_DCR+TIM1_BASE))
#define	TIMER1_DMAR  	*((volatile uint32*)(TIMERx_DMAR+TIM1_BASE))


/******************************	TIMER 2	**********************/

#define	TIMER2_CR1 		*((volatile uint32*)(TIMERx_CR1+TIM3_BASE))
#define	TIMER2_CR2 		*((volatile uint32*)(TIMERx_CR2+TIM3_BASE))
#define	TIMER2_SMCR 	*((volatile uint32*)(TIMERx_SMCR+TIM3_BASE))
#define	TIMER2_DIER 	*((volatile uint32*)(TIMERx_DIER+TIM3_BASE))
#define	TIMER2_SR 		*((volatile uint32*)(TIMERx_SR+TIM3_BASE))
#define	TIMER2_EGR 		*((volatile uint32*)(TIMERx_EGR+TIM3_BASE))
#define	TIMER2_CCMR1 	*((volatile uint32*)(TIMERx_CCMR1 +TIM3_BASE))
#define	TIMER2_CCMR2 	*((volatile uint32*)(TIMERx_CCMR2 +TIM3_BASE))
#define	TIMER2_CCER 	*((volatile uint32*)(TIMERx_CCER+TIM3_BASE))
#define	TIMER2_CNT 		*((volatile uint32*)(TIMERx_CNT+TIM3_BASE))
#define	TIMER2_PSC 		*((volatile uint32*)(TIMERx_PSC+TIM3_BASE))
#define	TIMER2_ARR 		*((volatile uint32*)(TIMERx_ARR+TIM3_BASE))
#define	TIMER2_RCR 		*((volatile uint32*)(TIMERx_RCR+TIM3_BASE))
#define	TIMER2_CCR1 	*((volatile uint32*)(TIMERx_CCR1+TIM3_BASE))
#define	TIMER2_CCR2 	*((volatile uint32*)(TIMERx_CCR2+TIM3_BASE))
#define	TIMER2_CCR3 	*((volatile uint32*)(TIMERx_CCR3+TIM3_BASE))
#define	TIMER2_CCR4 	*((volatile uint32*)(TIMERx_CCR4+TIM3_BASE))
#define	TIMER2_BDTR 	*((volatile uint32*)(TIMERx_BDTR+TIM3_BASE))
#define	TIMER2_DCR  	*((volatile uint32*)(TIMERx_DCR+TIM3_BASE))
#define	TIMER2_DMAR  	*((volatile uint32*)(TIMERx_DMAR+TIM3_BASE))
#define	TIMER2_OR  		*((volatile uint32*)(TIMERx_OR+TIM3_BASE))



/******************************	TIMER 3	**********************/

#define	TIMER3_CR1 		*((volatile uint32*)(TIMERx_CR1+TIM3_BASE))
#define	TIMER3_CR2 		*((volatile uint32*)(TIMERx_CR2+TIM3_BASE))
#define	TIMER3_SMCR 	*((volatile uint32*)(TIMERx_SMCR+TIM3_BASE))
#define	TIMER3_DIER 	*((volatile uint32*)(TIMERx_DIER+TIM3_BASE))
#define	TIMER3_SR 		*((volatile uint32*)(TIMERx_SR+TIM3_BASE))
#define	TIMER3_EGR 		*((volatile uint32*)(TIMERx_EGR+TIM3_BASE))
#define	TIMER3_CCMR1 	*((volatile uint32*)(TIMERx_CCMR1 +TIM3_BASE))
#define	TIMER3_CCMR2 	*((volatile uint32*)(TIMERx_CCMR2 +TIM3_BASE))
#define	TIMER3_CCER 	*((volatile uint32*)(TIMERx_CCER+TIM3_BASE))
#define	TIMER3_CNT 		*((volatile uint32*)(TIMERx_CNT+TIM3_BASE))
#define	TIMER3_PSC 		*((volatile uint32*)(TIMERx_PSC+TIM3_BASE))
#define	TIMER3_ARR 		*((volatile uint32*)(TIMERx_ARR+TIM3_BASE))
#define	TIMER3_RCR 		*((volatile uint32*)(TIMERx_RCR+TIM3_BASE))
#define	TIMER3_CCR1 	*((volatile uint32*)(TIMERx_CCR1+TIM3_BASE))
#define	TIMER3_CCR2 	*((volatile uint32*)(TIMERx_CCR2+TIM3_BASE))
#define	TIMER3_CCR3 	*((volatile uint32*)(TIMERx_CCR3+TIM3_BASE))
#define	TIMER3_CCR4 	*((volatile uint32*)(TIMERx_CCR4+TIM3_BASE))
#define	TIMER3_BDTR 	*((volatile uint32*)(TIMERx_BDTR+TIM3_BASE))
#define	TIMER3_DCR  	*((volatile uint32*)(TIMERx_DCR+TIM3_BASE))
#define	TIMER3_DMAR  	*((volatile uint32*)(TIMERx_DMAR+TIM3_BASE))
#define	TIMER3_OR  		*((volatile uint32*)(TIMERx_OR+TIM3_BASE))


/******************************	TIMER 4	**********************/

#define	TIMER4_CR1 		*((volatile uint32*)(TIMERx_CR1+TIM4_BASE))
#define	TIMER4_CR2 		*((volatile uint32*)(TIMERx_CR2+TIM4_BASE))
#define	TIMER4_SMCR 	*((volatile uint32*)(TIMERx_SMCR+TIM4_BASE))
#define	TIMER4_DIER 	*((volatile uint32*)(TIMERx_DIER+TIM4_BASE))
#define	TIMER4_SR 		*((volatile uint32*)(TIMERx_SR+TIM4_BASE))
#define	TIMER4_EGR 		*((volatile uint32*)(TIMERx_EGR+TIM4_BASE))
#define	TIMER4_CCMR1 	*((volatile uint32*)(TIMERx_CCMR1 +TIM4_BASE))
#define	TIMER4_CCMR2 	*((volatile uint32*)(TIMERx_CCMR2 +TIM4_BASE))
#define	TIMER4_CCER 	*((volatile uint32*)(TIMERx_CCER+TIM4_BASE))
#define	TIMER4_CNT 		*((volatile uint32*)(TIMERx_CNT+TIM4_BASE))
#define	TIMER4_PSC 		*((volatile uint32*)(TIMERx_PSC+TIM4_BASE))
#define	TIMER4_ARR 		*((volatile uint32*)(TIMERx_ARR+TIM4_BASE))
#define	TIMER4_RCR 		*((volatile uint32*)(TIMERx_RCR+TIM4_BASE))
#define	TIMER4_CCR1 	*((volatile uint32*)(TIMERx_CCR1+TIM4_BASE))
#define	TIMER4_CCR2 	*((volatile uint32*)(TIMERx_CCR2+TIM4_BASE))
#define	TIMER4_CCR3 	*((volatile uint32*)(TIMERx_CCR3+TIM4_BASE))
#define	TIMER4_CCR4 	*((volatile uint32*)(TIMERx_CCR4+TIM4_BASE))
#define	TIMER4_BDTR 	*((volatile uint32*)(TIMERx_BDTR+TIM4_BASE))
#define	TIMER4_DCR  	*((volatile uint32*)(TIMERx_DCR+TIM4_BASE))
#define	TIMER4_DMAR  	*((volatile uint32*)(TIMERx_DMAR+TIM4_BASE))
#define	TIMER4_OR  		*((volatile uint32*)(TIMERx_OR+TIM4_BASE))


/******************************	TIMER 6	**********************/

#define	TIMER6_CR1 		*((volatile uint32*)(TIMERx_CR1+TIM6_BASE))
#define	TIMER6_CR2 		*((volatile uint32*)(TIMERx_CR2+TIM6_BASE))
#define	TIMER6_DIER 	*((volatile uint32*)(TIMERx_DIER+TIM6_BASE))
#define	TIMER6_SR 		*((volatile uint32*)(TIMERx_SR+TIM6_BASE))
#define	TIMER6_EGR 		*((volatile uint32*)(TIMERx_EGR+TIM6_BASE))
#define	TIMER6_CNT 		*((volatile uint32*)(TIMERx_CNT+TIM6_BASE))
#define	TIMER6_PSC 		*((volatile uint32*)(TIMERx_PSC+TIM6_BASE))
#define	TIMER6_ARR 		*((volatile uint32*)(TIMERx_ARR+TIM6_BASE))




/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define  TIM_CR1_CEN                         ((uint16)0x0001)            /*!<Counter enable        */
#define  TIM_CR1_UDIS                        ((uint16)0x0002)            /*!<Update disable        */
#define  TIM_CR1_URS                         ((uint16)0x0004)            /*!<Update request source */
#define  TIM_CR1_OPM                         ((uint16)0x0008)            /*!<One pulse mode        */
#define  TIM_CR1_DIR                         ((uint16)0x0010)            /*!<Direction             */

#define  TIM_CR1_CMS                         ((uint16)0x0060)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((uint16)0x0020)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       ((uint16)0x0040)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        ((uint16)0x0080)            /*!<Auto-reload preload enable     */

#define  TIM_CR1_CKD                         ((uint16)0x0300)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       ((uint16)0x0200)            /*!<Bit 1 */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define  TIM_CR2_CCPC                        ((uint16)0x0001)            /*!<Capture/Compare Preloaded Control        */
#define  TIM_CR2_CCUS                        ((uint16)0x0004)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        ((uint16)0x0008)            /*!<Capture/Compare DMA Selection            */

#define  TIM_CR2_MMS                         ((uint16)0x0070)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       ((uint16)0x0040)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        ((uint16)0x0080)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        ((uint16)0x0100)            /*!<Output Idle state 1 (OC1 output)  */
#define  TIM_CR2_OIS1N                       ((uint16)0x0200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        ((uint16)0x0400)            /*!<Output Idle state 2 (OC2 output)  */
#define  TIM_CR2_OIS2N                       ((uint16)0x0800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        ((uint16)0x1000)            /*!<Output Idle state 3 (OC3 output)  */
#define  TIM_CR2_OIS3N                       ((uint16)0x2000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        ((uint16)0x4000)            /*!<Output Idle state 4 (OC4 output)  */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define  TIM_SMCR_SMS                        ((uint16)0x0007)            /*!<SMS[2:0] bits (Slave mode selection)    */
#define  TIM_SMCR_SMS_0                      ((uint16)0x0001)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      ((uint16)0x0002)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      ((uint16)0x0004)            /*!<Bit 2 */

#define  TIM_SMCR_TS                         ((uint16)0x0070)            /*!<TS[2:0] bits (Trigger selection)        */
#define  TIM_SMCR_TS_0                       ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       ((uint16)0x0040)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        ((uint16)0x0080)            /*!<Master/slave mode                       */

#define  TIM_SMCR_ETF                        ((uint16)0x0F00)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      ((uint16)0x0200)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      ((uint16)0x0400)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      ((uint16)0x0800)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       ((uint16)0x3000)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     ((uint16)0x1000)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     ((uint16)0x2000)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        ((uint16)0x4000)            /*!<External clock enable     */
#define  TIM_SMCR_ETP                        ((uint16)0x8000)            /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define  TIM_DIER_UIE                        ((uint16)0x0001)            /*!<Update interrupt enable */
#define  TIM_DIER_CC1IE                      ((uint16)0x0002)            /*!<Capture/Compare 1 interrupt enable   */
#define  TIM_DIER_CC2IE                      ((uint16)0x0004)            /*!<Capture/Compare 2 interrupt enable   */
#define  TIM_DIER_CC3IE                      ((uint16)0x0008)            /*!<Capture/Compare 3 interrupt enable   */
#define  TIM_DIER_CC4IE                      ((uint16)0x0010)            /*!<Capture/Compare 4 interrupt enable   */
#define  TIM_DIER_COMIE                      ((uint16)0x0020)            /*!<COM interrupt enable                 */
#define  TIM_DIER_TIE                        ((uint16)0x0040)            /*!<Trigger interrupt enable             */
#define  TIM_DIER_BIE                        ((uint16)0x0080)            /*!<Break interrupt enable               */
#define  TIM_DIER_UDE                        ((uint16)0x0100)            /*!<Update DMA request enable            */
#define  TIM_DIER_CC1DE                      ((uint16)0x0200)            /*!<Capture/Compare 1 DMA request enable */
#define  TIM_DIER_CC2DE                      ((uint16)0x0400)            /*!<Capture/Compare 2 DMA request enable */
#define  TIM_DIER_CC3DE                      ((uint16)0x0800)            /*!<Capture/Compare 3 DMA request enable */
#define  TIM_DIER_CC4DE                      ((uint16)0x1000)            /*!<Capture/Compare 4 DMA request enable */
#define  TIM_DIER_COMDE                      ((uint16)0x2000)            /*!<COM DMA request enable               */
#define  TIM_DIER_TDE                        ((uint16)0x4000)            /*!<Trigger DMA request enable           */

/********************  Bit definition for TIM_SR register  ********************/
#define  TIM_SR_UIF                          ((uint16)0x0001)            /*!<Update interrupt Flag              */
#define  TIM_SR_CC1IF                        ((uint16)0x0002)            /*!<Capture/Compare 1 interrupt Flag   */
#define  TIM_SR_CC2IF                        ((uint16)0x0004)            /*!<Capture/Compare 2 interrupt Flag   */
#define  TIM_SR_CC3IF                        ((uint16)0x0008)            /*!<Capture/Compare 3 interrupt Flag   */
#define  TIM_SR_CC4IF                        ((uint16)0x0010)            /*!<Capture/Compare 4 interrupt Flag   */
#define  TIM_SR_COMIF                        ((uint16)0x0020)            /*!<COM interrupt Flag                 */
#define  TIM_SR_TIF                          ((uint16)0x0040)            /*!<Trigger interrupt Flag             */
#define  TIM_SR_BIF                          ((uint16)0x0080)            /*!<Break interrupt Flag               */
#define  TIM_SR_CC1OF                        ((uint16)0x0200)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIM_SR_CC2OF                        ((uint16)0x0400)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIM_SR_CC3OF                        ((uint16)0x0800)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIM_SR_CC4OF                        ((uint16)0x1000)            /*!<Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define  TIM_EGR_UG                          ((uint8)0x01)               /*!<Update Generation                         */
#define  TIM_EGR_CC1G                        ((uint8)0x02)               /*!<Capture/Compare 1 Generation              */
#define  TIM_EGR_CC2G                        ((uint8)0x04)               /*!<Capture/Compare 2 Generation              */
#define  TIM_EGR_CC3G                        ((uint8)0x08)               /*!<Capture/Compare 3 Generation              */
#define  TIM_EGR_CC4G                        ((uint8)0x10)               /*!<Capture/Compare 4 Generation              */
#define  TIM_EGR_COMG                        ((uint8)0x20)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          ((uint8)0x40)               /*!<Trigger Generation                        */
#define  TIM_EGR_BG                          ((uint8)0x80)               /*!<Break Generation                          */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define  TIM_CCMR1_CC1S                      ((uint16)0x0003)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    ((uint16)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    ((uint16)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     ((uint16)0x0004)            /*!<Output Compare 1 Fast enable                 */
#define  TIM_CCMR1_OC1PE                     ((uint16)0x0008)            /*!<Output Compare 1 Preload enable              */

#define  TIM_CCMR1_OC1M                      ((uint16)0x0070)            /*!<OC1M[2:0] bits (Output Compare 1 Mode)       */
#define  TIM_CCMR1_OC1M_0                    ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    ((uint16)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR1_OC1CE                     ((uint16)0x0080)            /*!<Output Compare 1Clear Enable                 */

#define  TIM_CCMR1_CC2S                      ((uint16)0x0300)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    ((uint16)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     ((uint16)0x0400)            /*!<Output Compare 2 Fast enable                 */
#define  TIM_CCMR1_OC2PE                     ((uint16)0x0800)            /*!<Output Compare 2 Preload enable              */

#define  TIM_CCMR1_OC2M                      ((uint16)0x7000)            /*!<OC2M[2:0] bits (Output Compare 2 Mode)       */
#define  TIM_CCMR1_OC2M_0                    ((uint16)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    ((uint16)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    ((uint16)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR1_OC2CE                     ((uint16)0x8000)            /*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR1_IC1PSC                    ((uint16)0x000C)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  ((uint16)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  ((uint16)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      ((uint16)0x00F0)            /*!<IC1F[3:0] bits (Input Capture 1 Filter)      */
#define  TIM_CCMR1_IC1F_0                    ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    ((uint16)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    ((uint16)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    ((uint16)0x0C00)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler)  */
#define  TIM_CCMR1_IC2PSC_0                  ((uint16)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  ((uint16)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      ((uint16)0xF000)            /*!<IC2F[3:0] bits (Input Capture 2 Filter)       */
#define  TIM_CCMR1_IC2F_0                    ((uint16)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    ((uint16)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    ((uint16)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    ((uint16)0x8000)            /*!<Bit 3 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define  TIM_CCMR2_CC3S                      ((uint16)0x0003)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection)  */
#define  TIM_CCMR2_CC3S_0                    ((uint16)0x0001)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    ((uint16)0x0002)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     ((uint16)0x0004)            /*!<Output Compare 3 Fast enable           */
#define  TIM_CCMR2_OC3PE                     ((uint16)0x0008)            /*!<Output Compare 3 Preload enable        */

#define  TIM_CCMR2_OC3M                      ((uint16)0x0070)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    ((uint16)0x0040)            /*!<Bit 2 */

#define  TIM_CCMR2_OC3CE                     ((uint16)0x0080)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      ((uint16)0x0300)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    ((uint16)0x0200)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     ((uint16)0x0400)            /*!<Output Compare 4 Fast enable    */
#define  TIM_CCMR2_OC4PE                     ((uint16)0x0800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      ((uint16)0x7000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    ((uint16)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    ((uint16)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    ((uint16)0x4000)            /*!<Bit 2 */

#define  TIM_CCMR2_OC4CE                     ((uint16)0x8000)            /*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR2_IC3PSC                    ((uint16)0x000C)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  ((uint16)0x0004)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  ((uint16)0x0008)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      ((uint16)0x00F0)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    ((uint16)0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    ((uint16)0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    ((uint16)0x0040)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    ((uint16)0x0080)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    ((uint16)0x0C00)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  ((uint16)0x0400)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  ((uint16)0x0800)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      ((uint16)0xF000)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    ((uint16)0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    ((uint16)0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    ((uint16)0x4000)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    ((uint16)0x8000)            /*!<Bit 3 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define  TIM_CCER_CC1E                       ((uint16)0x0001)            /*!<Capture/Compare 1 output enable                 */
#define  TIM_CCER_CC1P                       ((uint16)0x0002)            /*!<Capture/Compare 1 output Polarity               */
#define  TIM_CCER_CC1NE                      ((uint16)0x0004)            /*!<Capture/Compare 1 Complementary output enable   */
#define  TIM_CCER_CC1NP                      ((uint16)0x0008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       ((uint16)0x0010)            /*!<Capture/Compare 2 output enable                 */
#define  TIM_CCER_CC2P                       ((uint16)0x0020)            /*!<Capture/Compare 2 output Polarity               */
#define  TIM_CCER_CC2NE                      ((uint16)0x0040)            /*!<Capture/Compare 2 Complementary output enable   */
#define  TIM_CCER_CC2NP                      ((uint16)0x0080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       ((uint16)0x0100)            /*!<Capture/Compare 3 output enable                 */
#define  TIM_CCER_CC3P                       ((uint16)0x0200)            /*!<Capture/Compare 3 output Polarity               */
#define  TIM_CCER_CC3NE                      ((uint16)0x0400)            /*!<Capture/Compare 3 Complementary output enable   */
#define  TIM_CCER_CC3NP                      ((uint16)0x0800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       ((uint16)0x1000)            /*!<Capture/Compare 4 output enable                 */
#define  TIM_CCER_CC4P                       ((uint16)0x2000)            /*!<Capture/Compare 4 output Polarity               */
#define  TIM_CCER_CC4NP                      ((uint16)0x8000)            /*!<Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIM_CNT register  ********************/
#define  TIM_CNT_CNT                         ((uint16)0xFFFF)            /*!<Counter Value            */

/*******************  Bit definition for TIM_PSC register  ********************/
#define  TIM_PSC_PSC                         ((uint16)0xFFFF)            /*!<Prescaler Value          */

/*******************  Bit definition for TIM_ARR register  ********************/
#define  TIM_ARR_ARR                         ((uint16)0xFFFF)            /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define  TIM_RCR_REP                         ((uint8_t)0xFF)               /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define  TIM_CCR1_CCR1                       ((uint16)0xFFFF)            /*!<Capture/Compare 1 Value  */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define  TIM_CCR2_CCR2                       ((uint16)0xFFFF)            /*!<Capture/Compare 2 Value  */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define  TIM_CCR3_CCR3                       ((uint16)0xFFFF)            /*!<Capture/Compare 3 Value  */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define  TIM_CCR4_CCR4                       ((uint16)0xFFFF)            /*!<Capture/Compare 4 Value  */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define  TIM_BDTR_DTG                        ((uint16)0x00FF)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      ((uint16)0x0001)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      ((uint16)0x0002)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      ((uint16)0x0004)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      ((uint16)0x0008)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      ((uint16)0x0010)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      ((uint16)0x0020)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      ((uint16)0x0040)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      ((uint16)0x0080)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       ((uint16)0x0300)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     ((uint16)0x0200)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       ((uint16)0x0400)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       ((uint16)0x0800)            /*!<Off-State Selection for Run mode  */
#define  TIM_BDTR_BKE                        ((uint16)0x1000)            /*!<Break enable                      */
#define  TIM_BDTR_BKP                        ((uint16)0x2000)            /*!<Break Polarity                    */
#define  TIM_BDTR_AOE                        ((uint16)0x4000)            /*!<Automatic Output enable           */
#define  TIM_BDTR_MOE                        ((uint16)0x8000)            /*!<Main Output enable                */

/*******************  Bit definition for TIM_DCR register  ********************/
#define  TIM_DCR_DBA                         ((uint16)0x001F)            /*!<DBA[4:0] bits (DMA Base Address) */
#define  TIM_DCR_DBA_0                       ((uint16)0x0001)            /*!<Bit 0 */
#define  TIM_DCR_DBA_1                       ((uint16)0x0002)            /*!<Bit 1 */
#define  TIM_DCR_DBA_2                       ((uint16)0x0004)            /*!<Bit 2 */
#define  TIM_DCR_DBA_3                       ((uint16)0x0008)            /*!<Bit 3 */
#define  TIM_DCR_DBA_4                       ((uint16)0x0010)            /*!<Bit 4 */

#define  TIM_DCR_DBL                         ((uint16)0x1F00)            /*!<DBL[4:0] bits (DMA Burst Length) */
#define  TIM_DCR_DBL_0                       ((uint16)0x0100)            /*!<Bit 0 */
#define  TIM_DCR_DBL_1                       ((uint16)0x0200)            /*!<Bit 1 */
#define  TIM_DCR_DBL_2                       ((uint16)0x0400)            /*!<Bit 2 */
#define  TIM_DCR_DBL_3                       ((uint16)0x0800)            /*!<Bit 3 */
#define  TIM_DCR_DBL_4                       ((uint16)0x1000)            /*!<Bit 4 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define  TIM_DMAR_DMAB                       ((uint16)0xFFFF)            /*!<DMA register for burst accesses                    */

/*******************  Bit definition for TIM_OR register  *********************/
#define TIM_OR_TI4_RMP                       ((uint16)0x00C0)            /*!<TI4_RMP[1:0] bits (TIM5 Input 4 remap)             */
#define TIM_OR_TI4_RMP_0                     ((uint16)0x0040)            /*!<Bit 0 */
#define TIM_OR_TI4_RMP_1                     ((uint16)0x0080)            /*!<Bit 1 */
#define TIM_OR_ITR1_RMP                      ((uint16)0x0C00)            /*!<ITR1_RMP[1:0] bits (TIM2 Internal trigger 1 remap) */
#define TIM_OR_ITR1_RMP_0                    ((uint16)0x0400)            /*!<Bit 0 */
#define TIM_OR_ITR1_RMP_1                    ((uint16)0x0800)            /*!<Bit 1 */



/**
  * @brief enum and typedef of all the regusters components
  */



/******************************TIMERx_CR1*********************TIM control register 1, Address offset: 0x00 ****************/
/**
  * @brief it's a flag and/or innterrupt hapens when the data reach it's end
  * 		so we can enable this UEV or disable it
  *
  * @state  Update event enable
  * 	    Update event disable
  */
typedef enum{
	UEV_Enable,
	UEV_Disable
}UDIS_update_state;






/**
  * @brief 	this bit is set to selct the UEV event sources
  * 				1.counter overflow/underflow
  * 				2.setting the UG bit
  * 				3.Update generation
  * 		OR for overflow/underflow or dma request only
  *
  * @state  0.Update event source all for counter over/underflow
  * 		setting UG bit,or update generation
  *
  * 	    1.the event source is for  overflow/underflow or dma request only
  */
typedef enum{
	URS_Source_all,
	URS_Source_OUF
}URS_update_request_source;



/**
  * @brief 	this bit is set to selct the UEV event sources
  * @bit number		bit 3
  * @state  0: Counter is not stopped at update event
  *			1: Counter stops counting at the next update event (clearing the bit CEN)
  */
typedef enum{
	OPM_Enable,
	OPM_Disable
}OPM_one_pulse_mode;



/**
  * @brief 	this bit is set to selct the UEV event sources
  * @bit number		bit 4
  * @state  0: Counter is not stopped at update event
  *			1: Counter stops counting at the next update event (clearing the bit CEN)
  */
typedef enum{
	Upcount,
	Downcount
}DIR_direction;



/**
  * @brief
  * @bit number		bit 5:6
  * @state  00: Edge-aligned mode. The counter counts up or down depending on the direction bit
				(DIR).

			01: Center-aligned mode 1. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			only when the counter is counting down.

			10: Center-aligned mode 2. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			only when the counter is counting up.

			11: Center-aligned mode 3. The counter counts up and down alternatively. Output compare
			interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
			both when the counter is counting up or down.
*/
typedef enum{
	Cemter_aligned_Disable,
	Center_aligned_mode_1,
	Center_aligned_mode_2,
	Center_alinged_mode_3
}CMS_Center_aligned_mode_selection;




/**
  * @brief 	This is the auto_reload preloading enable
  *	@bit number		bit 7
  * @state  0: TIMx_ARR register is not buffered
  *			1: TIMx_ARR register is buffered
  */
typedef enum{
	Not_buffered,
	buffered
}ARPE,Auto_reload_preload_enable;



/**
  * @brief
  * @bit number		bit 8:9
  * @state  This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and
				sampling clock used by the digital filters (ETR, TIx)
				00: t DTS  = t CK_INT
				01: t DTS  = 2 × t CK_INT
				10: t DTS  = 4 × t CK_INT
				11:  Reserved

*/
typedef enum{
	CLK_Division_Mode_0,
	CLK_Division_Mode_1,
	CLK_Division_Mode_2,
}CKD_Clock_division;




/******************************TIMERx_CR2*********************TIM control register 2, Address offset: 0x04 ****************/



#endif /* INC_TIMER_REGESTERS_H_ */
