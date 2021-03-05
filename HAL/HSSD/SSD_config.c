#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"
#include "GPIO_interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"

 SSD_t HSSDArrayOfSSD [ NUM_OF_SSD ] = {

		{
				.Type = COM_ANODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN8 , GPIOA_Port}
		},

		{
				.Type = COM_ANODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN9 , GPIOA_Port}
		},

		{
				.Type = COM_CATHODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN10 , GPIOA_Port}
		},

		{
				.Type = COM_CATHODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN11 , GPIOA_Port}
		},

		{
				.Type = COM_ANODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN12 , GPIOA_Port}
		},

		{
				.Type = COM_ANODE,
				.GPIO_tPin_A = {PIN0 , GPIOA_Port },
				.GPIO_tPin_B = {PIN1 , GPIOA_Port },
				.GPIO_tPin_C = {PIN2 , GPIOA_Port },
				.GPIO_tPin_D = {PIN3 , GPIOA_Port },
				.GPIO_tPin_E = {PIN4 , GPIOA_Port },
				.GPIO_tPin_F = {PIN5 , GPIOA_Port },
				.GPIO_tPin_G = {PIN6 , GPIOA_Port },
				.GPIO_tEnablePin = {PIN7 , GPIOA_Port}
		}

};

