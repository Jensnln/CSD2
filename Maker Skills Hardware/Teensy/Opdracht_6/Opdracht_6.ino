#include <Audio.h>
#include <SD.h>
//#include <Wire.h>
//#include <SPI.h>
//#include <SerialFlash.h>

AudioInputAnalog         adc1;           //xy=164,95
AudioAnalyzePeak         peak1;          //xy=317,123
AudioConnection          patchCord1(adc1, peak1);

const int ledpin = 23;
const int buttonpin = 0;
void setup() {
  AudioMemory(4);
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLDOWN);
}

void loop() {
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

}
