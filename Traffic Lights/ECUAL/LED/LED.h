/*
 * LED.h
 *
 * Created: 10/4/2022 4:24:59 AM
 *  Author: Win 10 5G
 */ 


#ifndef LED_H_
#define LED_H_


// Including DIO 

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Config.h"


// Functions Prototypes

void Led_Int (u8 LedPort , u8 LedPin) ; 
void Led_On (u8 LedPort , u8 LedPin ) ;
void Led_Off (u8 LedPort , u8 LedPin ) ;
void Led_Toggle (u8 LedPort , u8 LedPin ) ;
void Led_Blink5Sec (u8 LedPort , u8 LedPin ) ;
void  TwoLeds_Blink5Sec (u8 LedPort , u8	LedPin , u8 Led2Port , u8 Led2Pin ) ;
void LedsOff (void) ;


#endif /* LED_H_ */