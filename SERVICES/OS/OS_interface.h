#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

void OS_VoidStart( void );

void OS_VoidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay );

void OS_VoidSuspendTask ( u8 Copy_u8TaskID );
void OS_VoidResumeTask  ( u8 Copy_u8TaskID );
void OS_VoidDeleteTask  ( u8 Copy_u8TaskID );

#endif /* OS_INTERFACE_H_ */
