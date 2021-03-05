/****************************************************************/
/*   Author             :   Ismael Wael 				    	*/
/*	 Date 				:   29 October 2020 					*/
/*	 Version 			:   1.0V 							 	*/
/*	 Description 		:   basic functions definitions for LCD*/
/****************************************************************/

//used libraries
#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

//GPIO
#include "GPIO_interface.h"

//LCD
#include "HLCD_interface.h"
#include "HLCD_config.h"
#include "HLCD_private.h"

#include "Timer_interface.h"
//#include "SysTick_interface.h"

tenumFncErrorState HLCD_enuInit(void)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY ;
	u8 Local_u8Iterator;

	for(Local_u8Iterator = 0 ; Local_u8Iterator < HLCD_u8NumberOfLCD ; Local_u8Iterator++ )
	{
		if(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8MODE == HLCD_u8MODE_8BIT)
		{
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_0,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_1,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_2,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_3,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_4,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_5,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_6,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_7,OUTPUT_SPEED_2MHZ_PP);
		}
		else if (HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8MODE == HLCD_u8MODE_4BIT)
		{
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_4,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_5,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_6,OUTPUT_SPEED_2MHZ_PP);
			MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8DataPin_7,OUTPUT_SPEED_2MHZ_PP);

		}
		else
		{
			ReturnFunState = LSTY_READ_ERROR;
			return ReturnFunState;
		}

		MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8ReadWritePin,OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8RegSelectPin,OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8EnablePin,OUTPUT_SPEED_2MHZ_PP);
		Mtimer4_voidDelay_ms(40);
		//MSTK_voidSetBusyWait(40000); // 40000 uSec = 40 mSec

		if(HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8MODE == HLCD_u8MODE_8BIT)
		{
			HLCD_enuWriteCmd(FUNCTION_SET,Local_u8Iterator);
			Mtimer4_voidDelay_ms(1);
			//MSTK_voidSetBusyWait(1000); // 1000 uSec = 1 mSec
		}
		else if (HLCDArrayOfLCD[Local_u8Iterator].HLCD_u8MODE == HLCD_u8MODE_4BIT)
		{
			HLCD_enuWriteCmd(0x33,Local_u8Iterator);
			HLCD_enuWriteCmd(0x32,Local_u8Iterator);
			HLCD_enuWriteCmd(0x28,Local_u8Iterator);
		}
		else
		{
			ReturnFunState = LSTY_READ_ERROR;
			return ReturnFunState;
		}

		HLCD_enuWriteCmd(DISPLAY_ON_WITH_CURSOR,Local_u8Iterator);

		Mtimer4_voidDelay_ms(1);
		//MSTK_voidSetBusyWait(1000); // 1000 uSec = 1 mSec
		HLCD_enuWriteCmd(CLEAR_DISPLAY,Local_u8Iterator);
		Mtimer4_voidDelay_ms(2);
		//MSTK_voidSetBusyWait(2000); // 2000 uSec = 2 mSec
	}

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuWriteData(u8 HLCD_u8DataCpy, u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD))
	{

		MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8RegSelectPin, HIGH);
		MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8ReadWritePin, LOW);

		if(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8MODE == HLCD_u8MODE_4BIT)
		{
			u8 u8data = HLCD_u8DataCpy & 0xf0;
			HLCD_SendDataPort_4BIT(u8data,u8LCDNumber); // sending high nibble first
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH);// E = 1

			Mtimer4_voidDelay_us(1);
			//MSTK_voidSetBusyWait(1); // 1 uSec

			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW);// E = 0

			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec

			u8data = HLCD_u8DataCpy << 4;
			HLCD_SendDataPort_4BIT(u8data,u8LCDNumber); // sending low nibble second
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH); // E = 1 ;

			Mtimer4_voidDelay_us(1);
			//MSTK_voidSetBusyWait(1); // 1 uSec

			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW); // E = 0

			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec
		}
		else if(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8MODE == HLCD_u8MODE_8BIT)
		{
			HLCD_SendDataPort_8BIT(HLCD_u8DataCpy,u8LCDNumber);
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH);
			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW);
		}
		else
		{
			ReturnFunState = LSTY_READ_ERROR;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuWriteCmd(u8 HLCD_u8CmdCpy, u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD))
	{
		MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8RegSelectPin, LOW);
		MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8ReadWritePin, LOW);

		if(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8MODE == HLCD_u8MODE_4BIT)
		{
			u8 u8data = HLCD_u8CmdCpy & 0xf0;
			HLCD_SendDataPort_4BIT(u8data,u8LCDNumber); // sending high nibble first
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH);// E = 1

			Mtimer4_voidDelay_us(1);
			//MSTK_voidSetBusyWait(1); // 1 uSec
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW);// E = 0

			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec
			u8data = HLCD_u8CmdCpy << 4;
			HLCD_SendDataPort_4BIT(u8data,u8LCDNumber); // sending low nibble second
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH); // E = 1 ;

			Mtimer4_voidDelay_us(1);
			//MSTK_voidSetBusyWait(1); // 1 uSec
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW); // E = 0

			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec
		}
		else if(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8MODE == HLCD_u8MODE_8BIT)
		{
			HLCD_SendDataPort_8BIT(HLCD_u8CmdCpy,u8LCDNumber);
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, HIGH);

			Mtimer4_voidDelay_us(2);
			//MSTK_voidSetBusyWait(20); // 20 uSec
			MGPIO_voidSetPinValue(HLCDArrayOfLCD[u8LCDNumber].HLCD_u8EnablePin, LOW);
		}
		else
		{
			ReturnFunState = LSTY_READ_ERROR;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}

	return ReturnFunState;
}

tenumFncErrorState HLCD_enuGoToXY(u8 HLCD_u8RowNum,u8 HLCD_u8ColumnNum , u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;
	if(((HLCD_u8FirstCol <= HLCD_u8ColumnNum) && (HLCD_u8LastCol >= HLCD_u8ColumnNum)) &&
			((HLCD_u8FirstRow <= HLCD_u8RowNum) && (HLCD_u8SecRow >= HLCD_u8RowNum))  &&
			((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD)))
	{
		switch (HLCD_u8RowNum)
		{
		case HLCD_u8FirstRow:
			HLCD_enuWriteCmd(HLCD_u8FirstRowStart+HLCD_u8ColumnNum ,u8LCDNumber);
			break;
		case HLCD_u8SecRow:
			HLCD_enuWriteCmd(HLCD_u8SecondRowStart+HLCD_u8ColumnNum ,u8LCDNumber);
			break;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}
	return ReturnFunState;
}

tenumFncErrorState HLCD_voidIntegerToString(u32 u32Value, u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD))
	{
		u32 reverse = 1; /*to hold zeros*/

		while(u32Value >= 1) /*reverse : 1000 -> 10001*/
		{
			reverse = reverse*10+u32Value%10;
			u32Value = u32Value / 10;
		}

		while(reverse != 1)
		{
			HLCD_enuWriteData( reverse%10 +'0',u8LCDNumber);
			reverse = reverse / 10;
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}
	return ReturnFunState;
}


tenumFncErrorState HLCD_voidDisplayString(pu8 pu8String , u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD))
	{
		u8 u8Counter;
		for(u8Counter = 0 ; *(pu8String+u8Counter) !='\0' ; u8Counter++)
		{
			HLCD_enuWriteData(*(pu8String+u8Counter) , u8LCDNumber);
		}
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}
	return ReturnFunState;
}

tenumFncErrorState HLCD_enuClearScreen(u8 u8LCDNumber)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8LCDNumber >= 0)  && (u8LCDNumber < HLCD_u8NumberOfLCD))
	{

		Mtimer4_voidDelay_us(20);
		//MSTK_voidSetBusyWait(1000); // 1000 uSec = 1 mSec
		HLCD_enuWriteCmd(CLEAR_DISPLAY , u8LCDNumber);
		Mtimer4_voidDelay_us(20);
		//MSTK_voidSetBusyWait(2000); // 2000 uSec = 2 mSec
	}
	else
	{
		ReturnFunState = LSTY_OUT_OF_RANGE;
	}
	return ReturnFunState;
}


