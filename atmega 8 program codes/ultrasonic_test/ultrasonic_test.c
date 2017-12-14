#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"
#include "com_def.h"
#include "uart.h"
#include "ultrasonic_trigger_echo.h"

char data_buffer[4],buffer[50];

int distance = 0,c_m=0,m_m=0;

int convert_cm(int value)
{
 c_m = value/10;
 //m_m = value%10;


  integer_to_char(c_m,data_buffer,3);
  send2uart(data_buffer);
  /*send2uart(".");
  integer_to_char(m_m,data_buffer,2);
  usart_putchar(data_buffer[1]);*/
  send2uart("cm");
  usart_putchar(0x0D);
  usart_putchar(0x0A);
  if(c_m<015)
  {
    sprintf(buffer,"OBSTACLE DETECTED\n");
	send2uart(buffer);
   }

}


int main(void)
{

_delay_ms(1000);
print_uart("OK");


DDRB&=~(BIT3);
PORTB |= BIT3;

init_Ultrasonic_sensor();

if((PINB&BIT3) == BIT3)
{
init_usart(BAUD_9600);
}
else
{
init_usart(BAUD_57600);
}

while(1)
{
	distance = get_distance_Ultrasonic_sensor();
	convert_cm(distance);
	_delay_ms(100);
}

}
