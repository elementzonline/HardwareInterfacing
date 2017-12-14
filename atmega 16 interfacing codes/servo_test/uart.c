#include <avr/io.h>
#include <util/delay.h>


  
#ifndef F_CPU
#define F_CPU 8000000UL                    // set the CPU clock
#endif


//#include "iom16.h"
//#include <inavr.h>
#include "my_optim.c"


void init_usart(unsigned int baud)   
{   
    // USART initialization   
    // Communication Parameters: 8 Data, 1 Stop, No Parity   
    // USART Receiver: Off   
    // USART Transmitter: On   
    // USART Mode: Asynchronous   
    // USART Baud rate: baud   
    UCSRA=(0x00);   
    UCSRB=0x98;   
    UCSRC=0x86;   
    UBRRH=baud>>8;   
    UBRRL=baud;  
       
    //fdevopen(usart_putchar, NULL, 0);   
}
 
void usart_putchar(char data)   
{   
   while(!(UCSRA & BIT5));//if its '1' then pgm doesnt move.
   //Now write the data to USART buffer
   UDR=data;      
} 

void send2uart(char *buffer)
{
  int i;
//  for (i=0;i<strlen(buffer);i++)
  for (i=0;buffer[i] != '\0' ;i++)
  usart_putchar(buffer[i]);
}
