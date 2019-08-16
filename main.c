#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"

	int main(void)
{
		u8 t=0;//unsigned char
	u16 a,b,i,j;//unsigned short
	a=2000;
	b=1800;
	delay_init(); //延时函数初始化
	LED_Init(); //初始化与 LED 连接的硬件接口
	KEY_Init(); //初始化与按键连接的硬件接口
	//	BRRP_Init();蜂鸣器
	//LED0=0; //点亮 LED
	while(1)
	{
		t=KEY_Scan(0); //得到键值
		if(t)
		{
			switch(t)
			{
			case KEY1_PRES:
				for(i=0;i<2000;i++)
			{
				LED1=0;
				delay_ms(200);
				LED1=1;
				LED0=0;
				delay_ms(200);
				LED0=1;
				delay_ms(10);
			if(KEY1==0)
				break;
			}
			break;
			//流水灯
			case KEY0_PRES:
				delay_ms(10);
			for(j=0;j<2000;j++)
			{
				for(i=0;i<=a;i++)
				{
					LED0=0;
					LED1=0;
					delay(i);
					LED0=1;
					LED1=1;
					delay(a-i);
				if(KEY0==0)
					break;
			}
				for(i=0;i<b;i++)
			{
				LED0=0;
				LED1=0;
				delay(b-i);
				LED0=1;
				LED1=1;
				delay(i);
				if(KEY0==0)
					break;
			}
		}
	}
}
	else delay_ms(10);	
	}
}


