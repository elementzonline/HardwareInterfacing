#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "LCD.h"
int main()
{
  lcd_init();
  LCD_write_string_line1("HELLO WORLD");
  LCD_write_string_line2("test");
   
}
