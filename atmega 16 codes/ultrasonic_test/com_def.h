
#ifndef _COM_DEF_H__
#define _COM_DEF_H__

/*
Function	: 	void _delay_ms(long no_milliseconds);
Input args	: 	no: of milliseconds of delay
Output args	: 	none
Usage 		:	_delay_ms(500); // for 500 millisecond delay
Comments	:	
*/
//void _delay_ms(long no_milliseconds);
/*
Function	: 	void _delay_us(long no_microseconds);
Input args	: 	no: of microseconds of delay
Output args	: 	none
Usage 		:	_delay_us(500); // for 500 millisecond delay
Comments	:	
*/
//void _delay_us(long no_microseconds);

/*
Function	: 	void integer_to_char(unsigned char integer_input, unsigned char* character_array, char type);
Input args	: 	integer to be converted, output_array, number of digits
Output args	: 	none
Usage 		:	integer_to_char(my_integer,out_array,3) // for 3 digit output
Comments	:	Converts integer to character array, type 2 upto 99 
				type 3 upto 999
*/
void integer_to_char(int integer_input, char* character_array, char type);

/*
Function	: 	hex_to_char(unsigned char hex,unsigned char character_array[3]);
Input args	: 	hexadecimal value to be converted, output_array
Output args	: 	none
Usage 		:	hex_to_char(my_hex,out_array) // for 3 digit output
Comments	:	Converts hex - 0xA9 to "A9"
*/
/*
void hex_to_char(char hex,char character_array[3]);
*/
/*
Function	: 	char2num(char character);
Input args	: 	character between '0' and '9' converted to corresponding number
Output args	: 	number
Usage 		:	char2num(char character) // for 1 digit output
Comments	:	Converts '9' to 9
*/
/*
char char2num(char character);
*/
/*
Function	: 	map(long x, long in_min, long in_max, long out_min, long out_max);
Input args	: 	x-input, [input_max,min],[out_max,min]
Output args	: 	out mapped number
Usage 		:	int pwm_value = map(180,0,179,lower_bound,upper_bound); // for 1 digit output
Comments	:	val = map(90,0,179,125,625)    //returns 376
*/
/*
long map(long x, long in_min, long in_max, long out_min, long out_max);
*/
/*
Function	: 	char_to_int(char character_array[3], char type);
Input args	: 	number string array of size 'type'
Output args	: 	out integer number
Usage 		:	int char_to_int("1234", 4); // for 1 digit output
Comments	:	returns 1234    //returns integer
*/
/*
int char_to_int(char character_array[3], char type);
*/
#endif /* _COM_DEF_H__ */
