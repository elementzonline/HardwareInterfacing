#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

void InitADC()
{
  ADMUX |= BIT6;               // For Aref=AVcc;
  
  ADCSRA |= (BIT7|BIT2|BIT1|BIT0);  //ADC Enable, ADC clock = Mainclock/128
                                    //ADC clock = 16MHz/128 = 125 KHz
  //ADCSRA |= (BIT7|BIT0);
}

unsigned int ReadADC(unsigned char ch)
{
   //Select ADC Channel ch must be 0-7
   ch = ch & 0x07;
   ADMUX |= ch;
   ADMUX &= (0xf8|ch);


   //Start Single conversion
   ADCSRA |= BIT6;

   //Wait for conversion to complete
    while(!(ADCSRA & BIT4));

   //Clear ADIF by writing one to it
   //Note you may be wondering why we have write one to clear it
   //This is standard way of clearing bits in io as said in datasheets.
   //The code writes '1' but it result in setting bit to '0' !!!

    ADCSRA |= BIT4;

   return(ADC);
}
