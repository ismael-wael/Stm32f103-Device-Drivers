/****************************************************************/
/*   Author             :   Ismael Wael 				    	*/
/*	 Date 				:   29 October 2020 					*/
/*	 Version 			:   1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/
/*							for LCD				  			    */
/****************************************************************/

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

#include "LIB_STDTypes.h"
#include "GPIO_interface.h"

//list of all commands in LCD module
#define CLEAR_DISPLAY         			((u8)0b00000001)
#define RETURN_HOME    		 			((u8)0b00000010)
#define ENTRY_MODE_INC 		 			((u8)0b00000111)
#define ENTRY_MODE_DEC  		 		((u8)0b00000101)
#define DISPLAY_ON_ONLY		 			((u8)0b00001100)
#define DISPLAY_ON_WITH_CURSOR  		((u8)0b00001110)
#define DISPLAY_ON_WITH_CURSOR_BLINKING ((u8)0b00001111)
#define CURSOR_SHIFT_RIGHT  			((u8)0b00010100)
#define CURSOR_SHIFT_LEFT  		 		((u8)0b00010000)
#define DISPLAY_SHIFT_RIGHT  			((u8)0b00011100)
#define DISPLAY_SHIFT_LEFT  			((u8)0b00011000)
#define FUNCTION_SET  		 			((u8)0b00111100)

//LCD 2 MODES of operations
#define HLCD_u8MODE_4BIT      0
#define HLCD_u8MODE_8BIT      1

typedef struct Hlcd{
	u8 HLCD_u8MODE;

	GPIO_t HLCD_u8DataPin_0;
	GPIO_t HLCD_u8DataPin_1;
	GPIO_t HLCD_u8DataPin_2;
	GPIO_t HLCD_u8DataPin_3;
	GPIO_t HLCD_u8DataPin_4;
	GPIO_t HLCD_u8DataPin_5;
	GPIO_t HLCD_u8DataPin_6;
	GPIO_t HLCD_u8DataPin_7;

	GPIO_t HLCD_u8RegSelectPin;
	GPIO_t HLCD_u8ReadWritePin;
	GPIO_t HLCD_u8EnablePin;

}HLCD;

tenumFncErrorState HLCD_enuInit(void);
tenumFncErrorState HLCD_enuWriteData(u8 HLCD_u8DataCpy, u8 u8LCDNumber);
tenumFncErrorState HLCD_enuWriteCmd(u8 HLCD_u8CmdCpy, u8 u8LCDNumber);
tenumFncErrorState HLCD_enuGoToXY(u8 HLCD_u8RowNum,u8 HLCD_u8ColumnNum , u8 u8LCDNumber);
//void HLCD_enuCGRAM(void);//maximum 8 charcters (each 5*8 pixels stored in 8 addresses starting from 0x00)
tenumFncErrorState HLCD_voidIntegerToString(u32 u32Value, u8 u8LCDNumber);
tenumFncErrorState HLCD_voidDisplayString(pu8 pu8String , u8 u8LCDNumber);
tenumFncErrorState HLCD_enuClearScreen(u8 u8LCDNumber);


/*simple application example (in main):
____________________

void main (void)
{
	HLCD_enuInit();
	HLCD_voidDisplayString("i love mohamed!" , HLCD_u8NUmber_1);
	HLCD_voidIntegerToString(5*6,HLCD_u8NUmber_1);
	HLCD_voidDisplayString("ismael wael!" , HLCD_u8NUmber_2);
	HLCD_voidIntegerToString(25,HLCD_u8NUmber_2);
	while(1)
	{
	}
}
*/

#endif /* HLCD_INTERFACE_H_ */
