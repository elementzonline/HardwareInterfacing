#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#define BIT0 0x01
#define BIT1 0x02
int main()
{
  DDRD&=~BIT1;//switch
  DDRD|=BIT0;//relay
  PORTD&=~BIT0;
  while(1)
  {
    
	PORTD|=BIT1; 
	char input = (PIND&BIT1);
    if(input==(BIT1))
	{
	 
	  PORTD&=~BIT0;
    _delay_ms(1000);
	}
	else
	{
	  
	  PORTD|=BIT0;
	  _delay_ms(1000);
    }
    
   }
	
   return(0);
}
