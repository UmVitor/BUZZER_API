
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
