/*
 * Ul_S.c
 *
 * Created: 2/2/2022 12:55:52 AM
 *  Author: Mohamed Elwakel
 */ 
#include "Ul_S.h"

void ULTRASONIC_INIT(void)
{
	PIN_MODE(PD7,OUTPUT);
	PWM_2_INIT();
	PWM_2_SET_DUTY_CYCLE(70);
	PWM_2_START();
	TCCR1A=0; //normal mode
	ICR1=0; //clr register
}
f32 ULTRASONIC_READ(void)
{
		TCCR1B=0x45;  // ICU rising edge
		TIFR = (1<<ICF1); //CLR flag
		while((TIFR&(1<<ICF1))==0); //wait for input capture flag
		f32 ticks=ICR1;
		TCCR1B=0x05;  // ICU falling edge
		TIFR = (1<<ICF1); //CLR flag
		while((TIFR&(1<<ICF1))==0); //wait for input capture flag
		ticks=ICR1-ticks;
		f32 Distance=(ticks*64)/58;   //0.064 *1000 time of tick in u.sec
		TIFR = (1<<ICF1); //CLR flag
		return Distance;
}