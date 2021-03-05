#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "Hswitch_config.h"
#include "Hswitch_interface.h"

#include "GPIO_interface.h"

static SwitchesState Switches;

void Hswitch_voidInit(void)
{
	Switches.u8DownSwitchState = HIGH_STATE;
	Switches.u8UpSwitchState = HIGH_STATE;
	Switches.u8LeftSwitchState = HIGH_STATE;
	Switches.u8RightSwitchState = HIGH_STATE;
	Switches.u8CenterSwitchState = HIGH_STATE;

	for(u8 u8Iterator = 0 ; u8Iterator < NO_OF_SWITCHES ; u8Iterator++)
	{
		MGPIO_voidSetPinDirection(ArrOfSwitches[u8Iterator].GPIO_tSwitch, ArrOfSwitches[u8Iterator].u8SwitchMode);
	}
}

void Hswitches_voidUpdate(void)
{

}

void Hswitches_voidProcess(void)
{

}


