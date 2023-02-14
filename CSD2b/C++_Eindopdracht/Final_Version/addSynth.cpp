//
// Created by Jens on 21/12/2022.
//

#include "addSynth.h"

addSynth::addSynth() {}
addSynth::~addSynth() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < amt[i]; j++) {
			delete oscBank[i][j];
		}
		delete[] oscBank[i];
	}

}

void addSynth::init(){

	std::cout << "How many sines? "; amt[0] = UI::retrieveValueInRange(0, 20);
	std::cout << "How many squares? "; amt[1] = UI::retrieveValueInRange(0, 10);
	std::cout << "How many saws? "; amt[2] = UI::retrieveValueInRange(0, 10);
	std::cout << "\n";

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
}

void addSynth::loadFreq(float frequency) {
	fundamental = frequency;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->setFrequency(fundamental + (j * fundamental));
		}
	}
}
