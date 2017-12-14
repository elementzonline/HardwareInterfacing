#include <avr/io.h>
#include <util/delay.h>
#include "com_def.h"
#include "main.h"
#include "ultrasonic_trigger_echo.h"


unsigned int echo_duration;

void init_Ultrasonic_sensor(void)
{
  Ultrasonic_Triger_Port_Direction |= (Ultrasonic_Trigger_pin);    // Ultrasonic Trigger pin
  Ultrasonic_Triger_Port &= ~(Ultrasonic_Trigger_pin);   // Ultrasonic pin set to low
  
  Ultrasonic_Echo_Port_Direction &= ~(Ultrasonic_Echo_pin);   // Ultrasonic Echo pin set to input
  Ultrasonic_Echo_Port |= Ultrasonic_Echo_pin;      // Enable pullup
}

void trigger_Ultrasonic_sensor(void)
{
    Ultrasonic_Triger_Port |= (Ultrasonic_Trigger_pin);
    _delay_us(10);
    Ultrasonic_Triger_Port &= ~(Ultrasonic_Trigger_pin);
}

unsigned int read_Ultrasonic_sensor(void)
{
    echo_duration = 0;   
    while((Ultrasonic_Echo_Input&Ultrasonic_Echo_pin) != Ultrasonic_Echo_pin);
    while(((Ultrasonic_Echo_Input&Ultrasonic_Echo_pin) == Ultrasonic_Echo_pin) && (echo_duration<20000))
    {
      _delay_us(1);
      echo_duration++;
    }
    return echo_duration;
}


unsigned int get_distance_Ultrasonic_sensor(void)
{
  trigger_Ultrasonic_sensor();
  return read_Ultrasonic_sensor()/SCALE_FACTOR;
}
