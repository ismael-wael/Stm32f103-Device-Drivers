#ifndef _HTFT_INTERFACE_H_
#define _HTFT_INTERFACE_H_

#include "GPIO_interface.h"

typedef struct{
	GPIO_t	TFT_A0;
	GPIO_t	TFT_RST;
	GPIO_t	TFT_SS;
}TFT_t;

extern TFT_t TFTDisplay;

void HTFT_voidPinsConfig(void);
void HTFT_voidInit(void);
void HTFT_voidDisplayImage(pu16 Copy_pu16Image);
static void HTFT_voidWriteCommand(u8 Copy_u8Command);
static void HTFT_voidWriteData(u8 Copy_u8Data);

#endif
