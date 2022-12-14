#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    synth1.setSampleRate(samplerate);
    synth1.setOscFrequency(100);
    sawSynth.setSampleRate(samplerate);
    sawSynth.setOscFrequency(220, 20);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] =
            synth1.getSample() + sawSynth.getSample();
            synth1.tick();
            sawSynth.tick();
  }
}
