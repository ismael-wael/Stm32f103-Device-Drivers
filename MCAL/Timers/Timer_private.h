#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_

typedef struct{
    u32 TIMx_CR1;
    u32 TIMx_CR2;
    u32 TIMx_SMCR;
    u32 TIMx_DIER;
    u32 TIMx_SR;
    u32 TIMx_EGR;
    u32 TIMx_CCMR1;
    u32 TIMx_CCMR2;
    u32 TIMx_CCER;
    u32 TIMx_CNT;
    u32 TIMx_PSC;
    u32 TIMx_ARR;
    u32 _;           //reserved
    u32 TIMx_CCR1;
    u32 TIMx_CCR2;
    u32 TIMx_CCR3;
    u32 TIMx_CCR4;
    u32 __;           //reserved
    u32 TIMx_DCR;
    u32 TIMx_DMAR;
}Timer_t;

#define     TIM2_BASE    ((volatile Timer_t*)0x40000000)
#define     TIM3_BASE    ((volatile Timer_t*)0x40000400)
#define     TIM4_BASE    ((volatile Timer_t*)0x40000800)

#endif
