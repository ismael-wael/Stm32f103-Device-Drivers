#include "GPIO_interface.h"
#include "Led_config.h"
#include "Led_interface.h"

void Hled_voidInit(void)
{
	u8 u8Iterator ;
	for(u8Iterator = 0 ; u8Iterator < NUM_OF_LEDS ; u8Iterator++)
	{
		MGPIO_voidSetPinDirection(HLEDArrayOfLeds[u8Iterator].HLED_GPIO_tPin, HLEDArrayOfLeds[u8Iterator].HLED_u8ActiveLevel);
	}
}

void Hled_voidLedOn(u8 Hled_u8Number)
{
	MGPIO_voidSetPinValue(HLEDArrayOfLeds[Hled_u8Number].HLED_GPIO_tPin, HLEDArrayOfLeds[Hled_u8Number].HLED_u8ActiveLevel ^ LOW);
}

void Hled_voidLedOff(u8 Hled_u8Number)
{
	MGPIO_voidSetPinValue(HLEDArrayOfLeds[Hled_u8Number].HLED_GPIO_tPin, HLEDArrayOfLeds[Hled_u8Number].HLED_u8ActiveLevel ^ HIGH);
}
