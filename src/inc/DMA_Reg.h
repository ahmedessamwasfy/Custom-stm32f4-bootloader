/*
 * DMA_Reg.h
 *
 *  Created on: Sep 12, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_DMA_REG_H_
#define INC_DMA_REG_H_

/* ==================================================================== */
/* ========================== RCC Regesters =========================== */
/* ==================================================================== */
#define  RCC_AHB1ENR_DMA1EN                  ((uint32)0x00200000)
#define  RCC_AHB1ENR_DMA2EN                  ((uint32)0x00400000)

#define  RCC_AHB1ENR                 *((volatile uint32 *)(0x40203830))

/* ==================================================================== */
/* ========================== DMA Regesters =========================== */
/* ==================================================================== */
/*
 *
 *
 *
 * */

#define AHB1PERIPH_BASE       (0x40020000)


#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8)


#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8)


/*
#define DMA1                (*(volatile (uint32*)) DMA1_BASE)
#define DMA1_Stream0        (*(volatile (uint32*)) DMA1_Stream0_BASE)
#define DMA1_Stream1        (*(volatile (uint32*)) DMA1_Stream1_BASE)
#define DMA1_Stream2        (*(volatile (uint32*)) DMA1_Stream2_BASE)
#define DMA1_Stream3        (*(volatile (uint32*)) DMA1_Stream3_BASE)
#define DMA1_Stream4        (*(volatile (uint32*)) DMA1_Stream4_BASE)
#define DMA1_Stream5        (*(volatile (uint32*)) DMA1_Stream5_BASE)
#define DMA1_Stream6        (*(volatile (uint32*)) DMA1_Stream6_BASE)
#define DMA1_Stream7        (*(volatile (uint32*)) DMA1_Stream7_BASE)
#define DMA2                (*(volatile (uint32*)) DMA2_BASE)
#define DMA2_Stream0        (*(volatile (uint32*)) DMA2_Stream0_BASE)
#define DMA2_Stream1        (*(volatile (uint32*)) DMA2_Stream1_BASE)
#define DMA2_Stream2        (*(volatile (uint32*)) DMA2_Stream2_BASE)
#define DMA2_Stream3        (*(volatile (uint32*)) DMA2_Stream3_BASE)
#define DMA2_Stream4        (*(volatile (uint32*)) DMA2_Stream4_BASE)
#define DMA2_Stream5        (*(volatile (uint32*)) DMA2_Stream5_BASE)
#define DMA2_Stream6        (*(volatile (uint32*)) DMA2_Stream6_BASE)
#define DMA2_Stream7        (*(volatile (uint32*)) DMA2_Stream7_BASE)
*/
///OFSETTS

//#define DMA_CR(stream)  			0x10+0x18*stream   /*!< DMA stream x configuration register      */
//#define DMA_NDTR(stream)			0x14+0x18*stream   /*!< DMA stream x number of data register     */
//#define DMA_PAR(stream)				0x18+0x18*stream    /*!< DMA stream x peripheral address register */
//#define DMA_M0AR(stream)			0x1C+0x18*stream   /*!< DMA stream x memory 0 address register   */
//#define DMA_M1AR(stream)			0x20+0x18*stream   /*!< DMA stream x memory 1 address register   */
//#define DMA_FCR(stream)				0x24+0x24*stream 	/*!< DMA stream x FIFO control register       */

//#define LISR 				0x00   /*!< DMA low interrupt status register,      Address offset: 0x00 */
//#define HISR 				0x04   /*!< DMA high interrupt status register,     Address offset: 0x04 */
//#define LIFCR 				0x08  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//#define HIFCR 				0x0C  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */

#define DMA1_CR(stream)  				*((volatile uint32*)(0x10+0x18*stream+DMA1_BASE))  /*!< DMA stream x configuration register      */
#define DMA1_NDTR(stream)				*((volatile uint32*)0x14+0x18*stream+DMA1_BASE)    /*!< DMA stream x number of data register     */
#define DMA1_PAR(stream)				*((volatile uint32*)0x18+0x18*stream+DMA1_BASE)    /*!< DMA stream x peripheral address register */
#define DMA1_M0AR(stream)				*((volatile uint32*)0x1C+0x18*stream+DMA1_BASE)    /*!< DMA stream x memory 0 address register   */
#define DMA1_M1AR(stream)				*((volatile uint32*)0x20+0x18*stream+DMA1_BASE)    /*!< DMA stream x memory 1 address register   */
#define DMA1_FCR(stream)				*((volatile uint32*)0x24+0x24*stream+DMA1_BASE) 	/*!< DMA stream x FIFO control register       */
#define DMA1_LISR 						*((volatile uint32*) 0x00+DMA1_BASE)   			/*!< DMA low interrupt status register,      Address offset: 0x00 */
#define DMA1_HISR 						*((volatile uint32*) 0x04+DMA1_BASE) 	  			/*!< DMA high interrupt status register,     Address offset: 0x04 */
#define DMA1_LIFCR 						*((volatile uint32*) 0x08+DMA1_BASE)  				/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
#define DMA1_HIFCR 						*((volatile uint32*) 0x0C+DMA1_BASE)  				/*!< DMA high interrupt flag clear register, Address offset: 0x0C */


#define DMA2_CR(stream)  				*((volatile uint32*) (0x010+(0x18*stream)+DMA2_BASE))    /*!< DMA stream x configuration register      */
#define DMA2_NDTR(stream)				*((volatile uint32*) (0x014+(0x010*stream)+DMA2_BASE))    /*!< DMA stream x number of data register     */
#define DMA2_PAR(stream)				*((volatile uint32*) (0x018+(0x010*stream)+DMA2_BASE))    /*!< DMA stream x peripheral address register */
#define DMA2_M0AR(stream)				*((volatile uint32*) (0x01C+(0x010*stream)+DMA2_BASE))    /*!< DMA stream x memory 0 address register   */
#define DMA2_M1AR(stream)				*((volatile uint32*) (0x020+(0x010*stream)+DMA2_BASE))    /*!< DMA stream x memory 1 address register   */
#define DMA2_FCR(stream)				*((volatile uint32*) (0x024+(0x24*stream)+DMA2_BASE)) 	 /*!< DMA stream x FIFO control register       */
#define DMA2_LISR 						*((volatile uint32*) (0x00+DMA2_BASE ))  				/*!< DMA low interrupt status register,      Address offset: 0x00 */
#define DMA2_HISR 						*((volatile uint32*) (0x04+DMA2_BASE ))  				/*!< DMA high interrupt status register,     Address offset: 0x04 */
#define DMA2_LIFCR 						*((volatile uint32*) (0x08+DMA2_BASE ))	 				/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
#define DMA2_HIFCR 						*((volatile uint32*) (0x0C+DMA2_BASE )) 					/*!< DMA high interrupt flag clear register, Address offset: 0x0C */






/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_CHSEL                       ((uint32)0x0E000000)
#define DMA_SxCR_CHSEL_0                     ((uint32)0x02000000)
#define DMA_SxCR_CHSEL_1                     ((uint32)0x04000000)
#define DMA_SxCR_CHSEL_2                     ((uint32)0x08000000)
#define DMA_SxCR_MBURST                      ((uint32)0x01800000)
#define DMA_SxCR_MBURST_0                    ((uint32)0x00800000)
#define DMA_SxCR_MBURST_1                    ((uint32)0x01000000)
#define DMA_SxCR_PBURST                      ((uint32)0x00600000)
#define DMA_SxCR_PBURST_0                    ((uint32)0x00200000)
#define DMA_SxCR_PBURST_1                    ((uint32)0x00400000)
#define DMA_SxCR_ACK                         ((uint32)0x00100000)
#define DMA_SxCR_CT                          ((uint32)0x00080000)
#define DMA_SxCR_DBM                         ((uint32)0x00040000)
#define DMA_SxCR_PL                          ((uint32)0x00030000)
#define DMA_SxCR_PL_0                        ((uint32)0x00010000)
#define DMA_SxCR_PL_1                        ((uint32)0x00020000)
#define DMA_SxCR_PINCOS                      ((uint32)0x00008000)
#define DMA_SxCR_MSIZE                       ((uint32)0x00006000)
#define DMA_SxCR_MSIZE_0                     ((uint32)0x00002000)
#define DMA_SxCR_MSIZE_1                     ((uint32)0x00004000)
#define DMA_SxCR_PSIZE                       ((uint32)0x00001800)
#define DMA_SxCR_PSIZE_0                     ((uint32)0x00000800)
#define DMA_SxCR_PSIZE_1                     ((uint32)0x00001000)
#define DMA_SxCR_MINC                        ((uint32)0x00000400)
#define DMA_SxCR_PINC                        ((uint32)0x00000200)
#define DMA_SxCR_CIRC                        ((uint32)0x00000100)
#define DMA_SxCR_DIR                         ((uint32)0x000000C0)
#define DMA_SxCR_DIR_0                       ((uint32)0x00000040)
#define DMA_SxCR_DIR_1                       ((uint32)0x00000080)
#define DMA_SxCR_PFCTRL                      ((uint32)0x00000020)
#define DMA_SxCR_TCIE                        ((uint32)0x00000010)
#define DMA_SxCR_HTIE                        ((uint32)0x00000008)
#define DMA_SxCR_TEIE                        ((uint32)0x00000004)
#define DMA_SxCR_DMEIE                       ((uint32)0x00000002)
#define DMA_SxCR_EN                          ((uint32)0x00000001)

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT                            ((uint32)0x0000FFFF)
#define DMA_SxNDT_0                          ((uint32)0x00000001)
#define DMA_SxNDT_1                          ((uint32)0x00000002)
#define DMA_SxNDT_2                          ((uint32)0x00000004)
#define DMA_SxNDT_3                          ((uint32)0x00000008)
#define DMA_SxNDT_4                          ((uint32)0x00000010)
#define DMA_SxNDT_5                          ((uint32)0x00000020)
#define DMA_SxNDT_6                          ((uint32)0x00000040)
#define DMA_SxNDT_7                          ((uint32)0x00000080)
#define DMA_SxNDT_8                          ((uint32)0x00000100)
#define DMA_SxNDT_9                          ((uint32)0x00000200)
#define DMA_SxNDT_10                         ((uint32)0x00000400)
#define DMA_SxNDT_11                         ((uint32)0x00000800)
#define DMA_SxNDT_12                         ((uint32)0x00001000)
#define DMA_SxNDT_13                         ((uint32)0x00002000)
#define DMA_SxNDT_14                         ((uint32)0x00004000)
#define DMA_SxNDT_15                         ((uint32)0x00008000)

/********************  Bits definition for DMA_SxFCR register  ****************/
#define DMA_SxFCR_FEIE                       ((uint32)0x00000080)
#define DMA_SxFCR_FS                         ((uint32)0x00000038)
#define DMA_SxFCR_FS_0                       ((uint32)0x00000008)
#define DMA_SxFCR_FS_1                       ((uint32)0x00000010)
#define DMA_SxFCR_FS_2                       ((uint32)0x00000020)
#define DMA_SxFCR_DMDIS                      ((uint32)0x00000004)
#define DMA_SxFCR_FTH                        ((uint32)0x00000003)
#define DMA_SxFCR_FTH_0                      ((uint32)0x00000001)
#define DMA_SxFCR_FTH_1                      ((uint32)0x00000002)

/********************  Bits definition for DMA_LISR register  *****************/
#define DMA_LISR_TCIF3                       ((uint32)0x08000000)
#define DMA_LISR_HTIF3                       ((uint32)0x04000000)
#define DMA_LISR_TEIF3                       ((uint32)0x02000000)
#define DMA_LISR_DMEIF3                      ((uint32)0x01000000)
#define DMA_LISR_FEIF3                       ((uint32)0x00400000)
#define DMA_LISR_TCIF2                       ((uint32)0x00200000)
#define DMA_LISR_HTIF2                       ((uint32)0x00100000)
#define DMA_LISR_TEIF2                       ((uint32)0x00080000)
#define DMA_LISR_DMEIF2                      ((uint32)0x00040000)
#define DMA_LISR_FEIF2                       ((uint32)0x00010000)
#define DMA_LISR_TCIF1                       ((uint32)0x00000800)
#define DMA_LISR_HTIF1                       ((uint32)0x00000400)
#define DMA_LISR_TEIF1                       ((uint32)0x00000200)
#define DMA_LISR_DMEIF1                      ((uint32)0x00000100)
#define DMA_LISR_FEIF1                       ((uint32)0x00000040)
#define DMA_LISR_TCIF0                       ((uint32)0x00000020)
#define DMA_LISR_HTIF0                       ((uint32)0x00000010)
#define DMA_LISR_TEIF0                       ((uint32)0x00000008)
#define DMA_LISR_DMEIF0                      ((uint32)0x00000004)
#define DMA_LISR_FEIF0                       ((uint32)0x00000001)

/********************  Bits definition for DMA_HISR register  *****************/
#define DMA_HISR_TCIF7                       ((uint32)0x08000000)
#define DMA_HISR_HTIF7                       ((uint32)0x04000000)
#define DMA_HISR_TEIF7                       ((uint32)0x02000000)
#define DMA_HISR_DMEIF7                      ((uint32)0x01000000)
#define DMA_HISR_FEIF7                       ((uint32)0x00400000)
#define DMA_HISR_TCIF6                       ((uint32)0x00200000)
#define DMA_HISR_HTIF6                       ((uint32)0x00100000)
#define DMA_HISR_TEIF6                       ((uint32)0x00080000)
#define DMA_HISR_DMEIF6                      ((uint32)0x00040000)
#define DMA_HISR_FEIF6                       ((uint32)0x00010000)
#define DMA_HISR_TCIF5                       ((uint32)0x00000800)
#define DMA_HISR_HTIF5                       ((uint32)0x00000400)
#define DMA_HISR_TEIF5                       ((uint32)0x00000200)
#define DMA_HISR_DMEIF5                      ((uint32)0x00000100)
#define DMA_HISR_FEIF5                       ((uint32)0x00000040)
#define DMA_HISR_TCIF4                       ((uint32)0x00000020)
#define DMA_HISR_HTIF4                       ((uint32)0x00000010)
#define DMA_HISR_TEIF4                       ((uint32)0x00000008)
#define DMA_HISR_DMEIF4                      ((uint32)0x00000004)
#define DMA_HISR_FEIF4                       ((uint32)0x00000001)

/********************  Bits definition for DMA_LIFCR register  ****************/
#define DMA_LIFCR_CTCIF3                     ((uint32)0x08000000)
#define DMA_LIFCR_CHTIF3                     ((uint32)0x04000000)
#define DMA_LIFCR_CTEIF3                     ((uint32)0x02000000)
#define DMA_LIFCR_CDMEIF3                    ((uint32)0x01000000)
#define DMA_LIFCR_CFEIF3                     ((uint32)0x00400000)
#define DMA_LIFCR_CTCIF2                     ((uint32)0x00200000)
#define DMA_LIFCR_CHTIF2                     ((uint32)0x00100000)



#define DMA_LIFCR_CDMEIF2                    ((uint32)0x00040000)
#define DMA_LIFCR_CFEIF2                     ((uint32)0x00010000)
#define DMA_LIFCR_CTCIF1                     ((uint32)0x00000800)
#define DMA_LIFCR_CHTIF1                     ((uint32)0x00000400)
#define DMA_LIFCR_CTEIF1                     ((uint32)0x00000200)
#define DMA_LIFCR_CDMEIF1                    ((uint32)0x00000100)
#define DMA_LIFCR_CFEIF1                     ((uint32)0x00000040)
#define DMA_LIFCR_CTCIF0                     ((uint32)0x00000020)
#define DMA_LIFCR_CHTIF0                     ((uint32)0x00000010)
#define DMA_LIFCR_CTEIF0                     ((uint32)0x00000008)
#define DMA_LIFCR_CDMEIF0                    ((uint32)0x00000004)
#define DMA_LIFCR_CFEIF0                     ((uint32)0x00000001)

/********************  Bits definition for DMA_HIFCR  register  ****************/
#define DMA_HIFCR_CTCIF7                     ((uint32)0x08000000)
#define DMA_HIFCR_CHTIF7                     ((uint32)0x04000000)
#define DMA_HIFCR_CTEIF7                     ((uint32)0x02000000)
#define DMA_HIFCR_CDMEIF7                    ((uint32)0x01000000)
#define DMA_HIFCR_CFEIF7                     ((uint32)0x00400000)
#define DMA_HIFCR_CTCIF6                     ((uint32)0x00200000)
#define DMA_HIFCR_CHTIF6                     ((uint32)0x00100000)
#define DMA_HIFCR_CTEIF6                     ((uint32)0x00080000)
#define DMA_HIFCR_CDMEIF6                    ((uint32)0x00040000)
#define DMA_HIFCR_CFEIF6                     ((uint32)0x00010000)
#define DMA_HIFCR_CTCIF5                     ((uint32)0x00000800)
#define DMA_HIFCR_CHTIF5                     ((uint32)0x00000400)
#define DMA_HIFCR_CTEIF5                     ((uint32)0x00000200)
#define DMA_HIFCR_CDMEIF5                    ((uint32)0x00000100)
#define DMA_HIFCR_CFEIF5                     ((uint32)0x00000040)
#define DMA_HIFCR_CTCIF4                     ((uint32)0x00000020)
#define DMA_HIFCR_CHTIF4                     ((uint32)0x00000010)
#define DMA_HIFCR_CTEIF4                     ((uint32)0x00000008)
#define DMA_HIFCR_CDMEIF4                    ((uint32)0x00000004)
#define DMA_HIFCR_CFEIF4                     ((uint32)0x00000001)

/* @prog __ApplicationName ****************************************************
**
** __ShortDescription__
**
******************************************************************************/
	

#endif /* INC_DMA_REG_H_ */
