/*
 * App.c
 *
 * Created: 10/10/2022 9:11:17 AM
 *  Author: Win 10 5G
 */ 

#include <avr/delay.h>
#define FCPU 10000
#include "../Utilities/BIT_MATH.h"
#include "../Utilities/STD_TYPES.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/LED/LED_Config.h"
#include "../ECUAL/Button/Button.h"
#include "../ECUAL/Button/Button_Config.h"
#include "../MCAL/Timer/Timer0.h"
#include "../MCAL/Interrupt/Interrupt.h"
#include "../App/App.h"

// Global variables to be able to use it in the ISR

u8 ReturnStateOfApp ;
En_LightRead LightsRead ;
En_ButtonRead ButtonReadState ;


void App_Int (void) {
	/*
		Description: this function initialize the application
		inputs: none
		outputs: none
		return: none
	*/
		DIO_Int() ; // also int the leds
		DIO_SetPinValue(DIO_PortD,PIN2, Floating ) ;
		TimerNormalModeStart () ;
		Interrupt_Init() ;
}

void NormalMode (void) { 
	LedsOff() ;
	Led_On (CarLedPortGreen , CarLedPinGreen) ;
	ReturnStateOfApp = Green ;
	DelayingFor5Sec() ;
	LedsOff() ;
	Led_Off(CarLedPortGreen,CarLedPinGreen) ;
	ReturnStateOfApp = Yellow ;
	Led_Blink5Sec (CarLedPortYellow, CarLedPinYellow) ;
	LedsOff() ;
	Led_On (CarLedPortRed , CarLedPinRed) ;
	ReturnStateOfApp = Red ;
	DelayingFor5Sec() ;
	Led_Off(CarLedPortRed , CarLedPinRed)  ;
	LedsOff() ;
	Led_Blink5Sec (CarLedPortYellow, CarLedPinYellow) ;
}

void PasRed (void) {
		
		/* If pressed when the cars' Red LED is on,
		the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
		this means that pedestrians can cross the street while the pedestrian's Green LED is on. */
	
	 // Led_On (CarLedPortRed , CarLedPinRed) ;
	  Led_On(PasLedPortGreen , PasLedPinGreen) ;
	  DelayingFor5Sec() ;
	  Led_Off(CarLedPortRed, CarLedPinRed) ;
	 Led_Off(PasLedPortGreen , PasLedPinGreen) ;
}

void PasGreenOrYellow (void) {
	 
	/* If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, 
	the pedestrian Red LED will be on 
	then both Yellow LEDs start to blink for five seconds, 
	then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
	 this means that pedestrian must wait until the Green LED is on. */
	
	  Led_Off( CarLedPortGreen , CarLedPinGreen) ; // if when green
	  Led_On (PasLedPortRed , PasLedPinRed) ;
	  TwoLeds_Blink5Sec (CarLedPortYellow, CarLedPinYellow , PasLedPortYellow , PasLedPinYellow) ;
	  Led_Off (CarLedPortYellow , CarLedPinYellow ) ;
	  Led_Off (PasLedPortYellow , PasLedPinYellow) ;
	  Led_Off(PasLedPortRed , PasLedPinRed) ;
	  Led_On(PasLedPortGreen , PasLedPinGreen) ;
	  Led_On(CarLedPortRed, CarLedPinRed) ;
	  DelayingFor5Sec() ;
}

void PasMode (void) {
	  if ( 	ReturnStateOfApp == Red ) {
		PasRed () ;
	  }
	 
	  else if ( ReturnStateOfApp == Yellow || ReturnStateOfApp == Green  ) {
		 PasGreenOrYellow() ;
	   }
	 
	/* At the end of the two states,
	 the cars' Red LED will be off
	 and both Yellow LEDs start blinking for 5 seconds and
	 the pedestrian's Green LED is still on.
	 After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
	 Traffic lights signals are going to the normal mode again. */
	  Led_Off (CarLedPortRed , CarLedPinRed )  ;
	  Led_On(PasLedPortGreen , PasLedPinGreen) ;
	  TwoLeds_Blink5Sec (CarLedPortYellow, CarLedPinYellow , PasLedPortYellow , PasLedPinYellow) ;
	  Led_Off (CarLedPortYellow , CarLedPinYellow ) ;
	  Led_Off (PasLedPortYellow , PasLedPinYellow) ;
	  Led_Off(PasLedPortGreen,PasLedPinGreen) ;
	  Led_On(PasLedPortRed , PasLedPinRed) ;
	  Led_On(CarLedPortGreen, CarLedPinGreen) ;
	  if (ReturnStateOfApp == Yellow) {
	  DelayingFor5Sec() ;
	  Led_Off(CarLedPortGreen,CarLedPinGreen) ; 
	  }
}

ISR (EXT_INT_0) {
	_delay_ms(300);
	En_ButtonRead ReadButton ;
	ReadButton = ButtonRead(DIO_PortD, PIN2);
		if	( ReadButton == Not_Pressed ) {
	PasMode();
		}
}

void App_Start (void) {
	
	/*
		Description: this function starts the app 
		inputs: none
		outputs: none
		return: none
	*/
while (1) {
		NormalMode();
}

}

