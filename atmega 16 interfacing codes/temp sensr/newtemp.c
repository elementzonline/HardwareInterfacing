#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "main.h"
#include "adc.h"
unsigned int temp;
int main()
{
	DDRB = 0XFF;
	char character_array[4];
	InitADC();
	unsigned char sel = 1;
	unsigned int adc_read;
	init_usart(BAUD_9600);
    char buffer[50];
	while(1)
	{
	     _delay_ms(2000);
		adc_read = ReadADC(sel);
		temp=((adc_read*0.48828125));
		if(temp>30)
		{
		 PORTB=0XFF;
		 sprintf(buffer,"high\n");
		 send2uart(buffer);
         }
		 if(temp<30)
		{
		 PORTB=0X00;
		 sprintf(buffer,"low\n");
		 send2uart(buffer);
         }
		sprintf(character_array,"temp=%d\n",temp);
		send2uart(character_array);
	
		usart_putchar(0x0D);
	    usart_putchar(0x0A);
	}
}
