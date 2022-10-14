/*
 * Button.h
 *
 * Created: 10/4/2022 7:24:09 AM
 *  Author: Win 10 5G
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

// including DIO

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Config.h"

// Functions Prototypes

typedef enum EnumReturnStateOfButton 
{
	Pressed , Not_Pressed 
} En_ButtonRead ;


En_ButtonRead ButtonRead (u8 ButtonPort , u8 Buttonpin) ;


#endif /* BUTTON_H_ */