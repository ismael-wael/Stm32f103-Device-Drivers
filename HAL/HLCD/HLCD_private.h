/****************************************************************/
/*   Author             :   Ismael Wael 				    	*/
/*	 Date 				:   29 October 2020 					*/
/*	 Version 			:   1.0V 							 	*/
/*	 Description 		:   LCD private header file				*/
/*							contains some helper Macros 	    */
/****************************************************************/

#ifndef _LCD_PRIVATE_
#define _LCD_PRIVATE_

#define HLCD_u8FirstRowStart            ((u8)0b10000000)
#define HLCD_u8SecondRowStart           ((u8)0b11000000)

#define HLCD_u8FirstRow       ((u8)0)
#define HLCD_u8SecRow         ((u8)1)

#define HLCD_u8FirstCol       ((u8)0)
#define HLCD_u8LastCol        ((u8)15)

#define HLCD_u8FirstCGRAMPos  ((u8)0)
#define HLCD_u8LastCGRAMPos   ((u8)8)

#define HLCD_u8MODE_4BIT      0
#define HLCD_u8MODE_8BIT      1

extern HLCD HLCDArrayOfLCD [ HLCD_u8NumberOfLCD ];

#define HLCD_SendDataPort_8BIT(u8DataCpy,u8LCDNumber)  	 do{MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_0 ,GET_BIT(u8DataCpy,0)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_1 ,GET_BIT(u8DataCpy,1)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_2 ,GET_BIT(u8DataCpy,2)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_3 ,GET_BIT(u8DataCpy,3)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_4 ,GET_BIT(u8DataCpy,4)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_5 ,GET_BIT(u8DataCpy,5)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_6 ,GET_BIT(u8DataCpy,6)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_7 ,GET_BIT(u8DataCpy,7));} while(0)

#define HLCD_SendDataPort_4BIT(u8DataCpy,u8LCDNumber)  	 do{MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_4 ,GET_BIT(u8DataCpy,4)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_5 ,GET_BIT(u8DataCpy,5)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_6 ,GET_BIT(u8DataCpy,6)); \
															MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8DataPin_7 ,GET_BIT(u8DataCpy,7));} while(0)


#endif /*_LCD_PRIVATE_*/
