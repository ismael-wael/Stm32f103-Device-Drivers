#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void MSPI_voidInit(void)
{
	u8 u8Iterator;

	u8 u32Register = 0;

	for(u8Iterator = 0 ; u8Iterator < NUM_OF_SPI ; u8Iterator++)
	{

		switch(u8Iterator)
		{
		case 0 :
			SPI1_Base->SPI_CR1 = conc_16(0,0,0,0,1,
									     0,0,0,0,0,
									     0,0,0,0,0,0);
		}
	}
}
