﻿/*
 * SSD.c
 *
 * Created: 10/12/2021 04:26:58 م
 *  Author: dell
 */ 
#include "SSD_CFG.h"
#include "DIO.h"
#define F_CPU 16000000
#include <util/delay.h>

void SSD_INIT(void)
{
	PIN_MODE(SSD_PIN_0,OUTPUT);
	PIN_MODE(SSD_PIN_1,OUTPUT);
	PIN_MODE(SSD_PIN_2,OUTPUT);
	PIN_MODE(SSD_PIN_3,OUTPUT);
	PIN_MODE(SSD_PIN_EN1,OUTPUT);
	PIN_MODE(SSD_PIN_EN2,OUTPUT);
}
void SSD_DISPLAY(u8 num)
{
	u8 num_1 = num % 10;
	u8 num_2 = num / 10;
	
	u8 i = 0;
	for(i=0;i<50;i++)
	{
		PIN_WRITE(SSD_PIN_EN1,HIGH);
		PIN_WRITE(SSD_PIN_EN2,LOW);
		switch(num_2)
		{
			case 0:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 1:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 2:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;		
			case 3:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;	
			case 4:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;	
			case 5:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;	
			case 6:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 7:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;	
			case 8:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,HIGH);
			break;	
			case 9:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,HIGH);
			break;	
			default:
			break;							
		}
		_delay_ms(10);
		PIN_WRITE(SSD_PIN_EN1,LOW);
		PIN_WRITE(SSD_PIN_EN2,HIGH);
		switch(num_1)
		{
			case 0:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 1:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 2:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 3:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 4:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 5:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 6:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 7:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,HIGH);
			PIN_WRITE(SSD_PIN_2,HIGH);
			PIN_WRITE(SSD_PIN_3,LOW);
			break;
			case 8:
			PIN_WRITE(SSD_PIN_0,LOW);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,HIGH);
			break;
			case 9:
			PIN_WRITE(SSD_PIN_0,HIGH);
			PIN_WRITE(SSD_PIN_1,LOW);
			PIN_WRITE(SSD_PIN_2,LOW);
			PIN_WRITE(SSD_PIN_3,HIGH);
			break;
			default:
			break;
		}
		_delay_ms(10);	
		PIN_WRITE(SSD_PIN_EN1,LOW);
		PIN_WRITE(SSD_PIN_EN2,LOW);
	}
}