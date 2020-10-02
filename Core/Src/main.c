/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body - EXAMPLE APLICATION for use of BUZZER API.
  ******************************************************************************
 *  This software is overwhelmed by the license MIT License, for any questions check the license file.
 *  Copyright (C) 2020  Vitor Barreto <vitorbarreto@ufmg.br> and Wagner Menezes Polycarpo <wagnosferato@gmail.com>
 *
  ******************************************************************************
 * This code was developed by with hardware: MFS4NUCLEO_64_STMF103 and  Softwares: STM32CubeMX and SW4STM32.
 * The LEDs an your respectively pins in BOARD: LED_D1 = PB5 |  LED_D2 = PB4 | LED_D3 = PB4
  ******************************************************************************
 * **Brief of how the application works**
 * So the idea is a sound traffic light for the visually impaired.
 * When the green LED is on, no sound is emitted, that means there is a flow of cars.
 * In the middle of the yellow LED period a sound signal r is emitted. Then the cycle is reset.
 * I keep warning that the traffic light will close (interrupting the flow of cars).
 * When the red LED is on, a two-tone beep is emitted warning that there is no car flow, enabling pedestrian flow.
 * Just before turning off the red LED and turning on the green LED, a single-tone beep is emitted warning that the
 * traffic light will open.
 *
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "BUZZER_API.h"


void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();


  while (1)
  {

	  uint8_t i;

	  HAL_GPIO_WritePin(GPIOB, LED_D1_Pin, GPIO_PIN_SET);   // Turn on the green LED with no sound.
	  HAL_Delay(7000);										// 7 seconds ON.
	  HAL_GPIO_WritePin(GPIOB, LED_D1_Pin, GPIO_PIN_RESET); // Turn off the green LED.

	  HAL_GPIO_WritePin(GPIOB, LED_D2_Pin, GPIO_PIN_SET);   // Turn on the yellow LED.
	  HAL_Delay(1500);
	  BUZZER_ON(TRUE);										//Turn ON the BUZZER with continuous sound.
	  HAL_Delay(1500);
	  BUZZER_OFF();											//Turn off the BUZZER
	  HAL_GPIO_WritePin(GPIOB, LED_D2_Pin, GPIO_PIN_RESET); //Turn off the yellow LED

	  HAL_GPIO_WritePin(GPIOB, LED_D3_Pin, GPIO_PIN_SET);   //Turn on the red LED.
	  for (i=0; i<7 ; i++){									//Turn on the buzzer with two tones,
		  BUZZER_OSC_ALARM(500);							//Inside the function exists two delays with 500ms of period, so the complete period of the function is 1s.
	  }
	  for (i=0; i<4 ; i++){									//Turn on the buzzer with 1 tones and a silent period.
		  BUZZER_OSC(300);
	  }
	  HAL_GPIO_WritePin(GPIOB, LED_D3_Pin, GPIO_PIN_RESET);	//Turn off the red LED.
  }

}

void SystemClock_Config(void)
{
	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	  /** Initializes the RCC Oscillators according to the specified parameters
	  * in the RCC_OscInitTypeDef structure.
	  */
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
		Error_Handler();
	  }
	  /** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
								  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	  {
		Error_Handler();
	  }
}

static void MX_GPIO_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStruct = {0};
	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	  HAL_GPIO_WritePin(GPIOB, LED_D3_Pin|LED_D2_Pin|LED_D1_Pin, GPIO_PIN_RESET);

	   /*Configure GPIO pins : LED_D3_Pin LED_D2_Pin LED_D1_Pin */
	   GPIO_InitStruct.Pin = LED_D3_Pin|LED_D2_Pin|LED_D1_Pin;
	   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	   GPIO_InitStruct.Pull = GPIO_NOPULL;
	   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

