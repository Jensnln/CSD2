//
// Created by Jens on 16/12/2022.
//

#include "synth.h"

Synth::Synth(float fundamental, int sineAmount, int squareAmount){
	std::cout << "Inside Synth()\n";
//	Initialize all values.
	this->fundamental = fundamental;
	this->sineAmount = sineAmount;
	this->squareAmount = squareAmount;
}

Synth::~Synth(){
	std::cout << "Inside ~Synth()\n";
}

//	Initialize the Synth.
void Synth::init() {

	question(); // Function to ask how many what of what.

	oscAmount = sineAmount + squareAmount;

	oscBank = new Oscillator* [oscAmount];


	//	Fill the oscBank with Sine objects.
	for (int i = 0; i < sineAmount; i++){
		oscBank[i] = new Sine;
		std::cout << "New instance["<<i<<"]"<<std::endl;
	}
//	Fill the oscBank with Square objects.
	for (int i = sineAmount; i < oscAmount; i++){
		oscBank[i] = new Square;
	}

	float fundamentalScale = 2;



//	Set the frequency for all Sine objects.
	for (int i = 0; i < sineAmount; i++){
		oscBank[i]->setFrequency(fundamental + (fundamental * i * fundamentalScale));
	}
//	Set the frequency for all the Square objects.
	for (int i = sineAmount; i < oscAmount; i++){
		oscBank[i]->setFrequency(fundamental + (fundamental * (i - sineAmount) * fundamentalScale));
	}
}

/*
float Synth::getSample(){
	float sampleVal = 0;

	for (int i = 0; i < oscAmount; i++){
		sampleVal+= oscBank[i]->getSample();
		oscBank[i]->tick();
	}

	return sampleVal;
}
 */

void Synth::question(){
	std::cout << "amount of sines ";
	std::cin >> sineAmount;

	std::cout << "amount of squares ";
	std::cin >> squareAmount;

	std::cout << "fundamental ";
	std::cin >> fundamental;

}