/*
External dependencies
com_def.c

    PWM Motor 

1) TOWER PRO- MICRO SERVO SG90 (500 us to 2500 us)
#define upper_bound   312
#define lower_bound   62

2) VIGOR - VTS-08B (800 us to 2200 us)
#define upper_bound   275
#define lower_bound   100

3) VEGA - V3003 (600 us to 2400 us)
#define upper_bound   300
#define lower_bound   75

4) VEGA - V3006 (1500us to 1900 us)
#define upper_bound   275
#define lower_bound   90

us calculation

20 ms -- 

pwm_value == microseconds / (20000 /2500) 
*/


#ifndef _PWM_MOTOR_H___
#define _PWM_MOTOR_H___

#define MAX_ANGLE   179
#define MIN_ANGLE   0

#define upper_bound   275
#define lower_bound   90

#define PWM_1_SPEED   OCR1A
#define PWM_2_SPEED   OCR1B
#define Motor_PWM1     PWM_1_SPEED


void increase_speed_pwm1(int increment);
void decrease_speed_pwm1(int increment);
void change_speed_pwm1(int speed);
void init_hardware_pwm1(void);

#endif /* _PWM_MOTOR_H___ */
