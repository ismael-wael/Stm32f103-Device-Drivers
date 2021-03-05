#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "GPIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"

void SSD_Init(void)
{
	u8 u8Iterator = 0;

	for(u8Iterator = 0 ; u8Iterator < NUM_OF_SSD ; u8Iterator++)
	{
		// Initialize Enable pin
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tEnablePin, OUTPUT_SPEED_2MHZ_PP);

		// make data pins output
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_A, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_B, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_C, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_D, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_E, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_F, OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(HSSDArrayOfSSD[u8Iterator].GPIO_tPin_G, OUTPUT_SPEED_2MHZ_PP);

		if(HSSDArrayOfSSD[u8Iterator].Type == COM_ANODE)
		{
			MGPIO_voidSetPinValue( HSSDArrayOfSSD[u8Iterator].GPIO_tEnablePin , HIGH);
		}
		else if(HSSDArrayOfSSD[u8Iterator].Type == COM_CATHODE)
		{
			MGPIO_voidSetPinValue( HSSDArrayOfSSD[u8Iterator].GPIO_tEnablePin , LOW);
		}
	}
}

void SSD_voidEnableOneDisableRest(u8 HSSD_Number)
{
	u8 u8Iterator = 0;

	for(u8Iterator = 0 ; u8Iterator < NUM_OF_SSD ; u8Iterator++)
	{
		if(u8Iterator == HSSD_Number)
		{
			MGPIO_voidSetPinValue( HSSDArrayOfSSD[u8Iterator].GPIO_tEnablePin , HSSDArrayOfSSD[u8Iterator].Type ^ LOW);
		}
		else
		{
			MGPIO_voidSetPinValue( HSSDArrayOfSSD[u8Iterator].GPIO_tEnablePin , HSSDArrayOfSSD[u8Iterator].Type ^ HIGH);
		}
	}
}

void SSD_voidEnable( u8 HSSD_Number )
{
	MGPIO_voidSetPinValue( HSSDArrayOfSSD[HSSD_Number].GPIO_tEnablePin , HSSDArrayOfSSD[HSSD_Number].Type ^ LOW);
}	

void SSD_voidDisable( u8 HSSD_Number )
{
	MGPIO_voidSetPinValue( HSSDArrayOfSSD[HSSD_Number].GPIO_tEnablePin , HSSDArrayOfSSD[HSSD_Number].Type ^ HIGH);
}

void SSD_voidSendNumber( u8 HSSD_Number  , u8 Copy_u8Number )
{
	u8 LOC_u8Arr[10]= {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101,
					   0b01111101, 0b00000111, 0b01111111, 0b01101111};

	SSD_voidClearLeds( HSSD_Number );

	if (HSSDArrayOfSSD[HSSD_Number].Type == COM_CATHODE )
	{
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_A , GET_BIT(LOC_u8Arr[Copy_u8Number],0));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_B , GET_BIT(LOC_u8Arr[Copy_u8Number],1));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_C , GET_BIT(LOC_u8Arr[Copy_u8Number],2));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_D , GET_BIT(LOC_u8Arr[Copy_u8Number],3));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_E , GET_BIT(LOC_u8Arr[Copy_u8Number],4));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_F , GET_BIT(LOC_u8Arr[Copy_u8Number],5));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_G , GET_BIT(LOC_u8Arr[Copy_u8Number],6));
	}
	else if (HSSDArrayOfSSD[HSSD_Number].Type == COM_ANODE )
	{
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_A , !GET_BIT(LOC_u8Arr[Copy_u8Number],0));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_B , !GET_BIT(LOC_u8Arr[Copy_u8Number],1));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_C , !GET_BIT(LOC_u8Arr[Copy_u8Number],2));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_D , !GET_BIT(LOC_u8Arr[Copy_u8Number],3));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_E , !GET_BIT(LOC_u8Arr[Copy_u8Number],4));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_F , !GET_BIT(LOC_u8Arr[Copy_u8Number],5));
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_G , !GET_BIT(LOC_u8Arr[Copy_u8Number],6));
	}
}

void SSD_voidClearLeds( u8 HSSD_Number )
{
	if (HSSDArrayOfSSD[HSSD_Number].Type == COM_CATHODE )
	{
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_A , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_B , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_C , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_D , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_E , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_F , LOW);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_G , LOW);
	}
	else if (HSSDArrayOfSSD[HSSD_Number].Type == COM_ANODE )
	{
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_A , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_B , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_C , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_D , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_E , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_F , HIGH);
		MGPIO_voidSetPinValue(HSSDArrayOfSSD[HSSD_Number].GPIO_tPin_G , HIGH);
	}
}

