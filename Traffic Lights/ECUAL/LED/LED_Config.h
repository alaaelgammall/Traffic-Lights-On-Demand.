/*
 * LED_Config.h
 *
 * Created: 10/4/2022 4:25:22 AM
 *  Author: Win 10 5G
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

// including DIO

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_Config.h"


// Cars Port and pins
#define CarLedPortGreen DIO_PortA
#define CarLedPortYellow DIO_PortA
#define CarLedPortRed DIO_PortA 

#define CarLedPinGreen PIN0
#define CarLedPinYellow PIN1
#define CarLedPinRed PIN2 

// Pas leds and pins

#define PasLedPortGreen DIO_PortB
#define PasLedPortRed DIO_PortB
#define PasLedPortYellow DIO_PortB

#define PasLedPinGreen PIN0
#define PasLedPinYellow PIN1
#define PasLedPinRed PIN2

#endif /* LED_CONFIG_H_ */