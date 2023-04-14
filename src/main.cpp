#include <Arduino.h>

int pin_out = 3;
int dutyCycle = 0; // 0-255
String incomingString;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0){
    incomingString = Serial.readString();

    if (incomingString.equals("u")){
        if (dutyCycle <= 245){
        dutyCycle += 10;}
        analogWrite(pin_out, dutyCycle);
        Serial.print("Duty Cycle: ");
        Serial.println(dutyCycle);
    }
    if (incomingString.equals("d")){
        if (dutyCycle >= 10){
        dutyCycle -= 10;}
        analogWrite(pin_out, dutyCycle);
        Serial.print("Duty Cycle: ");
        Serial.println(dutyCycle);
    }
    if (incomingString.equals("z")){
        dutyCycle = 0;
        analogWrite(pin_out, dutyCycle);
        Serial.print("Duty Cycle: ");
        Serial.println(dutyCycle);
    }
    if (incomingString.equals("m")){
        dutyCycle = 125;
        analogWrite(pin_out, dutyCycle);
        Serial.print("Duty Cycle: ");
        Serial.println(dutyCycle);
    }
    if (incomingString.equals("f")){
        dutyCycle = 255;
        analogWrite(pin_out, dutyCycle);
        Serial.print("Duty Cycle: ");
        Serial.println(dutyCycle);
    
    }}}  