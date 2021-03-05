#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* ---------------------- Register Definitions ---------------------- */
typedef struct 
{
   volatile u32 CR;             /* Clock Control Register                   */
   volatile u32 CFGR;           /* Clock Configuration Register             */
   volatile u32 CIR;            /* Clock Interrupt Register                 */
   volatile u32 APB2RSTR;       /* APB2 Peripheral Reset Register           */
   volatile u32 APB1RSTR;       /* APB1 Peripheral Reset Register           */
   volatile u32 AHBENR;         /* AHB Perihperal Clock Enable Register     */
   volatile u32 APB2ENR;        /* APB2 Perihperal Clock Enable Register    */
   volatile u32 APB1ENR;        /* APB1 Perihperal Clock Enable Register    */
   volatile u32 BDCR;           /* Backup Domain Control Register           */
   volatile u32 CSR;            /* Control/Status Register                  */
}MRCC;

#define MRCC_Ptr ((volatile MRCC*) 0x40021000)

#endif