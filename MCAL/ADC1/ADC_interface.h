#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//ADC Mode
#define     Single_Conversion_mode          0
#define     Continous_Conversion_mode       1

//ADC Channels
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7
#define ADC_CH8		8
#define ADC_CH9		9
#define NOT_USED	0

//ADC Alignment
#define Right_Alignment			0
#define Left_Alignment			1

void MADC_voidInit(void);

void MADC_voidStartConversion(void);

u16 MADC_u16ReadConvertedData(void);

/*ADC Example (using ADC channel 1 [GPIOA - PIN1]):
 * ___________
 * int main(void)
{
	MRCC_enuInitSysClock();
	MRCC_enuEnableClock(APB2_BUS, GPIOA_RCC);
	MRCC_enuEnableClock(APB2_BUS, GPIOB_RCC);
	MRCC_enuEnableClock(APB1_BUS, TIM4_RCC);
	MRCC_enuEnableClock(APB2_BUS, ADC1_RCC);
	MSTK_voidInit();//AHB = 8 MHz , systick clk = AHB / 8
	HLCD_enuInit();
	MADC_voidInit();

	GPIO_t Pot_pin;
	Pot_pin.GPIO_Pin = PIN1; // ADC channel1
	Pot_pin.GPIO_Port = GPIOA_Port;

	MGPIO_voidSetPinDirection(Pot_pin, INPUT_ANALOG);

	u16 potentiometer = 0;

	MADC_voidStartConversion();//because in continous mood

	while(1)
	{
		potentiometer = MADC_u16ReadConvertedData();

		potentiometer = ((potentiometer*3300)/(4096));

		HLCD_enuClearScreen(HLCD_u8NUmber_1);
		HLCD_voidDisplayString("Pot : " , HLCD_u8NUmber_1);
		HLCD_voidIntegerToString((u32)potentiometer, HLCD_u8NUmber_1);
		HLCD_voidDisplayString(" mv" , HLCD_u8NUmber_1);
		MSTK_voidSetBusyWait(1000000);
	}

	return 0;
}*/


#endif
