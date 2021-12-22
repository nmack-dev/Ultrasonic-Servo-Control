#include "gpioA.h"

/**
  * @brief Initializes GPIO pins for Port A
  * @param None
  * @retval None
  */
void PortA_Init(void)
{
    volatile unsigned long delay;

    SYSCTL_RCGC2_R |= 0x01;                 /* Activate Port A clock */
    delay = SYSCTL_RCGC2_R;

    GPIO_PORTA_PCTL_R &= ~0xFFFFFF00;       /* Regular GPIO initialization */
    GPIO_PORTA_AMSEL_R &= ~0xFC;            /* Disable analog */
    GPIO_PORTA_DIR_R |= 0x1C;               /* Set direction to output */
    GPIO_PORTA_DIR_R &= ~0xE0;              /* Set direction to input */
    GPIO_PORTA_AFSEL_R &= ~0xFC;            /* Regular port function */
    GPIO_PORTA_DEN_R |= 0xFC;               /* Enable digital */
}
