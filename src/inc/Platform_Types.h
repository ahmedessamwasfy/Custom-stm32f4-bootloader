/*
 * Platform_Types.h
 *
 *  Created on: Aug 29, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_PLATFORM_TYPES_H_
#define INC_PLATFORM_TYPES_H_


/*
 * CPU register type width
 */
#define CPU_TYPE_8	  			(8u)
#define CPU_TYPE_16   			(16u)
#define CPU_TYPE_32	  			(32u)


/*
 * Bit order definition
 */
#define MSB_FIRST				(0x0)
#define LSB_FIRST				(0x1)


/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST			(0x0)
#define LOW_BYTE_FIRST			(0x1)


/*
 * platform type and endiness definitions, specific for tm4c123gh6pm (Not Sure)
 */
#define CPU_TYPE 				CPU_TYPE_32

#define CPU_BIT_ORDER			LSB_FIRST
#define CPU_BYTE_ORDER			LOW_BYTE_FIRST

#define FALSE                   0x0
#define TRUE					0x1


/*
 * AUTOSAR integer data types
 */

typedef signed char  	   	 sint8;
typedef unsigned char 	   	uint8;
typedef signed short       	sint16;
typedef unsigned short     	uint16;
typedef signed long        	sint32;
typedef unsigned long 	   	uint32;
typedef unsigned long long 	uint64;
typedef float 				float32;
typedef double 				float64;

typedef unsigned int 		uint8_least;
typedef unsigned int		uint16_least;
typedef unsigned long 		uint32_least;
typedef signed int 			sint8_least;
typedef signed int 			sint16_least;
typedef signed int 			sint32_least;


//typedef volatile int8 vint8_t;
//typedef volatile uint8 vuint8_t;

//typedef volatile int16_t vint16_t;
//typedef volatile uint16_t vuint16_t;

//typedef volatile int32_t vint32_t;
//typedef volatile uint32_t vuint32_t;

//typedef volatile int64_t vint64_t;
//typedef volatile uint64_t vuint64_t;

typedef unsigned char 		boolean;


#endif /* INC_PLATFORM_TYPES_H_ */
