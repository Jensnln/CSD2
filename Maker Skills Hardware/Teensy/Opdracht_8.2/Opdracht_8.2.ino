#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=314,307
AudioOutputAnalog        dac1;           //xy=510,307
AudioConnection          patchCord1(sine1, dac1);
// GUItool: end automatically generated code

int sensorPin = A0;
int ledPin = 23;
int sensorValue = 0;


void setup() {
  AudioMemory(4);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); // print the analogue value to the serial monitor
  sine1.amplitude(sensorValue / 1024.0 * 1.0);
  sine1.frequency((1024.0 - sensorValue) / 1024.0 * 440 * 2);
}
