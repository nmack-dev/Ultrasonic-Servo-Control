#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

/* PID Controller Struct */
typedef struct
{
    /* Controller Gains */
    float Kp;
    float Ki;
    float Kd;

    /* Derivative low-pass filter time constant */
    float tau;

    /* Output limits */
    float limMin;
    float limMax;

    /* Sample time (s) */
    float T;

    /* Controller memory */
    float integrator;
    float prevError;
    float differentiator;
    float prevMeasurement;

    /* Controller output */
    float out;

} PIDController;

/* Prototypes */
void PIDController_Init(PIDController* pid);
float PIDController_Update(PIDController* pid, float setpoint, float measurement);

#endif
