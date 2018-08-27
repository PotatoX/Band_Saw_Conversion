//---Streaming---//
  #include <Streaming.h>
//---Streaming---//

//---PCF8574---//
#include "PCF8574.h"
#include <Wire.h>

//PCF8574 PCF_01(0x38);
PCF8574 PCF_01(0x20);
//---PCF8574---//

// initialize global variable
  double RPM = 0;
  double SFM = 0;
  
// the setup function runs once when you press reset or power the board
void setup() {
  
  //initialize digital display on I2C
  PCF_01.begin();
  
  // initialize digital pin 2 as DETECTOR_PIN
  #define DEBUG false
  #define REFRESH_RATE 500 //updates per second
  
  #define DETECTOR_PIN 2
  #define LED_PIN 3
  #define DIGIT_COUNT 4
  #define LAST_DIGITAL_PIN 7
  #define DISPLAY_1_ENABLE_PIN 7
  #define DISPLAY_2_ENABLE_PIN 6
  #define DISPLAY_3_ENABLE_PIN 5
  #define DISPLAY_4_ENABLE_PIN 4
  #define SFM_SLOPE 1.0644
  pinMode(DETECTOR_PIN, INPUT_PULLUP);
  pinMode(DISPLAY_1_ENABLE_PIN, OUTPUT);
  pinMode(DISPLAY_2_ENABLE_PIN, OUTPUT);
  pinMode(DISPLAY_3_ENABLE_PIN, OUTPUT);
  pinMode(DISPLAY_4_ENABLE_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // set digital display initial state
  digitalWrite(DISPLAY_1_ENABLE_PIN, HIGH);
  digitalWrite(DISPLAY_2_ENABLE_PIN, HIGH);
  digitalWrite(DISPLAY_3_ENABLE_PIN, HIGH);
  digitalWrite(DISPLAY_4_ENABLE_PIN, HIGH);

  // attach interput for detector
  attachInterrupt(digitalPinToInterrupt(DETECTOR_PIN), detectedPickup, FALLING);  

  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  // reset pickup led to LOW
  digitalWrite(LED_PIN, LOW);  

  // write out RPM to serial
  static unsigned long currentTime = millis();
  if(millis() - currentTime > 1.0/REFRESH_RATE/DIGIT_COUNT*1000)
  {
    currentTime = millis();

    // write RPM to serial    
    if( DEBUG )
    {
      RPM = 1234;
      Serial << "RPM: " << RPM << endl;  
    }

    // write out display serial  
    static int currentDigit = 1;
    static int lastDigit = DIGIT_COUNT;
    
    //disable digit  
    if( DEBUG )
      Serial << "Current Digit: " << currentDigit << endl;  

    //Convert RPM to SFM
    //RPM = 1000;
    SFM = RPM * SFM_SLOPE;
    
    //prepare current digit for display
    String RPMString;
    RPMString = (int) SFM;  
    RPMString = "0000" + RPMString;
    RPMString.remove(0,RPMString.length()-DIGIT_COUNT);
    if( DEBUG )
      Serial << "RPM String: " << RPMString << endl;
    RPMString = RPMString.charAt(DIGIT_COUNT - currentDigit);
    if( DEBUG )
      Serial << "RPM Char: " << RPMString << endl;
  
    //hide old digit
    digitalWrite(LAST_DIGITAL_PIN-lastDigit+1, HIGH);
    if( DEBUG )
      Serial << "Digital Pin " << LAST_DIGITAL_PIN-lastDigit+1 << ": HIGH" << endl;
      
    //write new digit        
    PCF_01.write8(~getDigit(RPMString.toInt()));
    //PCF_01.write8(~getDigit(currentDigit));
  
    //show new digit
    digitalWrite(LAST_DIGITAL_PIN-currentDigit+1, LOW);
    if( DEBUG )
      Serial << "Digital Pin " << LAST_DIGITAL_PIN-currentDigit+1 << ": LOW" << endl;
  
    //index and check digit count
    lastDigit = currentDigit;
    currentDigit += 1;
    if( currentDigit > DIGIT_COUNT )
      currentDigit = 1;  
  }

  // delay in between loop for stability
  if ( DEBUG )
    delay(1000);   
}

void detectedPickup()
{
  static unsigned long currentTime = millis();  
  static unsigned long lastTime = 0;

  // set the current time
  currentTime = millis();
  
  // setup array to store the last 10 values
  #define BUFFER_SIZE 10
  static unsigned long valueBuffer[BUFFER_SIZE] = {0};
  static int valueBufferPointer = 0;

  valueBuffer[valueBufferPointer] = currentTime - lastTime;

  // store the current time for use next cycle
  lastTime = currentTime;

  // average the buffer values
  unsigned long arraySum = 0;
  for(int i = 0; i < BUFFER_SIZE; i++)
  {
    arraySum += valueBuffer[i];
    if( DEBUG )
      Serial << "Array Value" << i + 1 << ": " << valueBuffer[i] << endl;
  }

  // calculate RPM (arrayAverage)
  double arrayAverage = arraySum / BUFFER_SIZE;

  // write RPM value to global variable
  RPM = 1000/arrayAverage*60;  
  if( DEBUG )
    Serial << "Buffer Pointer: " << valueBufferPointer << endl;

  // write pickup led HIGH
  digitalWrite(LED_PIN, HIGH);

  // reset pointer
  if (valueBufferPointer == BUFFER_SIZE - 1)
  {    
    valueBufferPointer = 0;
    if( DEBUG )
      Serial << "Buffer pointer reset." << endl;
  }
  else
  {
    valueBufferPointer += 1;
    if( DEBUG )
      Serial << "Increment pointer..." << endl;
  }
  
}

byte getDigit( int digit)
{
  #define DIGITAL_1 B00000110
  #define DIGITAL_2 B01011011
  #define DIGITAL_3 B01001111
  #define DIGITAL_4 B01100110
  #define DIGITAL_5 B01101101
  #define DIGITAL_6 B01111101
  #define DIGITAL_7 B00000111
  #define DIGITAL_8 B01111111
  #define DIGITAL_9 B01100111
  #define DIGITAL_0 B00111111 

  switch(digit)
  {
    case 0:
      return DIGITAL_0;
    
    case 1:
      return DIGITAL_1;
    
    case 2:
      return DIGITAL_2;
          
    case 3:
      return DIGITAL_3;
          
    case 4:
      return DIGITAL_4;
          
    case 5:
      return DIGITAL_5;
          
    case 6:
      return DIGITAL_6;
          
    case 7:
      return DIGITAL_7;
          
    case 8:
      return DIGITAL_8;
          
    case 9:
      return DIGITAL_9;
  }
}


