//
// Created by Jens on 20/12/2022.
//

#include "synth.h"

Synth::Synth() {

}

Synth::~Synth() {
//	deAllocate();
}

void Synth::init(){

	std::cout << "How many sines?"; std::cin >> amt[0];
	std::cout << "How many squares?"; std::cin >> amt[1];
	std::cout << "How many saws?"; std::cin >> amt[2];
	std::cout << "Fundamental"; std::cin >> fundamental;


	oscAmt += sineAmt + squareAmt + sawAmt;



	oscBank[0] = new Oscillator * [amt[0]];
	oscBank[1] = new Oscillator * [amt[1]];
	oscBank[2] = new Oscillator * [amt[2]];



	for (int i = 0; i < amt[0];i++){
		oscBank[0][i] = new Sine;
	}

	for (int i = 0; i < amt[1];i++){
		oscBank[1][i] = new Square;
	}

	for (int i = 0; i < amt[2]; i++){
		oscBank[2][i] = new Saw;
	}



	for(int i = 0; i < 2; i++){

		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->print(j++);
		}

	}

	std::cout << oscBank[0][1]->getSample();


}


float Synth::getSample(){

//	std::cout << oscBank[0][1]->getSample();


	float sampleVal = 0;
	for(int i = 0; i < 2; i++){

		for (int j = 0; j < amt[i]; j++){
			sampleVal += oscBank[i][j]->getSample();
			oscBank[i][j]->tick();
		}
	}

	std::cout << "Sample value: " << sampleVal << std::endl;

	return sampleVal;


//	std::cout << sampleVal << std::endl;
}