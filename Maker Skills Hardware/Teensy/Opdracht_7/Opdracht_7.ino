
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

void setup() {
  AudioMemory(4);
  Serial.begin(9600);
  sine1.amplitude(0.01);
  sine1.frequency(880 * 2);

}

void loop() {
  // put your main code here, to run repeatedly:

}
