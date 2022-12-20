#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "addSynth.h"
//#include "addSynth.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

  float summedGetSample();

private:
  float samplerate = 44100;
  //Sine sine = Sine(440, samplerate);
//  Square square = Square(440, samplerate);
//  Sine sine = Sine();
//  Synth synth1 = Synth(65);
  addSynth addSynth1 = addSynth(220, 10, 0);
};

#endif //CALLBACK_H
