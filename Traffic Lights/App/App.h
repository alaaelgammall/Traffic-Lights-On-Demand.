/*
 * App.h
 *
 * Created: 10/10/2022 9:11:31 AM
 *  Author: Win 10 5G
 */ 


#ifndef APP_H_
#define APP_H_

// including DIO 

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/DIO/DIO_Config.h"

// Functions Protypes

void App_Int (void) ;
void NormalMode (void) ;
void PasMode (void) ;
void PasRed (void) ;
void PasGreenOrYellow (void) ;
void App_Start (void)  ;

// enum for colors
typedef enum EnumReturnStateOfApp
{
	Green , Yellow , Red
} En_LightRead ;

#endif /* APP_H_ */