#include "LIB_STDTypes.h"
#include "LIB_BMNP.h"

#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

void MI2C1_voidInit(void)
{
	/*I2c is initially disabled*/
	I2C1_Ptr->I2C_CR1 &= ~(1 << 0);

	/*2 MHz Clk*/
	I2C1_Ptr->I2C_CR2 |= (0x08 << 0);

	/*Sm mode*/
	I2C1_Ptr->I2C_CCR &=~(1<<15);

	/*clock control register*/
	I2C1_Ptr->I2C_CCR |= (0x28<<0);

	/*rise time configuration*/
	I2C1_Ptr->I2C_TRISE |= ( 0x09<<0);

	/*Disable ACK*/
	I2C1_Ptr->I2C_CR1 &= ~(1 << 10);

	/*I2c mode enabled*/
	I2C1_Ptr->I2C_CR1 &= ~(1 << 1);

	/*Enable I2c*/
	I2C1_Ptr->I2C_CR1 |= (1 << 0);
}

void MI2C1_voidSendChar(u8 u8Data)
{
	I2C1_Ptr->I2C_DR = u8Data;

	while(GETBIT(I2C1_Ptr->I2C_SR1 , 2) == 0);
}

void MI2C1_voidSendAddress(u8 u8Data , u8 u8Operation)
{
	I2C1_Ptr->I2C_DR = (u8Data << 1) | (u8Operation & 0x01) ;

	while(GETBIT(I2C1_Ptr->I2C_SR1 , 1) == 0);
}

u8 MI2C1_u8ReceiveChar(void)
{
    u8 u8DataReceived;
    
    while(GETBIT(I2C1_Ptr->I2C_SR1 , 6) == 0);

    u8DataReceived = (u8)I2C1_Ptr->I2C_DR;

    return u8DataReceived;
}

void MI2C1_voidStartCondition(void)
{
	/*Send Start Condition*/
	I2C1_Ptr->I2C_CR1 |= (1 << 8);

	/* wait till start condition generated bit is set */
	while(GETBIT(I2C1_Ptr->I2C_SR1 , 0) == 0);
}

void MI2C1_voidrepeatedStart(void)
{
	/*Send Repeated Start*/
	I2C1_Ptr->I2C_CR1 |= (1 << 8);
}

void MI2C1_voidStopCondition(void)
{
	/*Send Stop Condition*/
	I2C1_Ptr->I2C_CR1 |= (1 << 9);

	while(GETBIT(I2C1_Ptr->I2C_SR1 , 4) == 0);

	I2C1_Ptr->I2C_CR1 = I2C1_Ptr->I2C_CR1;
}
