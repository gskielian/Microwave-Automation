/*
We will send '1' to the arduino to add time to the clock (in units of 30 seconds)
We will send '2' to the arduino to press the stop button
*/

//Relays are active low, so we'll just call "LOW" "On" from here on utilizing the #define protocol
#define ON LOW
#define OFF HIGH
#define StartButton 7
#define StopButton 8

//this is where we'll be storing user input
char ch;

void setup() {
  //set the control pins
  pinMode(StartButton, OUTPUT);
  pinMode(StopButton, OUTPUT);
  //end setting control pins
  
  //make sure the the buttons start off
  digitalWrite(StartButton, OFF);
  digitalWrite(StopButton, OFF);
  //end 
  
  //begin communication at speed of 9600
  Serial.begin(9600);   
  
}

void loop() {

  if (Serial.available()) 
  {
      ch = Serial.read();
      
      if ( ch == '1' ) 
      { 
        digitalWrite(StartButton,ON);
        delay(100);
        digitalWrite(StartButton,OFF);
        Serial.println('a');
      }
      else if (ch == '2') 
      {
        digitalWrite(StopButton,ON);
        delay(100);
        digitalWrite(StopButton,OFF);
        Serial.println( millis() );
      }
      else 
      {
        delay(100);
      }
  }
}
