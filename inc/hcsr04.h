#include <stdint.h>
#include "gpioA.h"
#include "sysTick.h"

/* Air temperature constant */
#define AIR_TEMPERATURE 19.307

/* Prototypes */
uint32_t getPulseDuration(uint8_t echoPin, uint32_t maxDistanceDuration);
float measureDistanceCm(uint8_t triggerPin, uint8_t echoPin, uint32_t maxDistances);
