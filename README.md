# BUZZER_API
This repository contains a buzzer API in:

    Core/Src/BUZZER_API.c - Functions File.  
    Core/Src/BUZZER_API.h - Header File.

The following software was used to create this API: STM32CubeMx , SW4STM32.

Development kit used: NUCLEO_64_STMF103RB.

Buzzer is a piezoelectric device that vibrates according to the frequency of the input signal, thus
our goal is to set a timer that generates a PWM signal for the buzzer activation.

## How it works.
First the clock frequency of the 8Mhz nucleus in HSI was set. With this, the timer 2(TIM2) channel 1 was chosen, which was configured to operate as PWM output. In the development kit, the output of this signal is at the pin: PA0.
Once this is done, we have configured the timer to generate a 1kHz or 500Hz PWM with a duty cycle of 50%, you can easily calculate the timer parameters in this excel spreadsheet.


## References
AN2580 - Aplication Notes - STM32F10xxx TIM1 application examples.

RM0008 - Reference Manual STM32F103xx.

