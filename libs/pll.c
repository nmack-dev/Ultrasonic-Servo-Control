#include "pll.h"

/**
  * @brief Initializes PLL with external oscillator crystal
  * @param None
  * @retval None
  */
void PLL_Init(void)
{
    SYSCTL_RCC2_R |= 0x80000000;                    /* USERCC2 */
    SYSCTL_RCC2_R |= 0x00008000;                    /* BYPASS2, PLL bypass */
    SYSCTL_RCC_R = (SYSCTL_RCC_R &= ~0x000007C0)    /* clear XTAL field, bits 10-6 */
                   + 0x00000540;                    /* 10101, config 16Mhz crystal */

    SYSCTL_RCC2_R &= ~0x00000070;                   /* config main oscillator source */
    SYSCTL_RCC2_R &= ~0x00002000;                   /* activate PLL, clear PWRDN */

    SYSCTL_RCC2_R |= 0x40000000;                    /* use 400 MHz PLL */
    SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000)    /* clear system clock divider */
                    + (4<<22);                      /* configure for 80 MHz clock */

    while((SYSCTL_RIS_R&0x00000040)==0){};          /* wait for PLLRIS bit */

    SYSCTL_RCC2_R &= ~0x00000800;                   /* clear BYPASS and enable PLL */
}
