#include <Audio.h>
#include <SD.h>
//#include <Wire.h>
//#include <SPI.h>
//#include <SerialFlash.h>

AudioInputAnalog         adc1;           //xy=164,95
AudioAnalyzePeak         peak1;          //xy=317,123
AudioConnection          patchCord1(adc1, peak1);

const int ledpin = 23;
const int buttonpin = 2;
int oldSwitchValue;
int currentSwitchValue;
int edge;
int ledState = 0;
void setup() {
  AudioMemory(4);
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
}

void loop() {

  /*
//    Serial.println(digitalRead(buttonpin));
  if (peak1.available()) {
    int monoPeak = peak1.read() * 30;

//    Serial.println(monoPeak);
    if (digitalRead(buttonpin) >= 1) {
      digitalWrite(ledpin, HIGH);
      Serial.println("Button On");
    } 
    if (monoPeak >= 30) {
      digitalWrite(ledpin, LOW);
      Serial.println("Button Off");
    }
  }
  */

  oldSwitchValue = currentSwitchValue;
  currentSwitchValue = digitalRead(buttonpin);
  
//  Serial.print("CSV:");
//  Serial.println(currentSwitchValue);
//  Serial.print("OSV: ");
//  Serial.println(oldSwitchValue);
  edge = currentSwitchValue - oldSwitchValue;
  if (edge == 1){
    
      Serial.print("Edge: ");
      Serial.println(edge);
  }
  if (edge == -1){
    digitalWrite(ledpin, ledState);
    ledState = !ledState;
      Serial.print("Edge: ");
      Serial.println(edge);
      delay(200);
  }

  

}
