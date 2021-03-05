#ifndef     _USART_PRIVATE_H_
#define     _USART_PRIVATE_H_

typedef struct{
    u32 USART_SR;
    u32 USART_DR;
    u32 USART_BRR;
    u32 USART_CR1;
    u32 USART_CR2;
    u32 USART_CR3;
    u32 USART_GTPR;
}USART_t;

#define     USART1  ((volatile USART_t*)0x40013800);
#define     USART2  ((volatile USART_t*)0x40004400);
#define     USART3  ((volatile USART_t*)0x40004800);

#endif