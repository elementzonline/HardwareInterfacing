      
#ifndef _ULTRASONIC_TRIGGER_ECHO_H___
#define _ULTRASONIC_TRIGGER_ECHO_H___


#define SCALE_FACTOR      3

/* Defines common macro*/
#define CON_CAT(a,b)                a ## b
#define DDR_(name)        CON_CAT(DDR,name)
#define PORT_(name)       CON_CAT(PORT,name)
#define PIN_(name)        CON_CAT(PIN,name)
#define BIT_(name)        CON_CAT(BIT,name)

/*Need to change according to connections*/
#define ULTRASONIC_PORT_IND        B              /*need to configure here */
#define ULTRASONIC_TRIGGER         0               /*need to configure trigger pin(0-7) */
#define ULTRASONIC_ECHO            1               /*need to configure echo pin(0-7) */

/*  ULTRASONIC 1  */

#define Ultrasonic_Triger_Port_Direction            DDR_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Triger_Port                      PORT_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Trigger_pin                      BIT_(ULTRASONIC_TRIGGER)


#define Ultrasonic_Echo_Port_Direction              DDR_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Echo_Port                        PORT_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Echo_Input                       PIN_(ULTRASONIC_PORT_IND)
#define Ultrasonic_Echo_pin                         BIT_(ULTRASONIC_ECHO)

void init_Ultrasonic_sensor(void);
void trigger_Ultrasonic_sensor(void);
unsigned int read_Ultrasonic_sensor(void);
unsigned int get_distance_Ultrasonic_sensor(void);

#endif /* _ULTRASONIC_TRIGGER_ECHO_H___ */
