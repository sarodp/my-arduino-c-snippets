/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

//nodemcu pins map
/*
static const uint8_t BUILTIN_LED = 16;
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

#define Dout D2
#define D000 LED_BUILTIN

#define pwmperiod 2000  //msec period
#define pwmstep  200    //msec
#define nmax 10        //loop count 


//define Potentiometer ==============================================
// GND--Variable Resistor---+3.3V
//        |
//       A0 PIN
#define POTPIN A0         


uint pwmon;     //msec on
uint pwmoff;    //msec off
uint xval;
uint xpc;
// the setup function runs once when you press reset or power the board
void setup() {
  //0.init ADC  
  // analogReference(EXTERNAL);

  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Dout, OUTPUT);
  
  //2.init serial0
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() 
{
 //-----------
 if (pwmon >= pwmperiod){
   pwmon = 0;
 } 
  pwmon = pwmon + pwmstep;
  pwmoff = pwmperiod - pwmon;
  xpc = pwmon*100/pwmperiod;

//--read POTPIN
  xval = analogRead(POTPIN);
      
//------------  
  Serial.println("");
  Serial.println("---------------------------");
  
  Serial.print("POT value= ");
  Serial.println(xval);
  
  Serial.print ("pwm period = ");
  Serial.print (pwmperiod);
  Serial.println ("msec");
  
  Serial.print ("% pwm on = ");
  Serial.print (xpc);
  Serial.println ("%");

  for (int n = 0 ; n <= nmax; n += 1) 
  {
    Serial.print(n);
    digitalWrite(Dout, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(pwmon);                       // wait for a second
    digitalWrite(Dout , LOW);    // turn the LED off by making the voltage LOW
    delay(pwmoff);   // wait for a second
  }

 
}
