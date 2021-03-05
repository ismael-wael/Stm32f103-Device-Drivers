#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "Timer_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"

#include "NVIC_interface.h"

static void (*TIM3_Callback) (void) ;

void MTimer3_voidInit(void)
{
	/* counter prescaller */
	TIM3_BASE->TIMx_PSC = MTIMER3_PRESCALLER;

	/* auto-reload register value */
	TIM3_BASE->TIMx_ARR = MTIMER3_AUTO_RELOAD_REG;

	/* counter direction */
	#if MTIMER3_COUNTER_DIRECTION == UP_COUNTING
		TIM3_BASE->TIMx_CR1 &= ~(1<<4);
	#elif MTIMER3_COUNTER_DIRECTION == DOWN_COUNTING
		TIM3_BASE->TIMx_CR1 |= (1<<4);
	#endif

	/* one-pulse enable/disable */
	#if MTIMER_ONE3_PULSE_MODE == ONE_PULSE_DISABLE
		TIM3_BASE->TIMx_CR1 &= ~(1<<3);
	#elif MTIMER3_ONE_PULSE_MODE == ONE_PULSE_ENABLE
		TIM3_BASE->TIMx_CR1 |= (1<<3);
	#endif

	//enable counter/timer
	TIM3_BASE->TIMx_CR1 |= (1<<0);
}

void Mtimer3_voidSetInterval_ms(u32 Copy_u32Milli_seconds , void (*ptr) (void))
{
	//if clk is 8 MHz clk then prescaller 8000, will make period = 1 msec
	TIM3_BASE->TIMx_PSC = 7999;
	// how many ms till overflow ?
	TIM3_BASE->TIMx_ARR = Copy_u32Milli_seconds;
	//enable counter
	TIM3_BASE->TIMx_CR1 |=(1<<0);

	//Auto-reload preload enable
	TIM3_BASE->TIMx_CR1 |=(1<<7);

	TIM3_BASE->TIMx_DIER &=~(1<<3); // Counter is not stopped at update event

	TIM3_BASE->TIMx_DIER |=(1<<0); // Update interrupt enable

	TIM3_BASE->TIMx_EGR |=(1<<0); // Update generation

	MNVIC_voidEnableInterrupt(TIM3);

	TIM3_Callback = ptr;
}

void Mtimer4_voidDelay_us(u32 Copy_u32Micro_seconds)
{
	//if clk is 8 MHz clk then prescaller 8, will make period = 1 usec
	TIM4_BASE->TIMx_PSC = 7;
	// how many us till overflow ?
	TIM4_BASE->TIMx_ARR = Copy_u32Micro_seconds;
	//enable counter
	TIM4_BASE->TIMx_CR1 |=(1<<0);

	//wait till update flag is set
	while(GETBIT(TIM4_BASE->TIMx_SR,0) != 1);
	// clear update flag
	TIM4_BASE->TIMx_SR &=~(1<<0);

	//disable counter
	TIM4_BASE->TIMx_CR1 &=~(1<<0);
}


void Mtimer4_voidDelay_ms(u32 Copy_u32Milli_seconds)
{
	//if clk is 8 MHz clk then prescaller 8000, will make period = 1 msec
	TIM4_BASE->TIMx_PSC = 7999;
	// how many ms till overflow ?
	TIM4_BASE->TIMx_ARR = Copy_u32Milli_seconds;
	//enable counter
	TIM4_BASE->TIMx_CR1 |=(1<<0);

	//wait till update flag is set
	while(GETBIT(TIM4_BASE->TIMx_SR,0) != 1);
	// clear update flag
	TIM4_BASE->TIMx_SR &=~(1<<0);

	//disable counter
	TIM4_BASE->TIMx_CR1 &=~(1<<0);
}

void TIM3_IRQHandler(void)
{
	// clear update flag, to generate another interrupt periodically
	TIM3_BASE->TIMx_SR &=~(1<<0);

    /*if assigned to a function by user == not NULL (because NULL is the initiated value)*/
    if(TIM3_Callback != LSTY_NULL)
    {
        /*start executing the passed function by user*/
    	TIM3_Callback();
    }
}
