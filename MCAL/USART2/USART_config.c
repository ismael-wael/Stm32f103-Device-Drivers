#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"


                        /*ENABLE USART1*/
USART_INIT USARTs[3] = {{0 ,
                        /*SC1 : RE, TE, RXNEIE, TCIE, TXEIE, PEIE, PS, PCE, M, UE*/
                                 0,  0,      0,    0,     0,    0,  0,   0, 0,  0,     
                        /*SC2 : STOP*/
                                0,
                        /*SC3 : EIE*/ 
                                0,
                        /*BaudRate*/
                                0    },
                        /*ENABLE USART2*/            
                        {1
                        /*SC1 : RE, TE, RXNEIE, TCIE, TXEIE, PEIE, PS, PCE, M, UE*/
                                 1,  1,      0,    0,     0,    0,  0,   0, 0, 1,
                        /*SC2 : STOP*/
                                00,
                        /*SC3 : EIE*/ 
                                1
                        /*BaudRate*/
                            9600    },
                        /*ENABLE USART3*/            
                        {0
                        /*SC1 : RE, TE, RXNEIE, TCIE, TXEIE, PEIE, PS, PCE, M, UE*/
                                 0,  0,      0,    0,     0,    0,  0,   0, 0,  0,     
                        /*SC2 : STOP*/
                                0,
                        /*SC3 : EIE*/ 
                                0,
                        /*BaudRate*/
                                0    }};

