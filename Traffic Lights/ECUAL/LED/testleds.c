/*
 * testleds.c
 *
 * Created: 10/12/2022 9:11:47 PM
 *  Author: Win 10 5G
 */ 

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "LED.h"
#include "LED_Config.h"
#include "../../MCAL/Timer/Timer0.h"

/*
u8 main (void) {
	
		DIO_Int() ;
		TimerNormalModeStart () ;
	while (1) {
	Led_On (PasLedPortRed , PasLedPinRed) ;
	
	TwoLeds_Blink5Sec (CarLedPortYellow, CarLedPinYellow , PasLedPortYellow , PasLedPinYellow) ;
	
	Led_Off(PasLedPortRed , PasLedPinRed) ;
	
	Led_On(PasLedPortGreen , PasLedPinGreen) ;
	
	LedsOff();
	
	Led_Blink5Sec (CarLedPortYellow, CarLedPinYellow) ;
	
	Led_Toggle(PasLedPortGreen , PasLedPinGreen) ;
	}
} */