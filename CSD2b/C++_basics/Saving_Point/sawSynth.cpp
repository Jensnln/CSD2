//
// Created by Jens on 21/12/2022.
//

#include "sawSynth.h"

sawSynth::sawSynth() {}
sawSynth::~sawSynth() {}

void sawSynth::init(){
	amt[0] = 0;
	amt[1] = 0;
	std::cout << "How many saws? "; std::cin >> amt[2];

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

	setFreq();

}

void sawSynth::setFreq() {
	std::cout << "Fundamental: "; std::cin >> fundamental;
	oscBank[2][0]->setFrequency(fundamental);
	float detune;
	std::cout << "Much detune would you like to have? (in percentage)"; std::cin >> detune;
	detune = (detune / 3000);
	for (int i = 1; i < amt[2]; i++){
		oscBank[2][i]->setFrequency(fundamental + ((fundamental * i) * detune));
	}

}