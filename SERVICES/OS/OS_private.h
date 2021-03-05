#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

typedef struct{

	u16  u16Periodicity               ;
	void ( *TaskHandler )( void )  ;
	u16  u16FirstDelay                ;
	u8   u8State                     ;

}TASK_TCB ;

#define TASK_READY       0
#define TASK_SUSPEND     1

void OS_VoidSchedular( void );

#endif /* OS_PRIVATE_H_ */
