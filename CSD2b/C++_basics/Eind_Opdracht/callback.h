#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "saw.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;
private:
  float samplerate = 44100;
  Sine sine = Sine();
  Square square = Square();
  Saw saw = Saw();
  Saw saw2 = Saw();

  // Synth synth2 = Synth();
};

#endif //CALLBACK_H
