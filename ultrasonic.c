#include <REGX52.H>
#include "delay.h"
sbit Trig=P1^6;//定义超声波模块引脚
sbit Echo=P1^5;

void T1_Init()	// 定时计数器1初始化 
{
    TMOD &= 0x0F; // 清除高四位（定时器1的设置位）
    TMOD |= 0x10; // 设置定时器1为模式1（16位定时）
    TH1 = 0;      // 高 8 位初值
    TL1 = 0;      // 低 8 位初值
    ET1 = 1;      // 允许定时器1中断
    EA  = 1;      // 开总中断
}

	
void UT_Init()	//超声波模块初始化
{
    Echo=0;
    Trig=0;
    T1_Init();
}

/**
  *@beaf 超声波模块触发函数
  *@param 无
  *@retval 无
*/
void UT_triggr()
{
    Trig=1;
    Delay10us(2);
    Trig=0;    
}
/**
  *@beaf超声波测距
  *@param 无
  *@retval distance 测试的距离
*/
unsigned int measure()
{
    unsigned int a,distance;
    while(Echo==0);
        TR1=1;
    while(Echo);
        TR1=0;
    a=TH0*256+TL0;
       TH1=0;
       TL1=0;
    distance= a*1.7/100;
    return distance;        
}

void avoid()
{
	unsigned int left_dist,right_dist,distance;
	distance = measure();
	while(1)
	{
		if(distance < 20)  // 障碍物距离小于 20cm
		{
			stop();
			delay_ms(300);
			// 检查左边
			turnleft(); // 临时转向左边测距
			delay_ms(500); // 模拟探测方向调整时间
			distance = measure();
			left_dist = distance;
            // 再测右边
            turnright();
            delay_ms(1000); // 模拟探测方向调整
            distance = measure();
            right_dist = distance;
            // 回正方向
			turnleft();
			delay_ms(500);
            retreat();
            delay_ms(200);
            // 判断左右哪个更远，往远的方向转
            if(left_dist > right_dist)
            {
                turnleft();
                delay_ms(500);
            }
            else
            {
                turnright();
                delay_ms(500);
            }
		}
        else
        {
            straight();
        }

        delay_ms(100);
	}
}