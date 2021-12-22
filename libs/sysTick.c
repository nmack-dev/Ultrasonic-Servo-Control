#include "sysTick.h"

/**
  * @brief Intializes the SysTick clock
  * @param None
  * @retval None
  */
void SysTick_Init(void)
{
    NVIC_ST_CTRL_R = 0;             /* disable SysTick during setup */
    NVIC_ST_CTRL_R = 0x00000005;    /* enable SysTick with core clock */
}

/**
  * @brief Instantiates SysTick for a specified delay period
  * @param delay: Number of cycles to wait
  * @retval None
  */
void SysTick_Wait(uint32_t delay)
{
    NVIC_ST_RELOAD_R = delay - 1;                   /* number of counts to wait */
    NVIC_ST_CURRENT_R  = 0;                         /* resets current value */
    while ((NVIC_ST_CTRL_R  & 0x00010000) == 0) {}  /* wait for count flag */
}

/**
  * @brief Delays execution based on decimal number of ms
  * @param delay: Number of ms to delay (floating point)
  * @retval None
  */
void SysTick_Wait_float(float delay)
{
    uint32_t wait = 80000;
    SysTick_Wait(wait * delay);
}

/**
  * @brief Delays execution based on a ms delay
  * @param delay: Number of ms to delay
  * @retval None
  */
void SysTick_Wait1ms(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait(80000);   /* wait 10ms */
    }
}

/**
  * @brief Delays execution based on a 10ms delay
  * @param delay: Number of 10ms to delay
  * @retval None
  */
void SysTick_Wait10ms(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < delay; i++)
    {
        SysTick_Wait(800000);   /* wait 10ms */
    }
}
