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
	delay_init(); //��ʱ������ʼ��
	LED_Init(); //��ʼ���� LED ���ӵ�Ӳ���ӿ�
	KEY_Init(); //��ʼ���밴�����ӵ�Ӳ���ӿ�
	//	BRRP_Init();������
	//LED0=0; //���� LED
	while(1)
	{
		t=KEY_Scan(0); //�õ���ֵ
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
			//��ˮ��
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


