#ifndef __motor_h
#define	__motor_h

void Timer0Init();
void PWM(float A,float B);
void turnleft();
void turnright();
void straight();
void stop();
void retreat();

#endif