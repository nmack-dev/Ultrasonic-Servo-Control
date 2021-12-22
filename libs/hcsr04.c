#include "hcsr04.h"

/**
  * @brief Gets pulse duration of echo signal
  * @param echoPin: Input GPIO pin for echo signal
  * @param maxDistanceDuration: Echo signal duration given a distance
  */
uint32_t getPulseDuration(uint8_t echoPin, uint32_t maxDistanceDuration)
{
    uint32_t pulseDuration = 0;
    uint32_t elapsed = 0;
    uint8_t latch = 0;

    while (elapsed <= maxDistanceDuration)
    {
        if ((echoPin & GPIO_PORTA_DATA_R) == echoPin)
        {
            latch = 1;
            pulseDuration++;
        }

        else if ((echoPin & GPIO_PORTA_DATA_R) != echoPin && latch == 1)
        {
            break;
        }

        SysTick_Wait_float(0.001);
        elapsed++;
    }

    return pulseDuration;
}

/**
  * @brief Measures distance from object to ultrasonic sensor
  * @param triggerPin: Pin to trigger sensor
  * @param echoPin: Modulated return signal
  * @param maxDistance: Maximum distance from object to sensor
  * @retval distance: Distance from object to sensor (cm)
  */
float measureDistanceCm(uint8_t triggerPin, uint8_t echoPin, uint32_t maxDistance)
{
    /* Duration in uS */
    uint32_t maxDistanceDuration;

    /* Generate trigger pulse */
    GPIO_PORTA_DATA_R &= ~triggerPin;
    SysTick_Wait_float(0.002);
    GPIO_PORTA_DATA_R |= triggerPin;
    SysTick_Wait_float(0.01);
    GPIO_PORTA_DATA_R &= ~triggerPin;

    /* Calculates speed of sound in cm / uS */
    float speedOfSound = 0.03313 + 0.0000606 * AIR_TEMPERATURE;

    /* Calculates the max duration of echo return signal */
    maxDistanceDuration = 2.5 * maxDistance / speedOfSound;

    /* Calculates duration */
    uint32_t duration = getPulseDuration(echoPin, maxDistanceDuration);

    /* Calculates distance from object to sensor */
    float distance = duration / 2.0 * speedOfSound;

    if (distance == 0 || distance > maxDistance)
    {
        return -1.0;
    }
    else
    {
        return distance;
    }

}
