/*
 * Interrupt.h
 *
 * Created: 10/7/2022 7:55:39 PM
 *  Author: Win 10 5G
 */ 
#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// Including DIO 

#include "../DIO/DIO.h"
#include "../DIO/DIO_Config.h"


// External Interrupt vectors

// External interrupt request 0
#define EXT_INT_0 __vector_1
// External interrupt request 1
#define EXT_INT_1 __vector_2
// External interrupt request 2
#define EXT_INT_2 __vector_3

// Set global interrupts, set the I-bit in status register to 1
#define  sei() __asm__ __volatile__ ("sei" ::: "memory")

// Clear Global interrupts, set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")


//registers

#define MCUCR *((volatile u8*)0x55)
#define GICR *((volatile u8*)0x5B)

// ISR defition

#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal, used)); \
void INT_VECT(void)

// Function protypes

void Interrupt_Init(void) ;  

#endif