/* Mono Peak Meter

   Scrolling peak audio level meter in the Arduino Serial Monitor

   Audio input needs to connect to pin 16 (A2).  The signal range is 0 to 1.2V.
   See the documentation in the Audio System Design Tool for the recommended
   circuit to connect an analog signal.

   This example code is in the public domain
*/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=164,95
AudioAnalyzePeak         peak1;          //xy=317,123
AudioConnection          patchCord1(adc1, peak1);
AudioSynthWaveformSine   sine1;          //xy=314,307
AudioOutputAnalog        dac1;           //xy=510,307
AudioConnection          patchCord2(sine1, dac1);
// GUItool: end automatically generated code


int sensorPin = A0;
int ledPin = 23;
float sensorValue = 0;



void setup() {
  AudioMemory(36);
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

}

// for best effect make your terminal/monitor a minimum of 31 chars wide and as high as you can.

elapsedMillis fps;

void loop() {
    // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
//  Serial.println(sensorValue); // print the analogue value to the serial monitor
//  sine1.amplitude(sensorValue / 1024.0 * 1.0);
//  sine1.frequency((1024.0 - sensorValue) / 1024.0 * 440 * 2);



  if (fps > 24) {
    if (peak1.available()) {
      fps = 0;
      int monoPeak = peak1.read() * 30.0;
      Serial.print("|");
      for (int cnt=0; cnt<monoPeak; cnt++) {
        Serial.print(">");
      }
      Serial.println(monoPeak);
      analogWrite(ledPin, monoPeak / 30 * 255);
    }
  }
//  int monoPeak = peak1.read() * 30.0;


  

}
