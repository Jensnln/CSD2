//
// Created by Jens on 20/12/2022.
//

#include "synth.h"

Synth::Synth() {

}

Synth::~Synth() {}

void Synth::init(){

	std::cout << "How many sines?"; std::cin >> amt[0];
	std::cout << "How many squares?"; std::cin >> amt[1];
	std::cout << "Fundamental"; std::cin >> fundamental;


	oscAmt += sineAmt + squareAmt;


	Oscillator** oscBank[2];

	array[new Sine, new Square, new Saw]

	oscBank[0] = new Oscillator * [amt[0]];
	oscBank[1] = new Oscillator * [amt[1]];



	for (int i = 0; i < amt[0];i++){
		oscBank[0][i] = new Sine;
	}


	for(int i = 0; i < 2; i++){

		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->print(j);
		}

	}









}