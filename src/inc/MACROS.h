/*
 * MACROS.h
 *
 * Created: 7/17/2018 7:51:32 PM
 *  Author: Carnival
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define set_bit(reg,pin) (reg) |=1 << (pin)
#define reset_bit(reg,pin) (reg) &=~(1<< (pin))
#define toggel_bit(reg,pin) (reg) ^= (1<<(pin))

#define set_port(reg,mask) (reg)|=(mask)
#define reset_port(reg,mask) (reg)&=~(mask)
#define toggel_port(reg,mask) (reg)^=(mask)
#define write_port(reg,mask) (reg)=(mask)

#define all_high(reg) (reg)=(0xFF)
#define all_low(reg) (reg)=(0x00)

#define getbit(reg,pin) ((reg>>pin)&(1))





#endif /* MACROS_H_ */