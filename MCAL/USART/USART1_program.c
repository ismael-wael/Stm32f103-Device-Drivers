#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART1_config.h"


void MUSART1_voidInit(void)
{
    /* Set the Mantissa value of the Baud Rate 
		Mantissa = (F_CPU) / (16 * USART1_BAUD_RATE);
		Fraction = (((F_CPU * 100) / (16 * USART1_BAUD_RATE)) % 100) * 16 
		USART1_Ptr -> USART_BRR = (Mantissa << 4) | (Fraction / 100);
	If the value of fraction is > 1500, add one to Mantissa  
		if(Fraction > 1500)
		{ 
			Mantissa += 1; 
			Fraction = 0; 
		}	*/
	/* ------ BAUD Rate Configuration ------ */
	#if   USART1_BAUD_RATE == BAUD_9600
		    USART1_Ptr -> USART_BRR = 0x341;
	#elif USART1_BAUD_RATE == BAUD_115200
		    USART1_Ptr -> USART_BRR = 0x45;
	#endif
	
    /* ------ USART_1 Settings ------ */
	#if USART1_STATUS == USART_ENABLE

                /* Set the word size */
		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH       
					CLR_BIT(USART1_Ptr -> USART_CR1, 12);   

		#elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH
					SET_BIT(USART1_Ptr -> USART_CR1, 12);
		#endif

                /* ------ Parity Check Configuration ------ */
		#if   USART1_PARITY == PARITY_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 10);

		#elif USART1_PARITY == PARITY_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 10);
			#if   USART1_PARITY_TYPE == USART1_PARITY_EVEN
					CLR_BIT(USART1_Ptr -> USART_CR1, 9);
			#elif USART1_PARITY_TYPE == USART1_PARITY_ODD
					SET_BIT(USART1_Ptr -> USART_CR1, 9);
			#endif
			#if   PARITY_ERROR_INTERRUPT == USART_PE_DISABLED
					CLR_BIT(USART1_Ptr -> USART_CR1, 8);
			#elif PARITY_ERROR_INTERRUPT == USART_PE_ENABLED
					SET_BIT(USART1_Ptr -> USART_CR1, 8);
			#endif
		#endif
	

             /* ------ Tx/Rx Interrupt Configuration ------ */
		#if  USART1_INTERRUPT == INT_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 5);
					CLR_BIT(USART1_Ptr -> USART_CR1, 6);
					CLR_BIT(USART1_Ptr -> USART_CR1, 7);

		#elif USART1_INTERRUPT == TXE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 7);

		#elif USART1_INTERRUPT == TCE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 6);

		#elif USART1_INTERRUPT == RXNE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 5);
		#endif

            /* ------ USART_1 Trasmitter Configeration ------ */
		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 3);

		#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 3);
		#endif

            /* ------ USART_1 Trasmitter Configeration ------ */
		#if   USART1_RECEIVER == RECEIVER_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 2);

		#elif USART1_RECEIVER == RECEIVER_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 2);
		#endif

            /* ------ USART_1 Stop Bit Configeration ------ */
		#if   USART1_STOP_BITS == ONE_STOP_BIT
					CLR_BIT(USART1_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == HALF_STOP_BIT
					SET_BIT(USART1_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == TWO_STOP_BIT
					CLR_BIT(USART1_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT
					SET_BIT(USART1_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART1_Ptr -> USART_CR2, 13);
		#endif

		/* Enable USART_1 */
		SET_BIT(USART1_Ptr -> USART_CR1, 13);
		/* Reset the Status Register */
		USART1_Ptr -> USART_SR = 0; 

	#elif USART1_STATUS == USART1_DISABLE
		CLR_BIT(USART1_Ptr -> USART_CR1, 0);
	#endif
}

void MUSART1_voidTransmit(u8 Copy_u8Char )
{

	USART1_Ptr -> USART_DR = Copy_u8Char ;

	while( GET_BIT( USART1_Ptr -> USART_SR , 6 ) == 0 );

	CLR_BIT( USART1_Ptr -> USART_SR , 6 );
}

u8 MUSART1_u8Receive(u32 Copy_u32TimeOut)
{
	u8  LOC_u8Data  = 0 ;
	u32 LOC_TimeOut = 0 ;

	CLR_BIT ( USART1_Ptr -> USART_SR , 5);

	while( ( GET_BIT ( USART1_Ptr -> USART_SR , 5) == 0 ) && ( LOC_TimeOut < Copy_u32TimeOut ) )
	{
		LOC_TimeOut++;
	}

	if( LOC_TimeOut == Copy_u32TimeOut )
	{
		LOC_u8Data = 255;
	}
	else
	{

		LOC_u8Data = USART1_Ptr -> USART_DR;
	}

	return LOC_u8Data;
}






