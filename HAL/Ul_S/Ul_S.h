/*
 * Ul_S.h
 *
 * Created: 2/2/2022 12:55:29 AM
 *  Author: Mohamed Elwakel
 */ 


#ifndef UL_S_H_
#define UL_S_H_
#include "APP/LIB/BIT_MATH.h"
#include "APP/LIB/STD.h"
#include "REG.h"
#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>

#include "LCD.h"
#include "TIMERS.h"

#define TIFR   (*((volatile u8*)0x58))
#define ICF1	5

void ULTRASONIC_INIT(void);
f32 ULTRASONIC_READ(void);



#endif /* UL_S_H_ */