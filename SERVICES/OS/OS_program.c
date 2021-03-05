#include "LIB_STDTypes.h"

#include "SysTick_interface.h"

#include "OS_private.h"
#include "OS_interface.h"
#include "OS_config.h"

#define NULL 	0

static TASK_TCB OS_Tasks[ TASK_NUMBERS ] = { { NULL } };

void OS_VoidStart( void ){

	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(1000, OS_VoidSchedular);
}

void OS_VoidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay ){

	if( OS_Tasks[ Copy_u8Priority ].TaskHandler == NULL ){

		OS_Tasks[ Copy_u8Priority ].u16Periodicity = Copy_u16Periodicity ;
		OS_Tasks[ Copy_u8Priority ].TaskHandler = Copy_pvTask         ;
		OS_Tasks[ Copy_u8Priority ].u16FirstDelay  = Copy_u16FirstDelay  ;
		OS_Tasks[ Copy_u8Priority ].u8State       = TASK_READY          ;

	}
	else{

		/* Do No Thing */

	}

}

void OS_VoidSuspendTask ( u8 Copy_u8TaskID ){

	OS_Tasks[ Copy_u8TaskID ].u8State = TASK_SUSPEND ;

}

void OS_VoidResumeTask  ( u8 Copy_u8TaskID ){

	OS_Tasks[ Copy_u8TaskID ].u8State = TASK_READY   ;

}
void OS_VoidDeleteTask  ( u8 Copy_u8TaskID ){

	OS_Tasks[ Copy_u8TaskID ].TaskHandler = NULL ;

}


void OS_VoidSchedular( void ){

	u8 LOC_u8TaskCounter      ;

	for( LOC_u8TaskCounter = 0 ; LOC_u8TaskCounter < TASK_NUMBERS ; LOC_u8TaskCounter++ ){

		if( ( OS_Tasks[ LOC_u8TaskCounter ].TaskHandler != NULL ) && ( OS_Tasks[ LOC_u8TaskCounter ].u8State == TASK_READY ) ){

			if( OS_Tasks[ LOC_u8TaskCounter ].u16FirstDelay == 0 ){

				OS_Tasks[ LOC_u8TaskCounter ].u16FirstDelay = OS_Tasks[ LOC_u8TaskCounter ].u16Periodicity - 1 ;
				OS_Tasks[ LOC_u8TaskCounter ].TaskHandler();
			}
			else{

				OS_Tasks[ LOC_u8TaskCounter ].u16FirstDelay--;

			}

		}
		else{

			/* Do No Thing */

		}

	}

}


