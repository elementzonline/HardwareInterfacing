#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

char rx_buffer[20];  //rx buffer chat length
char buff_index;

void init_usart(unsigned int baud)   
{   
    // USART initialization   
    // Communication Parameters: 8 Data, 1 Stop, No Parity   
    // USART Receiver: Off   
    // USART Transmitter: On   
    // USART Mode: Asynchronous   
    // USART Baud rate: baud   
    UCSRA=(0x00);   
    UCSRB=0x98;      // reciever disabled, receive interrrupt disabled, tx enabled   
    UCSRC=0x86;      // 8-bit mode   
    UBRRH=baud>>8;   
    UBRRL=baud;  
       
    //fdevopen(usart_putchar, NULL, 0);   
}
 
void usart_putchar(char data)   
{   
   while(!(UCSRA & BIT5));
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

void send_ATcommand(char *buffer)
{
  send2uart(buffer);
  usart_putchar(0x0D);
}

void print_uart(char *buffer)
{
  int i;
//  for (i=0;i<strlen(buffer);i++)
  for (i=0;buffer[i] != '\0' ;i++)
  usart_putchar(buffer[i]);
  usart_putchar(0x0D);
  usart_putchar(0x0A);
  }

/*
char process_uart_data(char uart_buffer)
{
  if(uart_buffer != 0x0D && uart_buffer != 0x0A)
  {
    rx_buffer[buff_index] = uart_buffer;
    buff_index++;
    return 0;
  }
  else
  {
    rx_buffer[buff_index]='\0';
    buff_index = 0;
    return 1;
  }
}
*/
