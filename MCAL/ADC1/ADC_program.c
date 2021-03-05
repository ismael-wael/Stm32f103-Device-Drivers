#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void MADC_voidInit(void)
{
    // If this bit holds a value of zero and a 1 is written to it then it wakes up the ADC from Power Down state
	ADC1_ptr->ADC_CR2 &= ~(1 << 0);//Clr
    ADC1_ptr->ADC_CR2 |= (1 << 0);//set

    //ADC_mode
	#if ADC_mode == Single_Conversion_mode
    	ADC1_ptr->ADC_CR2 &= ~(1 << 1); // single-conversion mode
	#elif ADC_mode == Continous_Conversion_mode
    	ADC1_ptr->ADC_CR2 |= (1 << 1); // continous-conversion mode
	#endif

    //number of channels
    ADC1_ptr->ADC_SQR1 |= ( (number_of_channels-1) << 20);

    // initialize ADC Calibration register
    ADC1_ptr->ADC_CR2 |= (1 << 3);
    // start ADC calibration 
    ADC1_ptr->ADC_CR2 |= (1 << 2);



    //Data_Alignment
	#if DATA_ALIGNMENT == Right_Alignment
    	ADC1_ptr->ADC_CR2 &= ~(1 << 11); // right-alignment
	#elif DATA_ALIGNMENT == Left_Alignment
    	ADC1_ptr->ADC_CR2 |= (1 << 11); // left-alignment
	#endif


    u8 Channels[16] = {channel1, channel2, channel3, channel4,
    			   	   channel5, channel6, channel7, channel8,
					   channel9,channel10, channel11, channel12,
					   channel13, channel14, channel15, channel16};


    //set channels (channel 16 ,internal temperature sensor)
    for(u8 i = 0 ; i < 16 ; i++ )
    {
    	if(i < 6)
    		ADC1_ptr->ADC_SQR3 |= (Channels[i] << i%4);
    	else if(i >= 6 && i < 12 )
    		ADC1_ptr->ADC_SQR2 |= (Channels[i] << i%4);
    	else
    		ADC1_ptr->ADC_SQR1 |= (Channels[i] << i%4);
    }
}

void MADC_voidStartConversion(void)
{
    // Conversion starts when this bit holds a value of 1 and a 1 is written to it
    ADC1_ptr->ADC_CR2 |= (1 << 0);

    // start ADC conversion of regular group 
    ADC1_ptr->ADC_CR2 |= (1 << 22);
}

u16 MADC_u16ReadConvertedData(void)
{
    while(GET_BIT(ADC1_ptr->ADC_SR,1) == 0);

    //right alignment
    u16 u16Value = (u16) ADC1_ptr->ADC_DR ;

    return u16Value;
}
