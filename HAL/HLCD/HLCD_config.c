/****************************************************************/
/*   Author             :    Ismael Wael 				    	*/
/*	 Date 				:    29 October 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    contain LCD Pins configuration		*/
/*             							[config.c] 				*/
/*								Link time configuration	in 		*/
/*									   build process			*/
/****************************************************************/

#include "GPIO_interface.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"

HLCD HLCDArrayOfLCD [ HLCD_u8NumberOfLCD ] =
{
	{ HLCD_u8MODE_4BIT  ,
	  0 ,0 ,0 ,0,
	  .HLCD_u8DataPin_4 = {PIN4 , GPIOA_Port},
	  .HLCD_u8DataPin_5 = {PIN5 , GPIOA_Port},
	  .HLCD_u8DataPin_6 = {PIN6 , GPIOA_Port},
	  .HLCD_u8DataPin_7 = {PIN7 , GPIOA_Port},

	  .HLCD_u8RegSelectPin = {PIN0 , GPIOA_Port},
	  .HLCD_u8ReadWritePin = {PIN1 , GPIOA_Port},
	  .HLCD_u8EnablePin    = {PIN2 , GPIOA_Port}
	}
};

/*****************************************************************/
/*********************** END OF PROGRAM **************************/
/*****************************************************************/


