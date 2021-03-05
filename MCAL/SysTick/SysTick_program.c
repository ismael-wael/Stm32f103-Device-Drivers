#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

static void (*MSTK_Callback) (void) ;

/***********************************************************************************/

void MSTK_voidInit(void)
{
    /* Select Clock for systick*/
    #if SYSTIC_CLOCK_TYPE == SYSTICK_AHB
        MsysTick->STK_CTRL |=  (1 << CLKSOURCE);
    #elif  SYSTIC_CLOCK_TYPE == SYSTICK_AHB_DIV_8    
        MsysTick->STK_CTRL &=  ~(1 << CLKSOURCE);
	#else 
		#error "Invalid SysTick Configuration error"
    #endif

    /*Disable interrupt for systick*/
    MsysTick->STK_CTRL &=  ~(1 << TICINT);

    /*Disable the systick*/
    MsysTick->STK_CTRL &=  ~(1 << Enable);
}

/* Synchronous function to stop the processor from 
    doing anything untill the timer finish counting "Polling" 
	i/p : time in uSec */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    /*clear old value in value register*/
    MsysTick->STK_VAL = 0;
    /*disable interrupt*/
    MsysTick->STK_CTRL &=  ~(1 << TICINT);
    /*load the required value in load register*/
    MsysTick->STK_LOAD = Copy_u32Ticks;
    /*Enable systick*/
    MsysTick->STK_CTRL |=  (1 << Enable);
    /*poll till systick overflows*/
    while(((MsysTick->STK_CTRL >> COUNTFLAG) & 0x01) == 0);
    /*disable the interrupt*/
    MsysTick->STK_CTRL &=  ~(1 << Enable);
}

/* Asynchronous function to let the timer start counting and 
   fire an interrupt for only one time (call stopTimer at the end of the
   function passed to this API to make it single)
   if you don't it will keep firing interrupts [periodic]*/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*ptr) (void))
{
    /*clear old value in value register*/
    MsysTick->STK_VAL = 0;
    /*enable the interrupt because it's asynchronous event*/
    MsysTick->STK_CTRL |=  (1 << TICINT);
    /*load the required value in load register*/
    MsysTick->STK_LOAD = Copy_u32Ticks;
    /*Enable systick*/
    MsysTick->STK_CTRL |=  (1 << Enable);
    /*assign the local function to be executed when interrupt fires to ISR through
     this global pointer to function variable*/
    MSTK_Callback = ptr;
}

/* Asynchronous function to let the timer start counting and 
   fire an interrupt (it's by default will keep firing the interrupt,
   untill you call stopTimer API) */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*ptr) (void))
{
    /*clear old value in value register*/
    MsysTick->STK_VAL = 0;
    /*enable the interrupt because it's asynchronous event*/
    MsysTick->STK_CTRL |=  (1 << TICINT);
    /*load the required value in load register*/
    MsysTick->STK_LOAD = Copy_u32Ticks;
    /*Enable systick*/
    MsysTick->STK_CTRL |=  (1 << Enable);
    /*assign the local function to be executed when interrupt fires to ISR through
     this global pointer to function variable*/
    MSTK_Callback = ptr;
}

void MSTK_voidStopTimer(void)
{
    /*disbale systick*/
    MsysTick->STK_CTRL &=  ~(1 << Enable);
    /*disable interrupt*/
    MsysTick->STK_CTRL &=  ~(1 << TICINT);
}

void MSTK_voidResumeTimer(void)
{
    /*enable systick*/
    MsysTick->STK_CTRL |=  (1 << Enable);
    /*enable the interrupt because it's asynchronous event*/
    MsysTick->STK_CTRL |=  (1 << TICINT);
}

/* To get number of counts already been counted */
u32 MSTK_u32GetElapsedTime(void)
{
    /*initiated number of ticks - current number of ticks = counted ticks till now [count down register]*/
    u32 Local_u32ElapsedTime = MsysTick->STK_LOAD - MsysTick->STK_VAL;

    return Local_u32ElapsedTime;
}

/* To get the remaining counts prior the interrupt */
u32 MSTK_u32GetRemainingTime(void)
{
    /*read current number of ticks. that's what remain to reach 0*/
    u32 Local_u32RemainingTime = MsysTick->STK_VAL;

    return Local_u32RemainingTime;      
}

/* Read Systick flag */
u8 SysTick_u8ReadFlag(void)
{
	return (GET_BIT(MsysTick -> STK_CTRL , COUNTFLAG));
}

/*  ISR of Systick, called by hardware*/
void SysTick_Handler(void)
{
    /*if assigned to a function by user == not NULL (because NULL is the initiated value)*/
    if(MSTK_Callback != LSTY_NULL)
    {
        /*start executing the passed function by user*/
        MSTK_Callback();
    }
}
