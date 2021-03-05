#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "LEDMTRX_private.h"
#include "LEDMTRX_interface.h"
#include "LEDMTRX_config.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "Timer_interface.h"

void LedMtrx_voidInit(void)
{
	u8 u8Iterator = 0;

	for( ; u8Iterator < NUM_OF_LEDMTRX ; u8Iterator++)
	{
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin0 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin1 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin2 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin3 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin4 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin5 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin6 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Row_Port, LedmtrxArr[u8Iterator].Row_Pin7 , OUTPUT_SPEED_2MHZ_PP);

		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin0 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin1 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin2 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin3 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin4 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin5 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin6 , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(LedmtrxArr[u8Iterator].Col_Port, LedmtrxArr[u8Iterator].Col_Pin7 , OUTPUT_SPEED_2MHZ_PP);
	}
}

void LedMtrx_voidDrawFrame(pu8 pu8_Frame , u8 u8LedMtrxNumber)
{
	MRCC_enuEnableClock (APB1_BUS , TIM4_RCC);
	u8 Arr_u8ControlValues[8] = {0xfe , 0xfd , 0xfb , 0xf7 , 0xef , 0xdf , 0xbf , 0x7f} ;

	if(LedmtrxArr[u8LedMtrxNumber].ControlMode == CONTROL_COLS)
	{
		//Activate Column0
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[0],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[0],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column1
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[1],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[1],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column2
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[2],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[2],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column3
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[3],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[3],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column4
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[4],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[4],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column5
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[5],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[5],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column6
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[6],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[6],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);

		//Activate Column7
		HLEDMTRX_SendDataColumn_8BIT(Arr_u8ControlValues[7],u8LedMtrxNumber);
		HLEDMTRX_SendDataRow_8BIT(pu8_Frame[7],u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2300);
	}
	else if(LedmtrxArr[u8LedMtrxNumber].ControlMode == CONTROL_ROWS)
	{
		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[0], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[0], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[1], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[1], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[2], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[2], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[3], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[3], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[4], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[4], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[5], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[5], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[6], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[6], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);

		HLEDMTRX_SendDataRow_8BIT(Arr_u8ControlValues[7], u8LedMtrxNumber);
		HLEDMTRX_SendDataColumn_8BIT(pu8_Frame[7], u8LedMtrxNumber);
		Mtimer4_voidDelay_us(2500);
	}

	MRCC_enuDisableClock (APB1_BUS , TIM4_RCC);
}
