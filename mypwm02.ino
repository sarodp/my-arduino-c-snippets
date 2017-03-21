/*
  File: mypwm02.ino
  Date: 21-Mar-2017
  By:   sarodp@yahoo.com ,Thailand

  TDL:  delay(pwmon), delay(pwmoff) -> change to Timer Interupt

  =============================================================  
  PWM Low Frequency SSR 220VAC Load Control
  Module: NodeMCU or Arduino Nano 
  =============================================================
  Turns on an AC Line Light Bulb as a heater
  with low frequency pwm concept.

  Use SSR G3MB 202P module as an AC line output module.
  
  1)OMRON G3MB 202P 
   -Solid State Relay with zero crossing input
   -220VAC, 1A output , 2A resistive fuse
  
    
  2)output wiring
 NodeMCU
  [SSR DC+] <---- 5VDC [pin VU]   //5V power supply from USB port
  [SSR DC-] <---- 0VDC [pin GND]  //power and signal ground
  [SSR CH1] <---- ACout1 [pin D2]   //3.3V output signal :High=on,Low=off
  [SSR CH2] <---- ACout2 [pin D3]   //3.3V output signal :High=on,Low=off spare


 Arduiono Nano
  [SSR DC+] <---- 5VDC [pin VU]   //5V power supply from USB port
  [SSR DC-] <---- 0VDC [pin GND]  //power and signal ground
  [SSR CH1] <---- ACout1 [pin PD4]   //5V output signal :High=on,Low=off
  [SSR CH2] <---- ACout2 [pin PD5]   //5V output signal :High=on,Low=off spare

  
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


  5) Potentiometer Input Wiring

    NodeMCU
     GND-----VR 10K-------+3.3V
               |
               |
             A0 PIN

    Arduino Nano
     GND-----VR 10K-------+3.3V
               |
               |
             ADC0 PIN

    -use analog input [pin A0] or [pin ADC0]
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

// arduino nano DIO,ADC Pins
/*
D0 = PD0(TXD)
D1 = PD1(RXD)
D2 = PD2(INT0)
D3 = PD#(INT1)
D4 = PD4
D5 = PD5
D6 = PD6
D7 = PD7
D8 = PD8
D9 = PD9
D10 = PB2(SS')
D11 = PB3(MOSI)
D12 = PB4(MISO)
D13 = PB5(SCK)
A0 = PC0(ADC0)
A1 = PC1(ADC1)
A2 = PC2(ADC2)
A3 = PC3(ADC3)
A4 = PC4(SDA)
A5 = PC5(SCL)
A6 = ADC6
A7 = ADC7
*/

//#define ACout1 D2  //nodemcu
//#define ACout2 D3  //nodemcu
//#define POTPIN A0    //nodemcu Potentiometer  

#define ACout1 PD4  //arduino nano
#define ACout2 PD5  //arduino nano
#define POTPIN A0    //arduino nano Potentiometer  

#define OFF LOW
#define ON HIGH


#define pwmperiod 500  //msec period
#define POTMAX 90    //adcmax/10 = 9xx/10

int pwmon;     //msec pwm on time interval
int pwmoff;    //msec pwm off time interval

int xval;
int xpc;
int xfull;

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
