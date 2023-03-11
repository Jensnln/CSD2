#ifndef CALLBACK_H
#define CALLBACK_H
#include "addSynth.h"


class CustomCallback : public AudioCallback {
public:
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;
private:
  float samplerate = 44100;

  addSynth addSynth = addSynth(1);


  // Synth synth2 = Synth();
};

#endif //CALLBACK_H
