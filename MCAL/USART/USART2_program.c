#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART2_config.h"


void MUSART2_voidInit(void)
{
    /* Set the Mantissa value of the Baud Rate 
		Mantissa = (F_CPU) / (16 * USART2_BAUD_RATE);
		Fraction = (((F_CPU * 100) / (16 * USART2_BAUD_RATE)) % 100) * 16 
		USART2_Ptr -> USART_BRR = (Mantissa << 4) | (Fraction / 100);
	If the value of fraction is > 1500, add one to Mantissa  
		if(Fraction > 1500)
		{ 
			Mantissa += 1; 
			Fraction = 0; 
		}	*/
	/* ------ BAUD Rate Configuration ------ */
	#if   USART2_BAUD_RATE == BAUD_9600
		    USART2_Ptr -> USART_BRR = 0x341;
	#elif USART2_BAUD_RATE == BAUD_115200
		    USART2_Ptr -> USART_BRR = 0x45;
	#endif
	
    /* ------ USART_2 Settings ------ */
	#if USART2_STATUS == USART_ENABLE

                /* Set the word size */
		#if   USART2_WORD_LENGTH == _8BIT_WORD_LENGTH       
					CLR_BIT(USART2_Ptr -> USART_CR1, 12);   

		#elif USART2_WORD_LENGTH == _9BIT_WORD_LENGTH
					SET_BIT(USART2_Ptr -> USART_CR1, 12);
		#endif

                /* ------ Parity Check Configuration ------ */
		#if   USART2_PARITY == PARITY_DISABLE
					CLR_BIT(USART2_Ptr -> USART_CR1, 10);

		#elif USART2_PARITY == PARITY_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 10);
			#if   USART2_PARITY_TYPE == USART2_PARITY_EVEN
					CLR_BIT(USART2_Ptr -> USART_CR1, 9);
			#elif USART2_PARITY_TYPE == USART2_PARITY_ODD
					SET_BIT(USART2_Ptr -> USART_CR1, 9);
			#endif
			#if   PARITY_ERROR_INTERRUPT == USART_PE_DISABLED
					CLR_BIT(USART2_Ptr -> USART_CR1, 8);
			#elif PARITY_ERROR_INTERRUPT == USART_PE_ENABLED
					SET_BIT(USART2_Ptr -> USART_CR1, 8);
			#endif
		#endif
	

             /* ------ TX/RX Interrupt Configuration ------ */
		#if  USART2_INTERRUPT == INT_DISABLE
					CLR_BIT(USART2_Ptr -> USART_CR1, 5);
					CLR_BIT(USART2_Ptr -> USART_CR1, 6);
					CLR_BIT(USART2_Ptr -> USART_CR1, 7);

		#elif USART2_INTERRUPT == TXE_INT_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 7);

		#elif USART2_INTERRUPT == TCE_INT_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 6);

		#elif USART2_INTERRUPT == RXNE_INT_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 5);
		#endif

            /* ------ USART_2 Transmitter Configuration ------ */
		#if   USART2_TRANSMITTER == TRANSMITTER_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 3);

		#elif USART2_TRANSMITTER == TRANSMITTER_DISABLE
					CLR_BIT(USART2_Ptr -> USART_CR1, 3);
		#endif

            /* ------ USART_2 Receiver Configuration ------ */
		#if   USART2_RECEIVER == RECEIVER_ENABLE
					SET_BIT(USART2_Ptr -> USART_CR1, 2);

		#elif USART2_RECEIVER == RECEIVER_DISABLE
					CLR_BIT(USART2_Ptr -> USART_CR1, 2);
		#endif

            /* ------ USART_2 Stop Bit Configuration ------ */
		#if   USART2_STOP_BITS == ONE_STOP_BIT
					CLR_BIT(USART2_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART2_Ptr -> USART_CR2, 13);

		#elif USART2_STOP_BITS == HALF_STOP_BIT
					SET_BIT(USART2_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART2_Ptr -> USART_CR2, 13);

		#elif USART2_STOP_BITS == TWO_STOP_BIT
					CLR_BIT(USART2_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART2_Ptr -> USART_CR2, 13);

		#elif USART2_STOP_BITS == ONE_AND_HALF_STOP_BIT
					SET_BIT(USART2_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART2_Ptr -> USART_CR2, 13);
		#endif

		/* Enable USART_2 */
		SET_BIT(USART2_Ptr -> USART_CR1, 13);
		/* Reset the Status Register */
		USART2_Ptr -> USART_SR = 0; 

	#elif USART2_STATUS == USART2_DISABLE
		CLR_BIT(USART2_Ptr -> USART_CR1, 0);
	#endif
}

void MUSART2_voidTransmit(char* Word)
{
	u8 Local_u8Currentletter = 0;
	/* Loop as long as the character != NULL */
	while(Word[Local_u8Currentletter] != '\0')
	{
		/* Insert the character to Data Register */
		USART2_Ptr -> USART_DR = Word[Local_u8Currentletter];
		/* Hold for Transmission Completion */
		while((GET_BIT((USART2_Ptr -> USART_SR), 6)) == 0 );
		Local_u8Currentletter++;
	}
}

u8 MUSART2_u8Receive(u32 Copy_u32TimeOut)
{
	u32 TimeOut = 0;
	s8 Local_u8ReceivedData = 0;
	/* Hold till shift register has been transferred to the USART_DR register 
		and the RXNE flag is fired */
	while((GET_BIT((USART2_Ptr -> USART_SR), 5)) == 0)
	{
		/* variable that keeps counting to threshold value not to wait the 
			sender infinite time to send the data */
		TimeOut++;
		if (TimeOut == Copy_u32TimeOut)
		{
			/* Since this function return ASCII characters 0-127,
				So, it 255 returned, time out */
			Local_u8ReceivedData = 255;
			break;
		}
	}
	if(Local_u8ReceivedData == 0)
	{
		Local_u8ReceivedData = USART2_Ptr -> USART_DR;
	}
	return (Local_u8ReceivedData);
}






