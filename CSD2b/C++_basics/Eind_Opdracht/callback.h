#ifndef CALLBACK_H
#define CALLBACK_H

#include "jack_module.h"
#include "addSynth.h"
#include "superSaw.h"
#include "PWMSynth.h"

class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;
private:
  float samplerate = 44100;
    addSynth synth1 = addSynth(0);
    superSaw sawSynth = superSaw(0);
    PWMSynth pwmSynth = PWMSynth(1);
};

#endif //CALLBACK_H
