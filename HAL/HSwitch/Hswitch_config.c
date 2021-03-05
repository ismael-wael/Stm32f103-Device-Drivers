#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "Hswitch_config.h"
#include "Hswitch_interface.h"

#include "GPIO_interface.h"

Hswitch_t const ArrOfSwitches[NO_OF_SWITCHES] =
{
		[SWITCH_UP] = {
							.GPIO_tSwitch = {PIN8 , GPIOB_Port},
							.u8SwitchMode = INPUT_PULL_UP_OR_DOWN
					  },

		[SWITCH_DOWN] = {
							.GPIO_tSwitch = {PIN7 , GPIOB_Port},
							.u8SwitchMode = INPUT_PULL_UP_OR_DOWN
					    },

		[SWITCH_LEFT] = {
							.GPIO_tSwitch = {PIN9 , GPIOB_Port},
							.u8SwitchMode = INPUT_PULL_UP_OR_DOWN
						},

		[SWITCH_RIGHT] = {
							.GPIO_tSwitch = {PIN6 , GPIOB_Port},
							.u8SwitchMode = INPUT_PULL_UP_OR_DOWN
						},

		[SWITCH_CENTER] = {
							.GPIO_tSwitch = {PIN5 , GPIOB_Port},
							.u8SwitchMode = INPUT_PULL_UP_OR_DOWN
						}

};
