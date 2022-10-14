/*
 * LED.c
 *
 * Created: 10/4/2022 4:24:42 AM
 *  Author: Win 10 5G
 */ 

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
 #include "LED.h"
 #include "LED_Config.h" 
 #include "../../MCAL/Timer/Timer0.h"

 /************************************************************************/
 /* Implementation of a function that lights the pin   */
 /************************************************************************/

void Led_On (u8 LedPort , u8 LedPin ) {
	DIO_SetPinValue(LedPort, LedPin , High ) ;
}


// function turns the led off 
void Led_Off (u8 LedPort , u8 LedPin ) {
	DIO_SetPinValue(LedPort, LedPin , Low ) ;
}


void Led_Toggle ( u8 LedPort , u8 LedPin ) {
	
	// used to toggle tha value in DIO 
	
	DIO_TogglePinValue(LedPort,LedPin);
}

void Led_Blink5Sec (u8 LedPort , u8 LedPin ) {
	
		
	/*
		Description: this function is used to blink led for 5 sec
		input : led port and led pin
		outputs: the blinking
		return: none
	*/
	
SET_BIT (TCCR0_REG, 2) ; //selecting the desired prescaler
u32	OverFlowsCounter = 0 ;
	while ( OverFlowsCounter < 77 ) // the number of overflows for 5 secs
	{
		while ( ( TIFR_REG & (1 << 0) ) == 0 ) ;	 // checking interrupt flag to see if it reached the overflow
		
		if (OverFlowsCounter % 6 == 0 ) {
			Led_Toggle(LedPort,LedPin);
		}
	    SET_BIT (TIFR_REG , 0 )  ; //clearing the register after the first overflow
		OverFlowsCounter++;
	}
	Led_Off(LedPort,LedPin) ;
	 OverFlowsCounter = 0 ;
}

void  TwoLeds_Blink5Sec (u8 LedPort , u8	LedPin , u8 Led2Port , u8 Led2Pin ) {
	
	
	/*
		Description: this function is used to blink 2 leds for 5 sec
		input : 2 leds port and 2 leds pins
		outputs: the blinking
		return: none
	*/
	
	
	SET_BIT (TCCR0_REG, 2) ; //selecting the desired prescaler
	u32	OverFlowsCounter = 0 ;
	while ( OverFlowsCounter < 77 ) // the number of overflows for 5 secs
	{
		while ( ( TIFR_REG & (1 << 0) ) == 0 ) ;	 // checking interrupt flag to see if it reached the overflow
		
		if (OverFlowsCounter % 6 == 0 ) {
			Led_Toggle(LedPort,LedPin);
			Led_Toggle(Led2Port,Led2Pin);
		}
		
		SET_BIT (TIFR_REG , 0 )  ; //clearing the register after the first overflow
		OverFlowsCounter++;
	}
	Led_Off(LedPort,LedPin) ;
	OverFlowsCounter = 0 ;

}

void LedsOff (void) {
	
	/*
		Description: this function is used to turn off all the lights
		input : none
		outputs: none
		return: none
	*/
	
	
	Led_Off(CarLedPortGreen , CarLedPinGreen) ;
	Led_Off (CarLedPortYellow, CarLedPinYellow) ;
	Led_Off( CarLedPortRed , CarLedPinRed) ;
	
	
	Led_Off(PasLedPortGreen , PasLedPinGreen) ;
	Led_Off (PasLedPortYellow, PasLedPinYellow) ;
	Led_Off( PasLedPortRed , PasLedPinRed) ;
}