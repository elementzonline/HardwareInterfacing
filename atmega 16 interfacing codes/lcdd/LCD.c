#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"


void lcd_init()	// fuction for intialize 
{

        
        LCD_PORT_DIR |= 0xFF; //Make LCD port output
        _delay_ms(500);
        dis_cmd(0x33);		//to initialize LCD 
        _delay_ms(100);
        dis_cmd(0x32);		//to initialize LCD 
        _delay_ms(100);
        dis_cmd(0x28);		//to initialize LCD in 2 lines, 5X8 dots and 4bit mode.
        _delay_ms(100);
        dis_cmd(0x0C);          // to set entire Display on, cursor on, blinking cursor on
        _delay_ms(100);
        dis_cmd(0x01);		// clear LCD
        _delay_ms(100);
        dis_cmd(0x06);          // to move cursor to right after each character display
        _delay_ms(100);
		dis_cmd(0x02);		// to set DDRAM Address to 0
        _delay_ms(200);
        
}
 
void dis_cmd(char cmd_value)
{
	char cmd_value1;
	
	cmd_value1 = cmd_value & 0xF0;		//mask lower nibble because PA4-PA7 pins are used. 
	lcdcmd(cmd_value1);			// send to LCD
        _delay_ms(10);
	cmd_value1 = ((cmd_value<<4) & 0xF0);	//shift 4-bit and mask
	lcdcmd(cmd_value1);			// send to LCD
}						
 
 
void dis_data(char data_value)
{
	char data_value1;
	
	data_value1=data_value&0xF0;
	lcddata(data_value1);
 
	data_value1=((data_value<<4)&0xF0);
	lcddata(data_value1);
}
 
void lcdcmd(char cmdout)
{
	LCD_PORT |= (cmdout|0x00);
        LCD_PORT &= (cmdout|0x0F);
	LCD_PORT |=en;
        LCD_PORT &= ~(rs|rw); 
	_delay_ms(1);
	LCD_PORT &= ~(en|rs|rw);
}
 
void lcddata(char dataout)
{
        LCD_PORT |= (dataout|0x00);
        LCD_PORT &= (dataout|0x0F);
        LCD_PORT |= rs|en;
        LCD_PORT &= ~rw;
	_delay_ms(1);
	LCD_PORT |= rs;
        LCD_PORT &= ~(en|rw);
}
 

//void delay_ms(unsigned int delay)
//{
//  unsigned int i;
//  for (i=0;i<delay;i++)
//    __delay_cycles(6000);
//
//}


void LCD_write_string_line1(char *data0)
{
        int jj = 0;
        dis_cmd(0x80);
	_delay_ms(20);
	while(data0[jj]!='\0')
	{
		dis_data(data0[jj]);
		_delay_ms(5);
		jj++;
	}
}
void LCD_write_string_line2(char *data1)
{
        int i=0;
	dis_cmd(0xC0);
        _delay_ms(20);
	i=0;
	while(data1[i]!='\0')
	{
		dis_data(data1[i]);
		_delay_ms(5);
		i++;
	}
        
}

void LCD_write_string(char LINE_INDEX,char addr,char *data0)
{
	if (LINE_INDEX == 1)
	{
		addr = addr + 0x80;
	}
	else
	{
		addr = addr + 0xC0;
	}
        int jj = 0;
        dis_cmd(addr);
	_delay_ms(20);
	while(data0[jj]!='\0')
	{
		dis_data(data0[jj]);
		_delay_ms(5);
		jj++;
	}
}

	
void LCD_write_string_custom(char addr,char *data0)
{
        int jj = 0;
        dis_cmd(addr);
	_delay_ms(20);
	while(data0[jj]!='\0')
	{
		dis_data(data0[jj]);
		_delay_ms(5);
		jj++;
	}
}

void CLEAR_LCD(char LINE_INDEX)
{
        if (LINE_INDEX == 1)
	{
		LCD_write_string_line1("                ");
	}
	else
	{
		LCD_write_string_line2("                ");
	}
}
