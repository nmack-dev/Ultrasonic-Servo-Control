/* Port A Address Definitions */
#define GPIO_PORTA_DATA_R   (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R    (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R  (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_R    (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_DEN_R    (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_CR_R     (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R  (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R   (*((volatile unsigned long *)0x4000452C))
#define SYSCTL_RCGC2_R      (*((volatile unsigned long *)0x400FE108))

/* Prototypes */
void PortA_Init(void);
