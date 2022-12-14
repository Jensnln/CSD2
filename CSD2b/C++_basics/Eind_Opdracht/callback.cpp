#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    sine.setSamplerate(samplerate);
    // square.setSamplerate(samplerate);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = 
    sine.getSample();
    // + 
    // square.getSample() +
    // saw.getSample() +
    // saw2.getSample();
    sine.tick();
    // square.tick();
    // saw.tick();
    // saw2.tick();
    // saw2.phaseCancel();
  }
}
