#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
//#include "main.h"
int main(void)
{
DDRA &= ~(0xFE);
PORTA |= 0xFF;
DDRB |= 0xFF;
//init_usart(BAUD_9600);
while(1)
{
if (PINA==0xFF)
{
  PORTB=0xFF;
  //send2uart("human presence\n\r");
}

else
{
  PORTB =0x00;
  //send2uart("no presence\n\r");
}
}
return 0;	
}
