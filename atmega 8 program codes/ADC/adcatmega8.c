#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "main.h"
#include "adc.h"
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
	     _delay_ms(1000);
		adc_read = ReadADC(sel);
		if(adc_read>800)
		{
			PORTB = 0X00;
			sprintf(buffer,"normal\n");
			send2uart(buffer);
		}
		else
		{
			PORTB = 0XFF;
		
			sprintf(buffer,"fire detected\n");
			send2uart(buffer);
		}
		sprintf(character_array,"adc=%d\n",adc_read);
		send2uart(character_array);
	
		usart_putchar(0x0D);
	    usart_putchar(0x0A);
	}
}
