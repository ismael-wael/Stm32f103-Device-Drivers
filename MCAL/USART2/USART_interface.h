#ifndef     _USART_INTERFACE_H_
#define     _USART_INTERFACE_H_

typedef struct{
    u16        : 2;        
    u16 RE     : 1; //Receiver enable (0 : disable , 1 : enable)
    u16 TE     : 1; //Transmitter enable (0 : disable , 1 : enable)
    u16        : 1; 
    u16 RXNEIE : 1; //RXNE interrupt enable
    u16 TCIE   : 1; //Transmission complete interrupt enable
    u16 TXEIE  : 1; //TXE interrupt enable
    u16 PEIE   : 1; //PE interrupt enable
    u16 PS     : 1; //Parity selection (0 : even parity , 1 : odd parity)
    u16 PCE    : 1; //Parity control enable
    u16        : 1; 
    u16 M      : 1; //Word length (0 : 8 bit Data , 1 : 9 bit Data)
    u16 UE     : 1; //USART enable (0 : disable , 1 : enable)
}Control_Register1;

typedef struct{
    u16        : 12;  
    u16 STOP   : 2; //STOP bits (00 : 1 stop bits, 01 : 0.5 stop bits, 10 : 2 stop bits, 11 : 1.5 stop bits)
}Control_Register2;

typedef struct{
    u16 EIE    : 1; //Error interrupt enable
}Control_Register3;

typedef struct{
    u8                  EN;

    Control_Register1   CR1;
    Control_Register2   CR2;
    Control_Register3   CR3;

    u32            baudRate;
}USART_INIT;

void MUSART_voidInit(u8 Copy_u8USART_Number);

void MSUART_voidTranmsitByte(u8 Copy_u8USART_Number, u8 Copy_u8Data);

void MSUART_voidTranmsitString(u8 Copy_u8USART_Number, u8* Copy_u8Data);

u8 MSUART_u8ReceiveByte(u8 Copy_u8USART_Number);

u8* MSUART_u8ReceiveString(u8 Copy_u8USART_Number);

#endif