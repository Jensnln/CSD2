#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    synth1.setSampleRate(samplerate);
    synth1.setOscFrequency(100);
    sawSynth.setSampleRate(samplerate);
    sawSynth.setOscFrequency(220, 2);


//    pwmSynth.init(samplerate, 330, 4, 0.15);

    pwmSynth.setSampleRate(samplerate);
    pwmSynth.setOscFrequency(330);
    pwmSynth.setPwm(4, 0.15);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] =
            synth1.getSample() + sawSynth.getSample() + pwmSynth.getSample();

  buffer.outputChannels[1][i] =
          synth1.getSample() + sawSynth.getSample() + pwmSynth.getSample();

  synth1.tick();
  sawSynth.tick();
  pwmSynth.tick();

  }
}
