//
// Created by Jens on 16/12/2022.
//

#include "addSynth.h"

addSynth::addSynth(float fundamental, int sineAmount, int squareAmount) : Synth(fundamental, sineAmount, squareAmount) {
	std::cout << "Inside addSynth()\n";
}

addSynth::~addSynth() {
	std::cout << "Inside ~addSynth()\n";
}

void addSynth::init(){

	question();

	oscAmount = sineAmount + squareAmount;

	oscBank = new Oscillator* [oscAmount];


	std::cout
			<< "sAmount: " << sineAmount << std::endl
			<< "sAmount: " << squareAmount << std::endl
			<< "oAmount: " <<  oscAmount << std::endl;

	for (int i = 0; i < oscAmount; i ++){
		std::cout << oscBank[i] << std::endl;
	}

//	Fill the oscBank with Sine objects.
	for (int i = 0; i < sineAmount; i++){
		oscBank[i] = new Sine;
		std::cout << "New instance["<<i<<"]"<<std::endl;
	}
//	Fill the oscBank with Square objects.
	for (int i = sineAmount; i < oscAmount; i++){
		oscBank[i] = new Square;
	}

//	Set the frequency for all Sine objects.
	for (int i = 0; i < sineAmount; i++){
		oscBank[i]->setFrequency(fundamental + (fundamental * i));
	}
//	Set the frequency for all the Square objects.
	for (int i = sineAmount; i < oscAmount; i++){
		oscBank[i]->setFrequency(fundamental + (fundamental * (i - sineAmount)));
	}
}

float addSynth::getSample(){
	float sampleVal = 0;

	for (int i = 0; i < oscAmount; i++){
		sampleVal+= oscBank[i]->getSample();
		oscBank[i]->tick();
	}

	return sampleVal;
}

