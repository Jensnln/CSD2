#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

const int major_scale[8] = { 0, 2, 4, 5, 7, 9, 11, 12};

// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=170,149
AudioSynthWaveformSine   sine1;          //xy=264,373
AudioAnalyzePeak         peak1;          //xy=306,247
AudioEffectReverb        reverb1;        //xy=349,149
AudioEffectChorus        chorus1;        //xy=539,153
AudioMixer4              mixer1;         //xy=687,243
AudioOutputAnalog        dac1;           //xy=820,234
AudioConnection          patchCord1(adc1, reverb1);
AudioConnection          patchCord2(adc1, peak1);
AudioConnection          patchCord3(sine1, 0, mixer1, 1);
AudioConnection          patchCord4(reverb1, chorus1);
AudioConnection          patchCord5(chorus1, 0, mixer1, 0);
AudioConnection          patchCord6(mixer1, dac1);
// GUItool: end automatically generated code


const int ledPin = 23;
const int buttonpin = 2;
int oldSwitchValue;
int currentSwitchValue;
int edge;
float noteMultiplier = 1;

elapsedMillis fps;



void setup(){
  AudioMemory(32);
  Serial.begin(115200);
  pinMode(buttonpin, INPUT_PULLUP);
  sine1.frequency(220);
  sine1.amplitude(0.1);

}

void loop(){


    if (fps > 48 / noteMultiplier) {
    if (peak1.available()) {
      fps = 0;
      int monoPeak = peak1.read() * 30.0;
      Serial.print("|");
      sine1.frequency(110 * monoPeak / 2 * noteMultiplier);
      for (int cnt=0; cnt<monoPeak; cnt++) {
        Serial.print(">");
      }
      Serial.println(monoPeak);
      analogWrite(ledPin, monoPeak / 30 * 255);
    }
  }

  oldSwitchValue = currentSwitchValue;
  currentSwitchValue = digitalRead(buttonpin);
  edge = currentSwitchValue - oldSwitchValue;

  if (edge == 1){  
      Serial.print("Edge: ");
      Serial.println(edge);
      delay(50);
      noteMultiplier = 1;
  }
  if (edge == -1){

     noteMultiplier = 1.5;
      Serial.print("Edge: ");
      Serial.println(edge);
      delay(50);
  }
  
}

double midiToFrequency(int midiNote) {
  // MIDI note number to frequency conversion formula
  double frequency = pow(2, (midiNote - 69) / 12.0) * 440;
  return frequency;
}
