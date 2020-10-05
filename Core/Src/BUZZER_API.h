/*
 *  BUZZER_API.H
 *  This software is overwhelmed by the license MIT License, for any questions check the license file.
 *  Copyright (C) 2020  Vitor Barreto <vitorbarreto@ufmg.br> and Wagner Menezes Polycarpo <wagnosferato@gmail.com>
 *	This API was developed as a work in the discipline of Embedded Systems Programming at UFMG Prof. Ricardo de Oliveira Duarte - Department of Electronic Engineering
 *  Version 1.0 - API with the following implemented functions:

    	void MX_TIM2_Init(void);
	void MX_TIM2_Init2(void);
	void BUZZER_ON(uint8_t select);
	void BUZZER_OFF(void);
	void BUZZER_OSC(uint32_t period);
	void BUZZER_OSC_ALARM(uint32_t period);
 *
 *  This API was developed by with hardware: MFS4NUCLEO_64_STMF103 and  Softwares: STM32CubeMX and SW4STM32
 *
 *   You can find an example of how to use this API in: https://github.com/UmVitor/BUZZER_API
 */
#ifndef BUZZER_API_H_
#define BUZZER_API_H_
#include <stdint.h>
#include "stm32f1xx_hal.h"

TIM_HandleTypeDef htim2;

#define TRUE 1
#define FALSE 0

void MX_TIM2_Init(void);
void MX_TIM2_Init2(void);

void BUZZER_ON(uint8_t select);
void BUZZER_OFF(void);
void BUZZER_OSC(uint32_t period);
void BUZZER_OSC_ALARM(uint32_t period);


#endif /* MFS4NUCLEO_64_STMF103_H_ */
