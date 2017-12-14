#ifndef F_CPU
#define F_CPU 8000000UL                 
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "main.h"
void main(void)
{


	DDRB|=((BIT6)|(BIT7)|(BIT4)|(BIT5));
	PORTB|=(BIT6)&&(BIT7)&&(BIT4)&&(BIT5);
	while(1)
	{
	     PORTB|=BIT4;
		 PORTB&=~BIT5;
     }
}
