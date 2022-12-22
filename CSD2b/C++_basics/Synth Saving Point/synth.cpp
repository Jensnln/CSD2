
// Filename: Synth.cpp
//

#include "synth.h"

Synth::Synth() {

}

Synth::~Synth() {
}

void Synth::init(){
}

//	Function to sum all the sampleValues from all the oscillators.
float Synth::getSample(){

	float sampleVal = 0;

//	Sum all the sine samples.
	for (int i = 0; i < amt[0];i++){
		sampleVal += oscBank[0][i]->getSample();
	}

//	Sum all the square samples.
	for (int i = 0; i < amt[1];i++){
		sampleVal += oscBank[1][i]->getSample();
	}

//	Sum all the saw samples.
	for (int i = 0; i < amt[2]; i++){
		sampleVal += oscBank[2][i]->getSample();
	}

//	std::cout << "SV: " << sampleVal << std::endl;

	tick();

	sampleVal *= amplitude;

	return sampleVal;
}

//	Function to tick all the oscs to the next phase step.
void Synth::tick(){

//	For loop for all the osc types, then another for loop with "i < amt[i]" to tick the oscs in specific array.
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->tick();
		}
	}
}

/*
void Synth::setFreq(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->setFrequency(fundamental + (j * fundamental));
		}
	}
}
 */

void Synth::setFreq(float frequency) {}

void Synth::setSampleRate(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->setSampleRate(sampleRate);
		}
	}
}