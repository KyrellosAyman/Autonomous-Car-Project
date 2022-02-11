/*
 * DC_MOTOR.h
 *
 * Created: 31/12/2021 03:42:20 م
 *  Author: dell
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "STD.h"

void DC_MOTORS_INIT(void);
void DC_MOTORS_START(u8);
void DC_MOTORS_STOP(void);

#define FORWARD        0
#define BACKWARD       1
#define RIGHT          2
#define LEFT           3

#endif /* DC_MOTOR_H_ */