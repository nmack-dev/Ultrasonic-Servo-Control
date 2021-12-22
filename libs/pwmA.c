#include "pwmA.h"

/**
  * @brief Sets duty cylce for PWM on Port A
  * @param pin: Port A pin
  * @param time: Duty cycle up-time
  * @retval None
  */
void setDutyCycle(uint8_t pin, float time)
{
    if ((time > 2 || time < 1) == 0)
    {
        GPIO_PORTA_DATA_R |= pin;
        SysTick_Wait_float(time);
        GPIO_PORTA_DATA_R &= ~pin;
        SysTick_Wait_float(20.0 - time);
    }
}
