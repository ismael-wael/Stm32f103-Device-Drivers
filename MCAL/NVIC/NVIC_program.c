#include "LIB_BMNP.h"
#include "LIB_STDTypes.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


/* Enable Peripheral Interrupt through "ISERx Reg" of NVIC */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntId)
{
    MNVIC_Ptr -> ISER [Copy_u8IntId / 32] = 1 << ( Copy_u8IntId % 32);
}


/* Disable Perihperal Interrupt through "ICERx Reg" of NVIC */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntId)
{
    MNVIC_Ptr -> ICER [Copy_u8IntId / 32] = 1 << (Copy_u8IntId % 32);
}

/*  Set Peripheral Pending Flag through "ISPRx Reg"  of NVIC */
/*used for testing / debugging without actually needing for interrupt to happen*/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntId)
{
    MNVIC_Ptr -> ISPR [Copy_u8IntId / 32] = 1 << (Copy_u8IntId % 32);
}

/* Clear Peripheral Pending Flag through "ICPRx Reg" of NVIC */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntId)
{
    MNVIC_Ptr -> ICPR [Copy_u8IntId / 32] = 1 << (Copy_u8IntId % 32);
}

/* Read Active Flag Status of a Peripheral through "IABRx Reg" of NVIC */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntId)
{
    u8 LOC_u8Active = GET_BIT( (MNVIC_Ptr -> IAPR [Copy_u8IntId/32]) , (Copy_u8IntId % 32));
	return LOC_u8Active;

}


/* Copy_s8PerIntID => Peripheral_ID || Copy_u8GroupPri => Setting group priority || Copy_u8SubPri => Setting sub-group priority
   MNVIC_GROUP_SUB_DISTRIBUTION => Distribution of groups/sub groups in IPR Register already predefined by user */
void MNVIC_voidSWSetPriority(s8 Copy_s8IntId , u8 Copy_u8GroupPri , u8 Copy_u8SubPri , u32 Copy_u32Group)
{
    u8 Local_u8Priority = Copy_u8SubPri | (Copy_u8GroupPri << ((Copy_u32Group - 0x05FA0300) / 256));
	//Core Peripheral
	if(Copy_s8IntId < 0)
    {
		if(Copy_s8IntId == MEMORY_MANAGE || Copy_s8IntId == BUS_FAULT || Copy_s8IntId == USAGE_FAULT)
        {
			Copy_s8IntId += 3;
			MSCB_Ptr -> SHPR1 = (Local_u8Priority) << ((8 * Copy_s8IntId) + 4);
		}
		else if ( Copy_s8IntId == SV_CALL )
        {
			Copy_s8IntId += 7;
			MSCB_Ptr -> SHPR2 = (Local_u8Priority) << ((8 * Copy_s8IntId) + 4);
		}
		else if (Copy_s8IntId == PEND_SV || Copy_s8IntId == SYSTICK )
        {
			Copy_s8IntId += 8;
			MSCB_Ptr -> SHPR3 = (Local_u8Priority) << ((8 * Copy_s8IntId) + 4);
		}
	}
    //External Peripheral
	else if (Copy_s8IntId >= 0)
    {
		MNVIC_Ptr -> IPR [Copy_s8IntId] = Local_u8Priority << 4;//shift because it's in high nibble
	}

	MSCB_Ptr -> AIRCR = Copy_u32Group ;

}
