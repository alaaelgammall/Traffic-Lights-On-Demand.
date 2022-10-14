/*
 * Interrupt.c
 *
 * Created: 10/7/2022 7:55:23 PM
 *  Author: Win 10 5G
 */ 

#include "../../Utilities/STD_TYPES.h"
#include "Interrupt.h" 

void Interrupt_Init(void){
	// 1. Enable global interrupt(setting bit 7 in status register to 1
	sei();
	// 2. Choosing the external interrupt on the rising edge
	MCUCR |= (1 << 0) | (1 << 1);
	// 3.Enable External interrupt 0(INT0)
	GICR |= (1 << 6);
	
}