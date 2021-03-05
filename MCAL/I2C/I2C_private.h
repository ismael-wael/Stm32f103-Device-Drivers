#ifndef _I2C_PRIVATE_H_
#define _I2C_PRIVATE_H_

typedef struct 
{
    u32 I2C_CR1;
    u32 I2C_CR2;
    u32 I2C_OAR1;
    u32 I2C_OAR2;
    u32 I2C_DR;
    u32 I2C_SR1;
    u32 I2C_SR2;
    u32 I2C_CCR;
    u32 I2C_TRISE;
}I2C_Regs;

#define    I2C1_Ptr ((volatile I2C_Regs *) (0x40005400))
#define    I2C2_Ptr ((volatile I2C_Regs *) (0x40005800))

#endif
