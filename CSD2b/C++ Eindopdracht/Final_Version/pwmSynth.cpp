//
// Created by Jens on 21/12/2022.
//

#include "pwmSynth.h"

pwmSynth::pwmSynth() {}

pwmSynth::~pwmSynth() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < amt[i]; j++) {
			delete oscBank[i][j];
		}
		delete[] oscBank[i];
	}
}

void pwmSynth::init() {


	amt[0] = 0;
	amt[1] = 1;
	amt[2] = 0;


	//	Filling all the 2D arrays with Oscillator point.
	oscBank[0] = new Oscillator* [amt[0]];
	oscBank[1] = new Oscillator* [amt[1]];
	oscBank[2] = new Oscillator* [amt[2]];

	//	Fill the array with sine object pointers.
	for (int i = 0; i < amt[0]; i++) {
		oscBank[0][i] = new Sine;
	}

	//	Fill the array with square object pointers.
	for (int i = 0; i < amt[1]; i++) {
		oscBank[1][i] = new Square;
	}

	//	Fill the array with saw object pointers
	for (int i = 0; i < amt[2]; i++) {
		oscBank[2][i] = new Saw;
	}

	setPwm();
}

void pwmSynth::setPwm() {
	float pwmFreq;
	float pwmAmt;
	std::cout << "Pwm Sine Frequency (LFO): ";
	pwmFreq = UI::retrieveValueInRange(0, 20000);
	std::cout << "Modulation Depth: ";
	pwmAmt = UI::retrieveValueInRange(0, 1);
	oscBank[1][0]->setPwm(pwmFreq, pwmAmt);
}

void pwmSynth::loadFreq(float frequency) {
	fundamental = frequency;
	oscBank[1][0]->setFrequency(fundamental);
}

