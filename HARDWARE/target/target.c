#include "target.h"
#include "usart.h"
#include "delay.h"
#include "oled.h"
#include "sys.h"

u8 target_data[3];
u8 target_RGB[3]; 
u8 target_STA=1;
void target(void)
{
	while(target_STA)
	{	
		delay_ms(500);
		if(UART1_Process())
		{
			break;
		}
	}
	target_STA=1;
}

void RGB(void)
{
	while(target_STA)
	{	
		delay_ms(500);
		if(UART3_Process())
		{
			break;
		}
	}
	target_STA=1;
}
int UART1_Process(void)
{			
	u8 i,x;

	if(USART_RX_STA&0x8000)			      //串口1的接受判断，显示。
	{
		OLED_ShowString(0,2,"target:");
		for(x=50,i=0;i<3;i++)
		{
			x=x+10;
			target_data[i]= USART_RX_BUF[i]-0x30;
			OLED_ShowNum(x,2,target_data[i],1,16);	
		}	
		for(x=50,i=4;i<7;i++)
		{
			x=x+10;
			target_data[i]= USART_RX_BUF[i]-0x30;
			OLED_ShowNum(x,4,target_data[i],1,16);	
		}	
		USART_RX_STA=0; 
		target_STA=0;
		return 1;
	}
	else return 0;
} 
	
int UART3_Process(void)
{			
	u8 i,x;

	if(USART3_RX_STA&0x8000)			      //串口1的接受判断，显示。
	{
		OLED_ShowString(0,6,"RGB:");
		for(x=50,i=0;i<3;i++)
		{
			x=x+10;
			target_RGB[i]= USART3_RX_BUF[i]-0x30;
			OLED_ShowNum(x,6,target_RGB[i],1,16);	
		}		
		USART3_RX_STA=0; 
		target_STA=0;
		if(target_RGB[0]!=target_RGB[1]&&target_RGB[0]!=target_RGB[2]&&target_RGB[2]!=target_RGB[1]&&target_RGB[0]<4&&target_RGB[1]<4&&target_RGB[2]<4)
			return 1;
		else 
			return 0;
	}
	else return 0;
}