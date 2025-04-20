#include <REGX52.H>

void Delay10us(unsigned char t)//@11.0592MHz
{
	while(t--)
	{
	unsigned char i;
 
	i = 2;
	while (--i);

	}
}

//延时n毫秒
void delay_ms(unsigned int n)
{
    unsigned int i=0,j=0;
    for(i=0;i<n;i++)
        for(j=0;j<123;j++);
}

//延时n秒
void delay_m(unsigned int n)
{
    unsigned int i=0,j=0;
    for(i=0;i<n;i++)
        for(j=0;j<21738;j++);
}
