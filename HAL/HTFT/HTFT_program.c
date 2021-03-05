#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "HTFT_interface.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "SPI_interface.h"

TFT_t TFTDisplay;

void HTFT_voidInit(void)
{
	TFTDisplay.TFT_SS.GPIO_Pin = PIN0;
	TFTDisplay.TFT_SS.GPIO_Port = GPIOA_Port;

	TFTDisplay.TFT_RST.GPIO_Pin = PIN1;
	TFTDisplay.TFT_RST.GPIO_Port = GPIOA_Port;

	TFTDisplay.TFT_A0.GPIO_Pin = PIN2;
	TFTDisplay.TFT_A0.GPIO_Port = GPIOA_Port;

	/* TFT pins initialization */
    MGPIO_voidSetPinDirection(TFTDisplay.TFT_SS , OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(TFTDisplay.TFT_RST , OUTPUT_SPEED_2MHZ_PP);
    MGPIO_voidSetPinDirection(TFTDisplay.TFT_A0 , OUTPUT_SPEED_2MHZ_PP);

     /*Reset pulse*/
     MGPIO_voidSetPinValue(TFTDisplay.TFT_RST, HIGH);
     MSTK_voidSetBusyWait(100);
     MGPIO_voidSetPinValue(TFTDisplay.TFT_RST, LOW);
     MSTK_voidSetBusyWait(1);
     MGPIO_voidSetPinValue(TFTDisplay.TFT_RST, HIGH);
     MSTK_voidSetBusyWait(100);
     MGPIO_voidSetPinValue(TFTDisplay.TFT_RST, LOW);
     MSTK_voidSetBusyWait(100);
     MGPIO_voidSetPinValue(TFTDisplay.TFT_RST, HIGH);
     MSTK_voidSetBusyWait(120000);

     /*sleep out command*/
     HTFT_voidWriteCommand(0x11);

     /*wait 150 msec*/
     MSTK_voidSetBusyWait(150000);

     /*Color Code Command*/
     HTFT_voidWriteCommand(0x3A);

     /*Color Code Data : RGB565*/
     HTFT_voidWriteData(0x05);

     /*Display ON command*/
     HTFT_voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(pu16 Copy_pu16Image)
{

}

static void HTFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8* pu8ReceivedData=0;
	MGPIO_voidSetPinValue(TFTDisplay.TFT_A0, LOW);

	MSPI1_voidSendReceiveSynch(Copy_u8Command , pu8ReceivedData , TFTDisplay.TFT_SS);
}

static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	u8* pu8ReceivedData=0;
	MGPIO_voidSetPinValue(TFTDisplay.TFT_A0, HIGH);

	MSPI1_voidSendReceiveSynch(Copy_u8Data , pu8ReceivedData , TFTDisplay.TFT_SS);
}
