#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "main.h"
#include <string.h>
int main(void)
{
DDRB &= ~BIT0;
PORTB |= 0xFF;
DDRC |= 0xFF;
init_usart(BAUD_9600);
char buffer[50];
while(1)
{
if ((PINB&BIT0)==BIT0)
{
  PORTC=0xFF;
  sprintf(buffer,"OBJECT DETECTED\n\r");
  send2uart(buffer);
  _delay_ms(500);
}

else
{
  PORTC =0x00;
  sprintf(buffer," NO OBJECT\n\r");
  send2uart(buffer);
  _delay_ms(500);
}
}
return 0;	
}
