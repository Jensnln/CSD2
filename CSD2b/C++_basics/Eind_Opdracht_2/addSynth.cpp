//
// Created by Jens on 16/12/2022.
//

#include "addSynth.h"

addSynth::addSynth(float fundamental) : Synth(fundamental) {
	std::cout << "Inside addSynth()\n";
}

addSynth::~addSynth() {
	std::cout << "Inside ~addSynth()\n";
}

void addSynth::init(){

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

float Synth::getSample(){
	float sampleVal = 0;

	for (int i = 0; i < oscAmount; i++){
		sampleVal+= oscBank[i]->getSample();
		oscBank[i]->tick();
	}

	return sampleVal;
}

