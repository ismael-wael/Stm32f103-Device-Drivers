#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "LEDMTRX_private.h"
#include "LEDMTRX_interface.h"
#include "LEDMTRX_config.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"


extern HLEDMTRX LedmtrxArr [NUM_OF_LEDMTRX] = {
												1,
                                    			0,
												PIN0 , PIN1 , PIN2 , PIN3 , PIN4 , PIN5 , PIN6 , PIN7 ,
												GPIOA_Port,
												PIN0 , PIN1 ,PIN5 , PIN6 , PIN7 , PIN8 ,PIN9 , PIN10 ,
												GPIOB_Port,
                                  	  	  	  };
