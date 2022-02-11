/*
* GccApplication1.c
*
* Created: 03/12/2021 02:36:04
* Author : dell
*/

#include "STD.h"
#include "St_M.h"
#include "Ul_S.h"
#include "DC_MOTOR.h"
//#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

#define CRASH_DISTANCE 30

int main(void)
{
	// INITIALIZING THE MOTORS,SERVO,ULTRASONIC
	DC_MOTORS_INIT();
	SERVO_INIT();
	ULTRASONIC_INIT();
	
	// TO MAKE SURE THAT ULTASONIC IN THE FRONT POSITION
	SERVO_ROTATE(FORWARD_DIRECTION);
	_delay_ms(1000);
	
	// SETTING THE DIRECTION AND STARTING THE MOTORS
	DC_MOTORS_START(FORWARD);
	
	while(1)   ///super loop
	{
		u8 ULTRASONIC_READINGS_FRONT = ULTRASONIC_READ() ;
		u8 ULTRASONIC_READINGS_LEFT , ULTRASONIC_READINGS_RIGHT ;
		
		//CHECKING IF THE CAR WILL CRASH OR NO
		while( ULTRASONIC_READINGS_FRONT <= CRASH_DISTANCE )  //dir loop
		{
			//STOPING THE CAR SO IT WONOT CRASH
			DC_MOTORS_STOP();
			
			//CHECKING THE AREA WITH THE SERVO AND THE UTRASONIC
			SERVO_ROTATE(LEFT_DIRECTION);
			_delay_ms(1000);
			ULTRASONIC_READINGS_LEFT = ULTRASONIC_READ();
			
			SERVO_ROTATE(RIGHT_DIRECTION);
			_delay_ms(1000);
			ULTRASONIC_READINGS_RIGHT = ULTRASONIC_READ();
			
			SERVO_ROTATE(FORWARD_DIRECTION);
			_delay_ms(1000);
			
			//CHOOSING THE BEST ROUTE FOR THE CAR TO MOVE
			if ((ULTRASONIC_READINGS_LEFT > CRASH_DISTANCE) && (ULTRASONIC_READINGS_LEFT >= ULTRASONIC_READINGS_RIGHT))
			{
				//MOVING THE CAR IN LEFT DIRECTION
				DC_MOTORS_START(LEFT);
				_delay_ms(1000);
				
				DC_MOTORS_STOP();
				_delay_ms(1000);
				
				// SETTING THE DIRECTION AND STARTING THE MOTORS
				DC_MOTORS_START(FORWARD);
				break;
				
			}
			
			else if ((ULTRASONIC_READINGS_RIGHT > CRASH_DISTANCE) && (ULTRASONIC_READINGS_LEFT <= ULTRASONIC_READINGS_RIGHT))
			{
				//MOVING THE CAR IN RIGHT DIRECTION
				DC_MOTORS_START(RIGHT);
				_delay_ms(1000);
				
				DC_MOTORS_STOP();
				_delay_ms(1000);
				
				// SETTING THE DIRECTION AND STARTING THE MOTORS
				DC_MOTORS_START(FORWARD);
				break;
			}
			
			else
			{
				//REPEATING THE SAME STEPS AGAIN AND AGAIN UNTIL FINDING EXIT
				while(1)
				{
					//MOVING THE CAR BACKWARD
					DC_MOTORS_START(BACKWARD);
					_delay_ms(1000);
					
					DC_MOTORS_STOP();
					
					//CHECKING THE AREA AGAIN TO FIND ANOTHER ROAD TO GO
					SERVO_ROTATE(LEFT_DIRECTION);
					_delay_ms(1000);
					ULTRASONIC_READINGS_LEFT = ULTRASONIC_READ();
					
					SERVO_ROTATE(RIGHT_DIRECTION);
					_delay_ms(1000);
					ULTRASONIC_READINGS_RIGHT = ULTRASONIC_READ();
					
					SERVO_ROTATE(FORWARD_DIRECTION);
					_delay_ms(1000);
					
					//CHECKING THE LEFT AND THE RIGHT AREA AGAIN UNTIL FIND THE BEST ROAD
					if ((ULTRASONIC_READINGS_LEFT > CRASH_DISTANCE) && (ULTRASONIC_READINGS_LEFT >= ULTRASONIC_READINGS_RIGHT))
					{
						DC_MOTORS_START(LEFT);
						_delay_ms(1000);
						
						DC_MOTORS_STOP();
						_delay_ms(1000);
						
						// SETTING THE DIRECTION AND STARTING THE MOTORS
						DC_MOTORS_START(FORWARD);
						break;
					}
					
					else if ((ULTRASONIC_READINGS_RIGHT > CRASH_DISTANCE) && (ULTRASONIC_READINGS_LEFT <= ULTRASONIC_READINGS_RIGHT))
					{
						DC_MOTORS_START(RIGHT);
						_delay_ms(1000);
						
						DC_MOTORS_STOP();
						_delay_ms(1000);
						
						// SETTING THE DIRECTION AND STARTING THE MOTORS
						DC_MOTORS_START(FORWARD);
						break;	
					}	
				}
			}
		break;
		}
	}
	return 0;
}



/*
ISR(INT0_vect)
{
LED_OFF();
_delay_ms(1000);
}
*/
/*
ISR(TIMER0_OVF_vect)
{
static u16 counter = 0;
counter++;
if(counter == no_of_ov)
{
LED_TOG(LED_0);
counter = 0;
TCNT0 = 256 - rem_ticks;
}
}
*/
/*
ISR(TIMER0_COMP_vect)
{
static u16 counter = 0;
counter++;
if(counter == no_of_cm)
{
LED_TOG(LED_0);
counter = 0;
}
}
*/