/*
 * Compiler.h
 *
 *  Created on: Aug 29, 2019
 *      Author: Ahmed Wasfy
 */

#ifndef INC_COMPILER_H_
#define INC_COMPILER_H_

/* REQ:COMPILER040,049,051 */
#define AUTOMATIC auto
#define STATIC 	static
#define NULL_PTR	((void *)0)

#define INLINE __inline__

#define ASM		  __asm

#define DISABLE_INTERRUPT() 	ASM("CPSID i;");
#define ENABLE_INTERRUPT()	ASM("CPSIE	i;");


#endif /* INC_COMPILER_H_ */
