#include "jack_module.h"
#include <array>
#include <iostream>
#include "delay.h"
#include "sine.h"
#include "tremolo.h"
#include "utillities.h"
#include "waveshaper.h"
#include "chorus.h"


class Callback : public AudioCallback {
public:
    void prepare (int sampleRate) override {
		testSine.prepareToPlay(static_cast <double> (sampleRate));
		for(Chorus& chorus : chorusses){
			chorus.prepareToPlay(static_cast <double> (sampleRate));
		}
		for (WaveShaper& waveShaper: waveShapers){
			waveShaper.prepareToPlay(static_cast<double> (sampleRate));
			waveShaper.setDrive(20);
		}
		for (Sine& sine : sines){
			sine.prepareToPlay (static_cast<double> (sampleRate));
			sine.setDelta(440);
			std::cout << "Freq: " << sine.getFrequency() << std::endl;
		}
		for (Delay& delay : delays){
			delay.prepareToPlay(static_cast<double> (sampleRate));
			delay.setDistance(44100 * 0.5);
		}
		for (Tremolo& tremolo : tremolos){
			tremolo.prepareToPlay (static_cast<double> (sampleRate));
		}
		for(int i = 0; i < 20; i++){
			float j = 0;
			std::cout << "input: " << static_cast <float> (1.0f / float(i)) << std::endl;
			chorusses[1].process(static_cast <float> (1.0f / double(i)), j);
		}
    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;


        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
//				outputChannels[channel][sample] = sines[channel].output();
//				chorusses[channel].process(inputChannels[0][sample], outputChannels[channel][sample]);
//				chorusses[channel].process(sines[channel].output(), outputChannels[channel][sample]);
//				waveShapers[0].process(sines[channel].output(), outputChannels[channel][sample]);
//				tremolos[channel].process(outputChannels[channel][sample], outputChannels[channel][sample]);
//				delays[channel].process(inputChannels[0][sample], outputChannels[channel][sample]);
//				waveShapers[channel].process(outputChannels[channel][sample], outputChannels[channel][sample]);

            }
        }
    }

private:
	Sine testSine;
	std::array<Sine, 2> sines;
	std::array<Delay, 2> delays;
	std::array<Tremolo, 2> tremolos;
	std::array<WaveShaper, 2> waveShapers;
	std::array<Chorus, 2> chorusses;
};


int main() {
    auto callback = Callback {};
    auto jack = JackModule (callback);

    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
