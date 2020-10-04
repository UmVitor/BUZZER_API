# BUZZER_API
This repository contains a buzzer API in:

[![file1]][link_file1]
[![file2]][link_file2]

    Core/Src/BUZZER_API.c - Functions File.  
    Core/Src/BUZZER_API.h - Header File.

The following software was used to create this API: STM32CubeMx , SW4STM32.

Development kit used: NUCLEO_64_STMF103RB.

Buzzer is a piezoelectric device that vibrates according to the frequency of the input signal, thus
our goal is to set a timer that generates a PWM signal for the buzzer activation.

## How it works
First the clock frequency of the 8Mhz nucleus in HSI was set. With this, the timer 2(TIM2) channel 1 was chosen, which was configured to operate as PWM output. In the development kit, the output of this signal is at the pin: PA0.
Once this is done, we have configured the timer to generate a 1kHz or 500Hz PWM with a duty cycle of 50%. 

![alt text](https://raw.githubusercontent.com/UmVitor/BUZZER_API/master/Images/pwm.jpg)

You can easily calculate the timer parameters in this excel [spreadsheet][sheet].

## Example of application
[![file3]][link_file3]

Sound traffic light for blind people.

Basically, this project emits different patterns of sounds warning when the pedestrian is allowed to advance or when the traffic light will close.

### Pin Association 

PIN   | LABEL  | CONFIG      | ID
----- | ------ | ----------- | -----------  
PB5   | LED_D1 | GPIO_OUTPUT | GREEN LED
PB4   | LED_D2 | GPIO_OUTPUT | YELLOW LED
PB10  | LED_D3 | GPIO_OUTPUT | RED LED
PA0   | BUZZER | TIM2_CH1    | BUZZER



## References
AN2580 - Aplication Notes - STM32F10xxx TIM1 application examples.

RM0008 - Reference Manual STM32F103xx.

[sheet]: https://github.com/UmVitor/BUZZER_API/blob/master/timer_period_caclulation.xlsx
[file1]: https://img.shields.io/static/v1?label=Functions&message=API_BUZZER.c&color=red
[file2]: https://img.shields.io/static/v1?label=Header&message=API_BUZZER.h&color=blue
[file3]: https://img.shields.io/static/v1?style=flat-square&logo=appveyor&label=Aplication&message=main.c&color=blue
[link_file1]: https://github.com/UmVitor/BUZZER_API/blob/master/Core/Src/BUZZER_API.c
[link_file2]: https://github.com/UmVitor/BUZZER_API/blob/master/Core/Src/BUZZER_API.h
[link_file3]: https://github.com/UmVitor/BUZZER_API/blob/master/Core/Src/main.c
