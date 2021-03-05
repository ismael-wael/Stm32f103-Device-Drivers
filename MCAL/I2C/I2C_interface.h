#ifndef _I2C_INTERFACE_H_
#define _I2C_INTERFACE_H_

#define WRITE		0
#define READ		1

void MI2C1_voidInit(void);
void MI2C1_voidSendChar(u8 u8Data);
u8 MI2C1_u8ReceiveChar(void);
void MI2C1_voidSendAddress(u8 u8Data , u8 u8Operation);
void MI2C1_voidStartCondition(void);
void MI2C1_voidrepeatedStart(void);
void MI2C1_voidStopCondition(void);

#endif
