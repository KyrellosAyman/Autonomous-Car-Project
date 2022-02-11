/*
 * St_M.c
 *
 * Created: 2/3/2022 1:39:11 AM
 *  Author: Mohamed Elwakel
 */ 

#include "St_M.h"


void SERVO_INIT (void)
{
	PWM_0_INIT();
}
void SERVO_ROTATE (u8 direction)
{
	PWM_0_SET_DUTY_CYCLE(direction);  
	PWM_0_START();
 
}