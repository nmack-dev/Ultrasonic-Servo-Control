#include "pid.h"

/**
  * @brief Initializations PID controller struct
  * @param pid: Points to PIDController struct
  * @retval None
  */
void PIDController_Init(PIDController* pid)
{
    pid->integrator = 0.0;
    pid->prevError = 0.0;

    pid->Kp = 10.0;
    pid->Ki = 24.0;
    pid->Kd = 4.0;

    pid->tau = 0.01;

    pid->limMin = 1.0;
    pid->limMax = 2.0;

    pid->T = 0.01;

    pid->differentiator = 0.0;
    pid->prevMeasurement = 0.0;

    pid->out = 0.0;
}

/**
  * @brief Updates PID controller based on input measurement
  * @param pid: Points to PIDController struct
  * @param setpoint: Goal value
  * @param measurment: Actual value
  * @retval pid->out: PID calculation output
  */
float PIDController_Update(PIDController* pid, float setpoint, float measurement)
{
    /* Error Signal */
    float error = setpoint - measurement;

    /* Proportional */
    float proportional = pid->Kp * error;

    // Integral
    pid->integrator = pid->integrator + 0.5 * pid->Ki * pid->T * (error + pid->prevError);

    /* Anti-wind-up via dynamic integrator clamping */
    float limMinInt, limMaxInt;

    /* Compute integrator limits */
    if (pid->limMax > proportional)
    {
        limMaxInt = pid->limMax - proportional;
    }
    else
    {
        limMaxInt = 0.0;
    }

    if (pid->limMin < proportional)
    {
        limMinInt = pid->limMin - proportional;
    }
    else
    {
        limMinInt = 0.0;
    }

    /* Clamp Integrator */
    if (pid->integrator > limMaxInt)
    {
        pid->integrator = limMaxInt;
    }
    else if (pid->integrator < limMinInt)
    {
        pid->integrator = limMinInt;
    }

    /* Derivative */
    pid->differentiator = -(2.0f * pid->Kd * (measurement - pid->prevMeasurement)
                    + (2.0f * pid->tau - pid->T) * pid->differentiator)
                    / (2.0f * pid->tau + pid->T);

    /* Compute output and apply limits */
    pid->out = proportional + pid->integrator + pid->differentiator;

    if (pid->out > pid->limMax)
    {
        pid->out = pid->limMax;
    }
    else if (pid->out < pid->limMin)
    {
        pid->out = pid->limMin;
    }

    /* Store error and measurement for later use */
    pid->prevError = error;
    pid->prevMeasurement = measurement;

    /* Return controller output */
    return pid->out;
}
