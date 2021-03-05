#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

#include "SPI_config.h"

typedef enum{
    Data_8bit,
    Data_16Bit
}DataFrameFormat_t;

typedef enum{
    Full_Duplex,
    Receive_Only
}RXONLY_t;

typedef enum{
    SSM_disable,
    SSM_enable
}SSM_t; // Software Slave Management

typedef enum{
    MSB_first,
    LSB_first
}FrameFormat_t; 

typedef enum{
    fclk_div_2,
    fclk_div_4,
    fclk_div_8,
    fclk_div_16,
    fclk_div_32,
    fclk_div_64,
    fclk_div_128,
    fclk_div_256
}BaudRate_t; 

typedef enum{
    SLAVE,
    MASTER
}SPI_Mode_t; 

typedef enum{
    idle_zero,
    idle_one
}CPOL_t; 

typedef enum{
    readThenWrite,
    writeThenRead
}CPHA_t;

typedef struct{

    CPHA_t  CPHA;
    CPOL_t  CPOL;
    SPI_Mode_t mode;
    BaudRate_t baudrate;
    FrameFormat_t frameFormat;
    RXONLY_t rxonloy;
    SSM_t ssm;
    DataFrameFormat_t dataFrameFormat;
    
}SPI_t;

extern const SPI_t HSPIArrayOfSPI [ NUM_OF_SPI ];

#endif
