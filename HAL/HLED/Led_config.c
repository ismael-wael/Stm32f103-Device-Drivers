#include "GPIO_interface.h"
#include "Led_config.h"
#include "Led_interface.h"

LED_t  HLEDArrayOfLeds [ NUM_OF_LEDS ] =
{

				[HLED_Red_Alarm] = {
											.HLED_GPIO_tPin = {PIN6 ,GPIOA_Port},
											.HLED_u8ActiveLevel = HLED_ACTIVE_HIGH
									},

				[HLED_Green_Time] = {
											.HLED_GPIO_tPin = {PIN7 ,GPIOA_Port},
											.HLED_u8ActiveLevel = HLED_ACTIVE_HIGH
									}

};


