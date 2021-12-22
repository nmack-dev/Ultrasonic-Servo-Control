/* PLL Address Definitions */
#define SYSCTL_RCC_R    (*((volatile unsigned long *)0x400FE060))
#define SYSCTL_RCC2_R   (*((volatile unsigned long *)0x400FE070))
#define SYSCTL_RIS_R    (*((volatile unsigned long *)0x400FE050))

/* Prototypes */
void PLL_Init(void);
