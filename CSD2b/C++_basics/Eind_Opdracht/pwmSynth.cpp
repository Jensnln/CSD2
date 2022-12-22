//
// Created by Jens on 21/12/2022.
//

#include "pwmSynth.h"

pwmSynth::pwmSynth() {}
pwmSynth::~pwmSynth() {}

void pwmSynth::init(){


	amt[0] = 0;
	amt[1] = 1;
	amt[2] = 0;


	//	Filling all the 2D arrays with Oscillator point.
	oscBank[0] = new Oscillator * [amt[0]];
	oscBank[1] = new Oscillator * [amt[1]];
	oscBank[2] = new Oscillator * [amt[2]];

	//	Fill the array with sine object pointers.
	for (int i = 0; i < amt[0];i++){
	oscBank[0][i] = new Sine;
	}

	//	Fill the array with square object pointers.
	for (int i = 0; i < amt[1];i++){
	oscBank[1][i] = new Square;
	}

	//	Fill the array with saw object pointers
	for (int i = 0; i < amt[2]; i++){
	oscBank[2][i] = new Saw;
	}

	setPwm();
//	setSampleRate();

}

void pwmSynth::setPwm() {
	float pwmFreq;
	float pwmAmt;
	std::cout << "PwmFreq: "; std::cin >> pwmFreq; std::cout << std::endl;
	std::cout << "PwmAmt: "; std::cin >> pwmAmt; std::cout << std::endl;
	oscBank[1][0]->setPwm(pwmFreq, pwmAmt);
}

void pwmSynth::loadFreq(float frequency) {
	fundamental = frequency;
//	std::cout << "Fundamental: "; std::cin >> fundamental; std::cout << std::endl;
	oscBank[1][0]->setFrequency(fundamental);
//	setPwm();
}

