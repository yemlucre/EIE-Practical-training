#include <REGX52.H>
#include "motor.h"

sbit s1	= 	P1^3;
sbit s2	=	P1^2;
sbit s3	= 	P1^1;

void trace() 
{
	P1 |= 0x07;  // 只把低三位置 1，其他位保持不变
	if (s1 == 0 && s2 == 1 && s3 == 0) 
		{straight();} 
	else if ((s1 == 0 && s2 == 0 && s3 == 1 ) || (s1 == 0 && s2 == 1 && s3 == 1 )) 
		{turnleft();} 
	else if ((s1 == 1 && s2 == 1 && s3 == 0) || (s1 == 1 && s2 == 0 && s3 == 0 )) 
		{turnright();}
	else if (s1 == 0 && s2 == 0 && s3 == 0 ) 
		{straight(); } 
	else if (s1 == 1 && s2 == 1 && s3 == 1 ) 
		{stop();  } 
	else 
		{straight();}
}