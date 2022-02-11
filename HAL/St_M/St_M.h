/*
 * St_M.h
 *
 * Created: 2/3/2022 1:38:55 AM
 *  Author: Mohamed Elwakel
 */ 


#ifndef ST_M_H_
#define ST_M_H_

#include "STD.h"
#include "REG.h"
#include "TIMERS.h"
#define F_CPU 16000000
#include <util/delay.h>

#define LEFT_DIRECTION 1
#define RIGHT_DIRECTION 20
#define FORWARD_DIRECTION 9

void SERVO_INIT (void);
void SERVO_ROTATE (u8);


#endif /* ST_M_H_ */