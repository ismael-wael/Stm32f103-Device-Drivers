/* Library includes */
#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

/* Module includes */
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
#include "GPIO_interface.h"


void AFIO_voidSetEXTIConfiguration(u8 Copy_u8EXTI_Line ,u8 Copy_u8PortMap)
{
	
	u8 LOC_u8RegIndex = Copy_u8EXTI_Line / 4;

	Copy_u8EXTI_Line = Copy_u8EXTI_Line % 4;
	/* Clear the four bits first */
	AFIO_Ptr -> EXTICRx[LOC_u8RegIndex] &= ~(( 0b1111) << (Copy_u8EXTI_Line * 4));
	/* Write into the four bits */
	AFIO_Ptr -> EXTICRx[LOC_u8RegIndex] |= (Copy_u8PortMap) << (Copy_u8EXTI_Line * 4);
}
