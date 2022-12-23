//
// Created by Jens on 21/12/2022.
//

#include "addSynth.h"

addSynth::addSynth() {}
addSynth::~addSynth() {}

void addSynth::init(){

	std::cout << "How many sines? "; std::cin >> amt[0];
	std::cout << "How many squares? "; std::cin >> amt[1];
	std::cout << "How many saws? "; std::cin >> amt[2];
//	std::cout << "Fundamental "; std::cin >> fundamental;
	std::cout << "\n";


//	Calculating the total amount of oscillators'
//	oscAmt += sineAmt + squareAmt + sawAmt;
	

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

	setSampleRate();
}

void addSynth::setFreq(float frequency) {
	fundamental = frequency;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->setFrequency(fundamental + (j * fundamental));
		}
	}
}
