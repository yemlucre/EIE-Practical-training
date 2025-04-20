#include <REGX52.H>
#include "motor.h"
#include "delay.h"
#include "trace.h"

void main()
{
	UT_Init();
	Timer0Init();
	PWM(60,30);
	while(1)
	{
		trace();
	}
}