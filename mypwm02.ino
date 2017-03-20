/*
  file: mypwm02.ino
  date: 20-Mar-2017
  by:   sarodp@yahoo.com ,Thailand

  
  NodeMCU --PWM Low Frequency SSR 220VAC Load Control
  ====================================================
  Turns on an AC Line Light Bulb as a heater
  with low frequency pwm concept.

  Use SSR G3MB 202P module as an AC line output module.
  
  1)OMRON G3MB 202P 
   -Solid State Relay with zero crossing input
   -220VAC, 1A output , 2A resistive fuse
  
    
  2)NodeMCU output wiring
 
  [SSR DC+] <---- 5VDC [pin VU]   //5V power supply from USB port
  [SSR DC-] <---- 0VDC [pin GND]  //power and signal ground
  [SSR CH1] <---- Dout [pin D2]   //3.3V output signal :High=on,Low=off
  [SSR CH2] <---- Dout [pin D3]   //3.3V output signal :High=on,Low=off spare

  
  3) SSR AC Load wiring
  
   line220VAC o------[Manual SW]------[AC LOAD1*]----|
                                                     |
                                                     | 
   line0VAC   o------[SSR A1]_/_[SSR B1]-------------|


   line220VAC o------[Manual SW]------[AC LOAD2*]----|
                                                     |
                                                     | 
   line0VAC   o------[SSR A2]_/_[SSR B2]-------------|


  
  4) AC Load1,2
    -intended loads function as heaters
    -test load = AC generic light bulbs
    -220VAC, 100W Test OK 
    -Max Load = 1A,220VAC by SSR spec.


  5) NodeMCU Potentiometer Input Wiring
    
     GND-----VR 10K-------+3.3V
               |
               |
             A0 PIN

    -use analog input [pin A0]
    -to adjust pwm output from 0% to 100%
   
*/



//nodemcu pins map
/*
static const uint8_t BUILTIN_LED = 16;
static const uint8_t LED_BUILTIN = 16;
static const uint8_t A0 = 17;
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;
*/

#define ACout1 D2
#define ACout2 D3
#define OFF LOW
#define ON HIGH


#define pwmperiod 500  //msec period

#define POTPIN A0    //Potentiometer 

#define POTMAX 90    //adcmax/10 = 9xx/10


uint pwmon;     //msec pwm on time interval
uint pwmoff;    //msec pwm off time interval

uint xval;
uint xpc;
uint xfull;

//========================================================

void setup() {
//0--init ADC  
// analogReference(EXTERNAL);
  
//1-- init pins Dout
  pinMode(ACout1, OUTPUT);
  pinMode(ACout2, OUTPUT);
  digitalWrite(ACout1 , OFF);
  digitalWrite(ACout2 , OFF);

//2--init serial0
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Test PWM Low frequency");
}


//========================================================

void loop() 
{

//1--read VR10K --> calc xpc pwmon,pwmoff
//read xval  
  xval = analogRead(POTPIN);
  
//xpc 
  xpc = xval * 10 / POTMAX;
  if (xpc > 100)  xpc = 100;          
  if (xpc < 0)  xpc = 0;          

//pwmon,pwmoff  
  xfull = pwmperiod / 100;
  
  pwmon = xpc * xfull;
  pwmoff = pwmperiod - pwmon;
  
      
//2--print current pwm output setting  
  Serial.println("");
  Serial.println("---------------------------");
  
  Serial.print("POT value= ");
  Serial.println(xval);
   
  Serial.print ("% pwm on = ");
  Serial.print (xpc);
  Serial.println ("%");

  Serial.print ("pwm period/on/off = ");
  Serial.print (pwmperiod);
  Serial.print ("msec ");
  Serial.print (pwmon);
  Serial.print ("msec ");
  Serial.print (pwmoff);
  Serial.println ("msec ");
 

//3---pwm.out 1 period
    //pwmon...    
    digitalWrite(ACout1, ON);     
    digitalWrite(ACout2, ON);     
    delay(pwmon);    
       
    //pwmoff...    
    digitalWrite(ACout1, OFF);    
    digitalWrite(ACout2, OFF);     
    delay(pwmoff);                

//99---next loop
 
}
