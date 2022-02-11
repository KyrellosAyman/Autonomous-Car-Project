/*
 * IncFile1.h
 *
 * Created: 1/31/2022 9:42:48 AM
 *  Author: Mohamed Elwakel
 */ 


#ifndef ICU_H_
#define ICU_H_

#include "STD.h"
#include "ICU_CFG.h"
#define NULL_PTR   0

typedef enum {
	NO_CLOCK,F_CPU_1,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum {
	FALLING,RISING
}Icu_Edge;

typedef struct
{
	Icu_Clock clock;
	Icu_Edge edge;
}Icu_ConfigType;

void ICU_init(const Icu_ConfigType * Config_Ptr);
void ICU_setCallBack(void (*a_Ptr)(void));
u16  ICU_getInputCaptureValue(void);
void ICU_setEdgeDetectionType(const Icu_Edge edge_type);
void ICU_clearTimer(void);
void ICU_disable(void);


#endif /* ICU_H_ */