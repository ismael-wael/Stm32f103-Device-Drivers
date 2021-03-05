#ifndef LEDMTRX_INTERFACE_H_
#define LEDMTRX_INTERFACE_H_

#define CONTROL_COLS		1
#define CONTROL_ROWS		0

#define MODE_ROWS_NEG		1
#define MODE_ROWS_POS		0

typedef struct{
	u8 ControlMode; /* either : 0 - control Rows
								1 - control Cols */

    u8 Mode;     /*  0 : Rows positive , Cols negative
     	 	 	 	 1 : Rows negative , Cols positive */

    u8 Row_Pin0;
    u8 Row_Pin1;
    u8 Row_Pin2;
    u8 Row_Pin3;
    u8 Row_Pin4;
    u8 Row_Pin5;
    u8 Row_Pin6;
    u8 Row_Pin7;

    u8 Row_Port;

    u8 Col_Pin0;
    u8 Col_Pin1;
    u8 Col_Pin2;
    u8 Col_Pin3;
    u8 Col_Pin4;
    u8 Col_Pin5;
    u8 Col_Pin6;
    u8 Col_Pin7;

    u8 Col_Port;

}HLEDMTRX;

void LedMtrx_voidInit(void);

void LedMtrx_voidDrawFrame(pu8 pu8_Frame , u8 u8LedMtrxNumber);

#endif
