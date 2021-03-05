#ifndef  USART_INTERFACE_H
#define  USART_INTERFACE_H

#define USART_DISABLE           0
#define USART_ENABLE            1

#define BAUD_9600               0
#define BAUD_115200             1

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define PARITY_ENABLE           1

#define USART_PARITY_EVEN       0
#define USART_PARITY_ODD        1

#define USART_PE_DISABLED       0
#define USART_PE_ENABLED        1

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1       /* Transmit Data Register is empty */
#define TCE_INT_ENABLE          3       /* Transmittion Complemte Interrupt */
#define RXNE_INT_ENABLE         5       /* Data Register not empty interrupt */

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISABLE        0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3

/******************************************* USART1 *****************************************/

/* Initialize USART */
void MUSART1_voidInit(void);

/* USART_1 Transmit a word
    i/p:  Array of Characters */
void MUSART1_voidTransmit(u8 Copy_u8Char);

/* USART_1 Receive Data
    i/p: Threshold value not to wait the sender infinite time to send the data 
    o/p: The received data from the sender */
u8 MUSART1_u8Receive(u32 Copy_u32TimeOut);
/*********************************************************************************************/

/***Test***/

/*#include "include.h"

int main(void)
{
	MRCC_enuInitSysClock();
	MRCC_enuEnableClock(APB1_BUS, TIM4_RCC);
	MRCC_enuEnableClock(APB2_BUS, GPIOA_RCC);
	MRCC_enuEnableClock(APB2_BUS, USART1_RCC);
	HLCD_enuInit();

	GPIO_t Tx , Rx , led;
	led.GPIO_Pin = PIN0;
	led.GPIO_Port = GPIOA_Port;
	MGPIO_voidSetPinDirection(led, OUTPUT_SPEED_2MHZ_PP);
	Tx.GPIO_Pin = PIN9;
	Tx.GPIO_Port = GPIOA_Port;

	Rx.GPIO_Pin = PIN10;
	Rx.GPIO_Port = GPIOA_Port;

	MGPIO_voidSetPinDirection(Tx, OUTPUT_SPEED_2MHZ_AFPP);
	MGPIO_voidSetPinDirection(Rx, INPUT_FLOATING);
	u8 t;
	MUSART1_voidInit();

	MUSART1_voidTransmit('T');


	while(1)
	{
		t = MUSART1_u8Receive(1000);
		if(t == 'E')
		{
			MGPIO_voidSetPinValue(led, HIGH);
			HLCD_enuWriteData(t, HLCD_u8NUmber_1);
			MUSART1_voidTransmit('*');
			MUSART1_voidTransmit(t);
			MUSART1_voidTransmit('*');
		}
		else if(t == 'D')
		{
			MGPIO_voidSetPinValue(led, LOW);
			HLCD_enuWriteData(t, HLCD_u8NUmber_1);
			MUSART1_voidTransmit('*');
			MUSART1_voidTransmit(t);
			MUSART1_voidTransmit('*');
		}

		//MUSART1_voidTransmit(t);
	}
	return 0;
}

 * */

/******************************************* USART2 *****************************************/

/* Initialize USART */
void MUSART2_voidInit(void);

/* USART_2 Transmit a word
    i/p:  Array of Characters */
void MUSART2_voidTransmit(char* Word);

/* USART_2 Receive Data
    i/p: Threshold value not to wait the sender infinite time to send the data 
    o/p: The received data from the sender */
u8 MUSART2_u8Receive(u32 Copy_u32TimeOut);
/*********************************************************************************************/

/******************************************* USART3 *****************************************/

/* Initialize USART */
void MUSART3_voidInit(void);

/* USART_3 Transmit a word
    i/p:  Array of Characters */
void MUSART3_voidTransmit(char* Word);

/* USART_3 Receive Data
    i/p: Threshold value not to wait the sender infinite time to send the data 
    o/p: The received data from the sender */
u8 MUSART3_u8Receive(u32 Copy_u32TimeOut);
/*********************************************************************************************/

#endif
