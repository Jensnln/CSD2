#include "callback.h"


void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
	addSynth1.init();
//    square.setSamplerate(samplerate);
//	sine.setSamplerate(samplerate);
//	sine.setFrequency(220);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  for (int i = 0; i < buffer.numFrames; ++i) {
    // write sample to buffer at channel 0, amp = 0.25
    buffer.outputChannels[0][i] = summedGetSample();
	buffer.outputChannels[1][i] = summedGetSample();
//    square.tick();
//	sine.tick();
//	synth1.tick();
  }

}

float CustomCallback::summedGetSample() {
	float value =
//	square.getSample();
//	sine.getSample();
	addSynth1.getSample();

	return value;
}
