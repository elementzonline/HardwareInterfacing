#ifndef _LCD_H__
#define _LCD_H__

#define LCD_PORT_DIR    DDRD         //LCD port direction   
#define LCD_PORT          PORTD	//LCD data port
 
//#define CTRL PORTB
//#define EN PIN2		// enable signal
//#define RW PIN1		// read/write signal
//#define RS PIN0		// register select signal


#define rs BIT0	          // register select signal
#define rw BIT1           // read/write signal
#define en BIT2           // enable signal

#define LINE1 1
#define LINE2 2
 
void lcd_init();
void dis_cmd(char);
void dis_data(char);
void lcdcmd(char);
void lcddata(char);
void delay_ms(unsigned int delay);
void LCD_write_string_line1(char *data0);
void LCD_write_string_line2(char *data1);
void LCD_write_string(char LINE_INDEX,char addr,char *data0);
void LCD_write_string_custom(char addr,char *data0);
void CLEAR_LCD(char line_index);

#endif
