#include <stdint.h>
#include "pll.h"
#include "sysTick.h"
#include "gpioA.h"
#include "pwmA.h"
#include "hcsr04.h"
#include "pid.h"

/* Ultrasonic sensor defines */
#define TRIGGER_PIN     0x04
#define ECHO_PIN        0x80
#define MAX_DISTANCE    7.5

/* Servo motor signal pin */
#define SIGNAL_PIN      0x08

/* PID controller */
PIDController pid;

int main(void)
{
    /* Driver initializations */
	PLL_Init();
	SysTick_Init();
	PortA_Init();
	PIDController_Init(&pid);

	/* Ultrasonic sensor measurement */
	float measurement;

	/* Output to servo motor */
	float output;

	/* Ultrasonic sensor distance setpoint */
	float setpoint = 2;

	while(1)
	{
	    /* Obtain distance measurement */
	    measurement = measureDistanceCm(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

	    /* Set servo motor output from PID controller */
	    output = PIDController_Update(&pid, setpoint, measurement);

	    /* Set servo motor duty cylce */
	    setDutyCycle(SIGNAL_PIN, output);
	}
}
