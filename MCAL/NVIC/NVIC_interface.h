#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_


#define NO_SUB_PRIORITY 0

#define PEND_SV        -6
#define SYSTICK        -5

#define SV_CALL        -4

#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1


/* GROUP 3
Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 ); */

/* u8 Priority   = ( Copy_u8SubPriority | (Copy_u8GroupPriority << 4) );
 0x100 Hex  ---> 256 Decimal */
#define MNVIC_4_GROUP_0_SUB     0x05FA0300   //0 bit for sub & 4 bit For group   << 0 [16 group priority , 0 sub-priority]
#define MNVIC_3_GROUP_1_SUB     0x05FA0400   //1 bit for sub & 3 bit For group   << 1 [8 group priority , 2 sub-priority for each group]
#define MNVIC_2_GROUP_2_SUB     0x05FA0500   //2 bit for sub & 2 bit For group   << 2 [4 group priority , 4 sub-priority for each group]
#define MNVIC_1_GROUP_3_SUB     0x05FA0600   //3 bit for sub & 1 bit For group   << 3 [2 group priority , 8 sub-priority for each group]
#define MNVIC_0_GROUP_4_SUB     0x05FA0700   //4 bit for sub & 0 bit For group   << 4 [0 group priority , 16 sub-priority for each group]


/* #define For Interrupt ID =  Position In Vector Table */
#define WWDG   0
#define EXTI0   6
#define EXTI1   7
#define EXTI5   23
#define EXTI6   23
#define EXTI7   23
#define EXTI8   23
#define EXTI9   23
#define TIM3	29
#define DMA_ID 11


/* Function that enables peripheral external interrupts from 0 to 59  */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntId);

/* Function that disables external interrupts from 0 to 59  */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntId);

/* Function that enables the pending flag for debugging  */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntId); 

/* Function that disables the pending flag for debugging  */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntId);

/* Function that reads the interrupt activity status flag  */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntId);

/* Function that sets the group and sub-group priority for the input peripheral-ID */
void MNVIC_voidSWSetPriority(s8 Copy_s8IntId , u8 Copy_u8GroupPri , u8 Copy_u8SubPri , u32 Copy_u32Group);


#endif 
