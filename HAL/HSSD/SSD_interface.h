#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "LIB_BMNP.h"
#include "GPIO_interface.h"
#include "SSD_config.h"

#define COM_ANODE       1
#define COM_CATHODE     0

typedef struct {
	u8 Type;

	GPIO_t GPIO_tPin_A;
	GPIO_t GPIO_tPin_B;
	GPIO_t GPIO_tPin_C;
	GPIO_t GPIO_tPin_D;
	GPIO_t GPIO_tPin_E;
	GPIO_t GPIO_tPin_F;
	GPIO_t GPIO_tPin_G;

	GPIO_t GPIO_tEnablePin;
}SSD_t;

extern SSD_t HSSDArrayOfSSD [ NUM_OF_SSD ] ;

void SSD_Init(void);
void SSD_voidEnable( u8 HSSD_Number );
void SSD_voidDisable( u8 HSSD_Number );
void SSD_voidSendNumber( u8 HSSD_Number  , u8 Copy_u8Number );
void SSD_voidClearLeds( u8 HSSD_Number );
void SSD_voidEnableOneDisableRest(u8 HSSD_Number);

#endif
