#ifndef LIB_BMNP_H_INCLUDED
#define LIB_BMNP_H_INCLUDED

#include "LIB_STDTypes.h"

#define BMNP_u8GetBit(VAR,Bitno)      (((VAR) >> (Bitno)) & 0x01)
#define GET_BIT(VAR,Bitno)            (((VAR) >> (Bitno)) & 0x01)
#define GETBIT(VAR,Bitno)             (((VAR) >> (Bitno)) & 0x01)

#define BMNP_u8ToggleBit( VAR, Bitno) (VAR) ^= (1 << (Bitno))
#define TOG_BIT( VAR, Bitno) 	      (VAR) ^= (1 << (Bitno))

#define BMNP_u8ClearBit(VAR,Bitno)    (VAR) &=~(1 << (Bitno))
#define CLR_BIT(VAR,Bitno)            (VAR) &=~(1 << (Bitno))

#define BMNP_u8SetBit(VAR,Bitno)      (VAR) |= (1 << (Bitno))
#define SET_BIT(VAR,Bitno)            (VAR) |= (1 << (Bitno))

#define conc(x0,x1,x2,x3,x4,x5,x6,x7)  conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(b0,b1,b2,b3,b4,b5,b6,b7) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define conc_2(x0,x1)	conchelper_2(x0,x1)
#define conchelper_2(s1,s2) s1##s2
 // printf("%d",conc_2(2,1)/3); ---> 7

//that macro function only works with integers
#define SWAP_INT(a,b)	do{\
							a ^= b;\
							b ^= a;\
							a ^= b;\
						  }while(0)

typedef union
{
    struct
    {
        u8 B0:1;
        u8 B1:1;
        u8 B2:1;
        u8 B3:1;
        u8 B4:1;
        u8 B5:1;
        u8 B6:1;
        u8 B7:1;
    }Bit;
    u8 Byte;
}Register;

#endif // LIB_BMNP_H_INCLUDED
