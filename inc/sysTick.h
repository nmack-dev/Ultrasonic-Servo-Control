#include <stdint.h>

/* SysTick Address Definitions */
#define NVIC_ST_CTRL_R      (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile uint32_t *)0xE000E018))

/* Prototypes */
void SysTick_Init();
void SysTick_Wait(uint32_t delay);
void SysTick_Wait_float(float delay);
void SysTick_Wait1ms(uint32_t delay);
void SysTick_Wait10ms(uint32_t delay);
