#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_

/*timer prescaller can be any value between 0 and 65535
 *
 * note : in case of 0 it will work because automatically he adds 1 to the value
 * in the register
 *
 * example : if clk = 8 MHz, then to make counter increase / decrease by 1 every
 * 			1 us i will use prescaller of 7, because 7 + 1 = 8
 * 			8 Mhz / 8 = 1 MHz , period = 1 / freq = 1 usec */

#define	MTIMER3_PRESCALLER			7999

/*up-counting   :  0 ---> MTIMER_AUTO_RELOAD_REG
 *down-counting :  MTIMER_AUTO_RELOAD_REG ---> 0
 * */
#define MTIMER3_AUTO_RELOAD_REG		60000

/*
 * UP_COUNTING , DOWN_COUNTING */
#define MTIMER3_COUNTER_DIRECTION	UP_COUNTING

/* ONE_PULSE_ENABLE , ONE_PULSE_DISABLE */
#define MTIMER3_ONE_PULSE_MODE		ONE_PULSE_DISABLE

#endif
