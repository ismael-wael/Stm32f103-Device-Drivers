#ifndef _SYSTICK_INTERFACE_
#define _SYSTICK_INTERFACE_

void MSTK_voidInit(void);

/* Synchronous function to stop the processor from 
    doing anything untill the timer finish counting "Polling" 
	i/p : time in uSec */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

/* Asynchronous function to let the timer start counting and 
   fire an interrupt for only one time (diable systick in function passed to this API)*/
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*ptr) (void));

/* Asynchronous function to let the timer start counting and 
   fire an interrupt and repeating (don't diable systick in function passed to this API)*/
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*ptr) (void));

void MSTK_voidStopTimer(void);

void MSTK_voidResumeTimer(void);

/* To get number of counts already been counted */
u32 MSTK_u32GetElapsedTime(void);

/* To get the remaining counts prior the interrupt */
u32 MSTK_u32GetRemainingTime(void);
/* Read Systick flag */
u8 SysTick_u8ReadFlag(void);

#endif