#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "main.h"
#include "adc.h"

#include "LCD.h"
int main()
{
	DDRA |= BIT0;
	PORTA &= ~BIT0;
	char character_array[4];
	InitADC();
	unsigned char sel = 1;
	unsigned int adc_read;
	init_usart(BAUD_9600);
lcd_init();
LCD_write_string_line1("motor");
	while(1)
	{
		adc_read = ReadADC(sel);
		if(adc_read>700)
		{
			PORTA |= BIT0;
 LCD_write_string_line1("motor on"); 
		}
		else
		{
			PORTA &= ~BIT0;
LCD_write_string_line1("motor off");
	

		}
		integer_to_char(adc_read,character_array,4);
		send2uart(character_array);
LCD_write_string_line2("Moisture:");
		LCD_write_string(2,10,character_array);
		usart_putchar(0x0D);///r,carriage return
	    usart_putchar(0x0A);//new line
		_delay_ms(2000);
		CLEAR_LCD(1);
	}
}
