/*
 * Button.c
 *
 * Created: 10/4/2022 7:24:38 AM
 *  Author: Win 10 5G
 */ 

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "Button.h"
#include "Button_Config.h"


En_ButtonRead ButtonRead (u8 ButtonPort ,u8 ButtonPin) {
	
	/*
		Description: this function reads the button if pressed or not
		inputs: ButtonPort , ButtonPin
		outputs: none
		return: Button Read
	*/

	u8 ReturnState ;
	u8 LocalPinValue = DIO_GetPinValue(ButtonPort,ButtonPin) ;
	if (LocalPinValue == 0 ) {
		ReturnState = Not_Pressed ;
	}
	else if (LocalPinValue == 1) {
		ReturnState = Pressed ;
	}
	return ReturnState ;
}