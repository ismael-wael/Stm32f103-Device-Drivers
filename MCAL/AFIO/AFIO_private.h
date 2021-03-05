#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/* Struct for the AFIO register mapping */
typedef struct {
	volatile u32 EVCR      ;    /* Event control register                       */
	volatile u32 MAPR      ;    /* remap and debug I/O configuration register   */
	volatile u32 EXTICRx[4] ;   /* External interrupt configuration registers   */
	volatile u32 MAPR2     ;    /* remap and debug I/O configuration register2  */
}AFIO_Type;

#define AFIO_Ptr  ((volatile AFIO_Type *) 0x40010000)

#endif
