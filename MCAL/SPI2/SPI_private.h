#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

typedef struct{
    u32 SPI_CR1;
    u32 SPI_CR2;
    u32 SPI_SR;
    u32 SPI_DR;

    u32 SPI_CRCPR;
    u32 SPI_RXCRCR;
    u32 SPI_TXCRCR;

    u32 SPI_I2SCFGR;
    u32 SPI_I2SPR;
}SPI;

#define SPI1_Base ((volatile SPI*)0x40013000)
#define SPI2_Base ((volatile SPI*)0x40003800)

#endif