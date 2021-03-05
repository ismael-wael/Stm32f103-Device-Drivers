#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

/*counter direction*/
#define UP_COUNTING		0
#define	DOWN_COUNTING	1

/*one Pulse mode enable disable*/
#define 	ONE_PULSE_ENABLE	1
#define 	ONE_PULSE_DISABLE	0

void MTimer3_voidInit(void);

/*these two API's don't need Timer_Init, nor any configuration
 * just enable the timer4 clk in RCC then use them
 *
 * timer4 clk int (RCC) : MRCC_enuEnableClock (APB1_BUS , TIM4_RCC);*/
void Mtimer4_voidDelay_us(u32 Copy_u32Micro_seconds);
void Mtimer4_voidDelay_ms(u32 Copy_u32Milli_seconds);

void Mtimer3_voidSetInterval_ms(u32 Copy_u32Milli_seconds , void (*ptr) (void));

#endif
