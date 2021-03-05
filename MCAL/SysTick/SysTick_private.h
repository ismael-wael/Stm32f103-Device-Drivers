#ifndef _SYSTICK_PRIVATE_
#define _SYSTICK_PRIVATE_

/*Cock Types*/
#define     SYSTICK_AHB             0
#define     SYSTICK_AHB_DIV_8       1

/*Control Register Pins*/
#define     Enable                  0
#define     TICINT                  1
#define     CLKSOURCE               2
#define     COUNTFLAG               16

typedef struct{
    u32 STK_CTRL;
    u32 STK_LOAD;
    u32 STK_VAL;
}SysTick_t;

#define   MsysTick  ((volatile SysTick_t*) 0xE000E010)

#endif
