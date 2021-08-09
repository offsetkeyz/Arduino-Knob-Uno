/*
Working code for knob analog and digital input

Author: Colin McAllister
*/

int pushButton = 12;
int LED = 8;

int volumeUp = 92;
int volumeDown = 170;
int counter = 0;

// knob input
int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(LED,OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  int knobReading = analogRead(sensorPin);
  if(knobReading < 1000) { //defaults to 1022 or 1023
    if (knobReading < 100) {
      counter = counter - 1;
    } else {
      counter = counter + 1;
    }
      Serial.println(counter);
      delay(150);
  }  
  delay(1);        // delay in between reads for stability

  //if button is pressed
if(buttonState == 0) {
   digitalWrite(LED,HIGH);
   delay(1000);
   digitalWrite(LED,LOW);
}
 
}
