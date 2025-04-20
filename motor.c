#include <REGX52.H>

sbit ENA	= 	P2^5;
sbit IN1	=	P2^4;
sbit IN2	= 	P2^3;
sbit IN3	=	P2^2;
sbit IN4 	= 	P2^1;
sbit ENB	= 	P2^0;

unsigned char PWMA,PWMB;

void PWM(float A,float B)
{
	PWMA = A;
	PWMB = B;
}

void Timer0Init(void)		
{
	TMOD |= 0x01;
	TL0 = (65535-100)%256;
	TH0 = (65535-100)/256;
	TR0 = 1;		
	ET0 = 1;
	EA = 1;
}

void straight()	//PWM 15
{
	IN1 = 1;
	IN2 = 0;
//	PWMA = 15;
	IN3 = 1;
	IN4 = 0;
//	PWMB = 15;
}
void turnleft() //PWM 60
{
	IN1 = 0;
	IN2 = 1;
//	PWMA = 60;
	IN3 = 1;
	IN4 = 0;
//	PWMB = 60;
}
void turnright()	//PWM 60
{
	IN1 = 1;
	IN2 = 0;
//	PWMA = 60;
	IN3 = 0;
	IN4 = 1;
//	PWMB = 60;
}
void stop()	//PWM 0
{
	IN1 = 0;
	IN2 = 0;
//	PWMA = 0;
	IN3 = 0;
	IN4 = 0;
//	PWMB = 0;
}

void retreat()	//PWM 15
{
	IN1 = 0;
	IN2 = 1;
//	PWMA = 15;
	IN3 = 0;
	IN4 = 1;
//	PWMB = 15;
}

void T0isp() interrupt 1
{
	unsigned char i,j;
	TL0 = (65536-200)%256;		
	TH0 = (65536-200)/256;		
	i++;
	j++;
	if(i < PWMA)
	{
		ENA = 1;
	}
	else 
	{
		ENA = 0;
		if(i >= 100)
		{
			i = 0;
		}
	}
	if(j < PWMB)
	{
		ENB = 1;
	}
	else 
	{
		ENB = 0;
		if(j >= 100)
		{
			j = 0;
		}
	}
}


//int Position_PID (int Encoder,int Target)
//{ 	
//	 float Position_KP=26,Position_KI=0.05,Position_KD=0;
//	 static float Bias,Pwm,Integral_bias,Last_Bias;
//	 Bias=Target-Encoder;                                  //计算偏差
//	 Integral_bias+=Bias;	                                 //求出偏差的积分
//	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
//	 Last_Bias=Bias;                                       //保存上一次偏差 
//	 return Pwm;                                           //增量输出
//}

// void curbA(int pwmA)
// {
//                 read_pwmA=    Position_PID (Aspeed,100);
//                         if( read_pwmA>=0)
//                         {
//                                 if(read_pwmA>pwmA)
//                                 {
//                                         read_pwmA=pwmA;
//                                 }
//                         }
//                         else 
//                         {
//                         read_pwmA=-read_pwmA;
//                                 if(read_pwmA>pwmA)
//                                 {
//                                 read_pwmA=pwmA;
//                                 }
//                         }
// }

// void curbB(int pwmR)
// {
//                 read_pwmR=    Position_PID (right_speed,100);
//                         if( read_pwmR>=0)
//                         {
//                                 if(read_pwmR>pwmR)
//                                 {
//                                         read_pwmR=pwmR;
//                                 }
//                         }
//                         else 
//                         {
//                         read_pwmR=-read_pwmR;


//                                 if(read_pwmR>pwmR)
//                                 {
//                                 read_pwmR=pwmR;
//                                 }
//                         }
// }