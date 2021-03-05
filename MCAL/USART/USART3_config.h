#ifndef USART3_CONFIG_H
#define USART3_CONFIG_H

/* USART3_Configuration */

/*  USART_3 Setting
     Options : - USART_ENABLE
               - USART_DISABLE  */
#define USART3_STATUS            USART_ENABLE

/* Fire an interrupt on Transmission 
    Options : - TRANSMITTER_DISABLE 
              - TRANSMITTER_ENABLE         */
#define USART3_TRANSMITTER       TRANSMITTER_ENABLE

/* Fire an interrupt on Receiving 
    Options : - RECEIVER_DISABLE 
              - RECEIVER_ENABLE         */
#define USART3_RECEIVER          RECEIVER_ENABLE

/*  Baud Rate Configuration
     Options : - BAUD_9600 
               - BAUD_115200  */
#define USART3_BAUD_RATE         BAUD_115200

/* Word Length 
    Options : - _8BIT_WORD_LENGTH
              - _9BIT_WORD_LENGTH  */
#define USART3_WORD_LENGTH       _8BIT_WORD_LENGTH

/* Parity Check Bit Setting
    Options: - PARITY_DISABLE
             - PARITY_ENABLE  */
#define USART3_PARITY           PARITY_DISABLE

/* Parity Check Bit Configuration
    Options: - USART_PARITY_EVEN
             - USART_PARITY_ODD  */
#define USART3_PARITY_TYPE       USART_PARITY_EVEN      

/* Parity Error Check flag Interrupt
    Options: - USART_PE_DISABLED
             - USART_PE_ENABLED  */
#define PARITY_ERROR_INTERRUPT     USART_PE_DISABLED

/* USART3 Interrupt Configuration 
    Options : - INT_DISABLE
              - TXE_INT_ENABLE
              - TCE_INT_ENABLE
              - RXNE_INT_ENABLE    */
#define USART3_INTERRUPT         INT_DISABLE

/* Stop Bit Configurations 
    Options : - ONE_STOP_BIT
              - HALF_STOP_BIT 
              - TWO_STOP_BIT
              - ONE_AND_HALF_STOP_BIT    */
#define USART3_STOP_BITS         ONE_STOP_BIT


#endif
