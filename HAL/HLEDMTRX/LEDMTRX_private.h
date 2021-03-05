#ifndef LEDMTRX_H_
#define LEDMTRX_H_

#include "LEDMTRX_interface.h"
#include "LEDMTRX_config.h"

extern HLEDMTRX LedmtrxArr [NUM_OF_LEDMTRX];

#define HLEDMTRX_SendDataRow_8BIT(u8DataCpy,u8LEDMTRXNumber)  		 do{MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin0 ,GET_BIT(u8DataCpy,0)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin1 ,GET_BIT(u8DataCpy,1)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin2 ,GET_BIT(u8DataCpy,2)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin3 ,GET_BIT(u8DataCpy,3)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin4 ,GET_BIT(u8DataCpy,4)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin5 ,GET_BIT(u8DataCpy,5)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin6 ,GET_BIT(u8DataCpy,6)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Row_Port ,LedmtrxArr[u8LEDMTRXNumber].Row_Pin7 ,GET_BIT(u8DataCpy,7));} while(0)

#define HLEDMTRX_SendDataColumn_8BIT(u8DataCpy,u8LEDMTRXNumber)  	 do{MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin0 ,GET_BIT(u8DataCpy,0)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin1 ,GET_BIT(u8DataCpy,1)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin2 ,GET_BIT(u8DataCpy,2)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin3 ,GET_BIT(u8DataCpy,3)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin4 ,GET_BIT(u8DataCpy,4)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin5 ,GET_BIT(u8DataCpy,5)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin6 ,GET_BIT(u8DataCpy,6)); \
															        	MGPIO_voidSetPinValue(LedmtrxArr[u8LEDMTRXNumber].Col_Port ,LedmtrxArr[u8LEDMTRXNumber].Col_Pin7 ,GET_BIT(u8DataCpy,7));} while(0)

#endif
