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

};

#endif //CALLBACK_H
