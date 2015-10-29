/*
By Joe DeFabrizio

*/
#include <RCSwitch.h>

int fogPin = 4;
int ledPin = 13; 
// RC Receive on Pin 2
char inbyte = 0;

RCSwitch RCmessage = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(fogPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  RCmessage.enableReceive(0);  // Receiver on inerrupt 0 => that is pin 2
  RCmessage.setPulseLength(167);
}

void loop() {

if (Serial.available() > 0){
    inbyte = Serial.read();
    if (inbyte == '0'){
      digitalWrite(fogPin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(5000); // Hold for 5 seconds
      digitalWrite(fogPin, LOW);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
    if (inbyte == '1'){
      digitalWrite(fogPin, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(3000); // Hold for 3 seconds
      digitalWrite(fogPin, LOW);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
  }

// Check Manual RC
if (RCmessage.available()) {
  int value = RCmessage.getReceivedValue();
  switch (value) {
      case 22272:
        // Hall Received - Turn on Fog machine
        digitalWrite(fogPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(5000); // Hold for 5 seconds
        digitalWrite(fogPin, LOW);
        digitalWrite(ledPin, LOW);
        delay(200);
        RCmessage.resetAvailable();
        break;

      case 21516:
        // Lab Received - set manual control
        digitalWrite(fogPin, HIGH);
        digitalWrite(ledPin, HIGH);
        delay(3000); // Hold for 3 seconds
        digitalWrite(fogPin, LOW);
        digitalWrite(ledPin, LOW);
        delay(200);
        RCmessage.resetAvailable();
        break;
  }
}
}
