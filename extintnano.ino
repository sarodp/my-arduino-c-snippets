//=================================
// test external interrupt 
//file: extint.ino
// 
// by: sarodp@yahoo.com
//
// date: 22-mar-2017
//=====================================
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

#define INTmode  FALLING //LOW CHANGE FALLING RISING

const byte ledPin = LED_BUILTIN;
const byte int0Pin = 2;
const byte int1Pin = 3;

volatile byte state = LOW;  //sahred variables
volatile unsigned int counter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(int0Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(int0Pin), subint0, INTmode);

  Serial.begin(115200);
  Serial.println ("hello...");
  
}

void loop() {
  Serial.print("state/counter = ");
  Serial.print(state);
  Serial.print("/");
  Serial.println(counter);
  delay(1000);
    
}

void subint0() {
  state = !state;
  digitalWrite(ledPin, state);
  counter = counter+1;
}
