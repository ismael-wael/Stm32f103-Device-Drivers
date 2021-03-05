#ifndef HSWITCH_INTERFACE_H_
#define HSWITCH_INTERFACE_H_

#include "GPIO_interface.h"

#define HIGH_STATE		1
#define LOW_STATE		0

typedef struct{
	ToggleState_t u8UpSwitchState;
	ToggleState_t u8DownSwitchState;
	ToggleState_t u8LeftSwitchState;
	ToggleState_t u8RightSwitchState;
	ToggleState_t u8CenterSwitchState;
}SwitchesState;

typedef struct{
    GPIO_t GPIO_tSwitch;

    u8 u8SwitchMode;        // INPUT_ANALOG
}Hswitch_t;                 // INPUT_FLOATING
                            // INPUT_PULL_UP_OR_DOWN

extern const Hswitch_t ArrOfSwitches[NO_OF_SWITCHES];

#endif
