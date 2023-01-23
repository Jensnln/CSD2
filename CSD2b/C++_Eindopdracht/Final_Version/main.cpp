// File name: main.ccp
// Making the synth playing it in the callback class.

#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "melody.h"
#include "synth.h"
#include "addSynth.h"
#include "sawSynth.h"
#include "pwmSynth.h"
#include "UI.h"


/*
 * NOTE: the development library with headers for jack2 needs to be installed to build this program.
 *
 * When built, before running the program start jackd, the JACK audio server daemon.
 *
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 *
 * start jackd : jackd -d <backend>
 * where backend is e.g. coreaudio (MacOS) or alsa (Linux)
 *
 * Alternatively there are graphical clients that start jackd.
 */


//Declaring synthbank here to be able to use it in the class scope and the main scope.
Synth* synthBank[1];

class Callback : public AudioCallback {

public:

// 	Function to calculate midi to frequency.
	double mtof(float mPitch) {
		// source of the mtof calculation:
		// https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
		double freqVal = 440.0 * pow(2.0, (mPitch - 57.0f) / 12.0f);

		return freqVal / 4;
	} // mtof()

//	Function to update the pitch.
	void updatePitch(Melody &melody, Synth &synth) {
		float pitch = melody.getPitch();
		double freq = mtof(pitch);
		synth.setFreq(freq);
	} // updatePitch()

//	Function to update the volume.
	float getAllSample() {
//	Reset the sample value.
		float sampleVal = 0;
		sampleVal += synthBank[0]->getSample();
		return sampleVal;
	}

//Function to prepare the synth.
	void prepare(double sampleRate) override {
		this->sampleRate = sampleRate;
		updatePitch(melody, *synthBank[0]);
	} // prepare()

	/*
	 * process() gets called by the JACK engine.
	 *
	 * If you are interested in incoming audio, use inputChannels[channel][sample]
	 * For sending audio to the output(s), use outputChannels[channel][sample]
	 */
	void process(AudioBuffer buffer) override {
		auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

//		For loop to fill the output buffer with the sample value for the left and the right channel.
		for (int sample = 0; sample < numFrames; sample++) {
			outputChannels[0][sample] = getAllSample();
			outputChannels[1][sample] = getAllSample();
//			Tick the synth to the next sample.
			synthBank[0]->tick();
			frameIndex++;
			if (frameIndex >= noteDelayFactor * sampleRate) {
				// reset frameIndex
				frameIndex = 0;
				// Function for updating pitch.
				updatePitch(melody, *synthBank[0]);
			}
		} // for sample
	} // process()

protected:
	bool prepared = false;
	double sampleRate;
	float amplitude = 0.025;
	int frameIndex = 0;
	Melody melody;

	/* instead of using bpm and specifying note lenghts we'll make every note
	 * equal length and specify the delay between notes in term of the
	 * samplerate
	 *
	 * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be
	 * played
	 */
	double noteDelayFactor = 0.1;
}; // Callback{}


int main(int argc, char** argv) {

//	Ask what synth to load.
	std::cout << "What type of synth do you want to load? [add, pwm, saw]";
//	Delcare the synth type.
	std::string synths[3] = {"add", "pwm", "saw"};
	std::string choice = UI::retrieveSelection(synths, 3);
//
	if (choice == "add") {
		synthBank[0] = new addSynth();
	} else if (choice == "pwm") {
		synthBank[0] = new pwmSynth();
	} else if (choice == "saw") {
		synthBank[0] = new sawSynth();
	}
// Initialize the synthBank.
	synthBank[0]->init();


	auto callback = Callback{};
	auto jack_module = JackModule(callback);

	jack_module.init(1, 2);

	std::cout << "Type 'quit' to exit, 's' to swap to new synth.\n";
	bool running = true;
	while (running) {
		switch (std::cin.get()) {
			case 'q':
				running = false;
				break;

//				Case to swap to a new synth.
			case 's':
//				Ask what synth to load.
				std::cout
						<< "\nWhat type of synth do you want? [add, pwm, saw].";
				std::string choice = UI::retrieveSelection(synths, 3);

//				Make an empty Synth ptr.
				Synth* newSynth = nullptr;
				if (choice == "add") {
					newSynth = new addSynth();
				} else if (choice == "pwm") {
					newSynth = new pwmSynth();
				} else if (choice == "saw") {
					newSynth = new sawSynth();
				}

//				Try not to initialise if newSynth empty.
//					Save the old synth, load the new synth, delete the old synth.
				newSynth->init();
				Synth* oldSynth = synthBank[0];
				synthBank[0] = newSynth;
				delete oldSynth;
				std::cout << "\nType 'quit' to exit, 's' to swap to new synth.\n";
				break;



		}
	} // while

	std::cout << "\n\nThank you for playing.\n\n\n\n";

	return 0;

} // main()



