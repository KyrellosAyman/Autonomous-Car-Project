﻿/*
 * KEY_PAD.c
 *
 * Created: 17/12/2021 03:39:44 م
 *  Author: dell
 */ 
#include "KEY_PAD_CFG.h"
#include "DIO.h"

void KEY_PAD_INIT(void)
{
	PIN_MODE(KEY_PAD_X0,OUTPUT);
	PIN_MODE(KEY_PAD_X1,OUTPUT);
	PIN_MODE(KEY_PAD_X2,OUTPUT);
	PIN_MODE(KEY_PAD_X3,OUTPUT);
	
	PIN_WRITE(KEY_PAD_X0,HIGH);
	PIN_WRITE(KEY_PAD_X1,HIGH);
	PIN_WRITE(KEY_PAD_X2,HIGH);
	PIN_WRITE(KEY_PAD_X3,HIGH);
	
	PIN_MODE(KEY_PAD_Y0,INPUT);
	PIN_MODE(KEY_PAD_Y1,INPUT);
	PIN_MODE(KEY_PAD_Y2,INPUT);
	PIN_MODE(KEY_PAD_Y3,INPUT);
	
	PIN_PULL_UP_RES(KEY_PAD_Y0,ENABLE);
	PIN_PULL_UP_RES(KEY_PAD_Y1,ENABLE);
	PIN_PULL_UP_RES(KEY_PAD_Y2,ENABLE);
	PIN_PULL_UP_RES(KEY_PAD_Y3,ENABLE);
}
u8   KEY_PAD_READ(void)
{
	u8 r = 0;
	u8 c = 0;
	u8 reading = 1;
	for (r=KEY_PAD_X0 ; r<=KEY_PAD_X3 ; r++)
	{
		PIN_WRITE(r,LOW);
		for(c=KEY_PAD_Y0 ; c<=KEY_PAD_Y3 ; c++)
		{
			reading = PIN_READ(c);
			if(reading == 0)
			{
				return reading;
			}
		}
		PIN_WRITE(r,HIGH);
	}
}