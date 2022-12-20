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

//	std::cout << "TESTING: "<< oscBank[0][0]->getSample();


	oscBank[0] = new Oscillator * [amt[0]];
	oscBank[1] = new Oscillator * [amt[1]];
	oscBank[2] = new Oscillator * [amt[2]];



	for (int i = 0; i < amt[0];i++){
		oscBank[0][i] = new Sine;
		std::cout << "TESTING: "<< oscBank[0][i]->getSample();
//		oscBank[0][i]->getSample();
	}

	for (int i = 0; i < amt[1];i++){
		oscBank[1][i] = new Square;
	}

	for (int i = 0; i < amt[2]; i++){
		oscBank[2][i] = new Saw;
	}



	for(int i = 0; i < 3; i++){

		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->print(j);
		}

	}

//	std::cout << oscBank[0][1]->getSample();


}


float Synth::getSample(){

//	std::cout << oscBank[0][1]->getSample();

	float sampleVal = 0;

	for (int i =0; i < 3; i++){
		std::cout << "amt" << i << "value: " << amt[i] << "\n";
	}

	/*
	std::cout << "TESTING: "<< oscBank[0][1]->getSample();

	for (int i = 0; i < amt[0];i++){
		std::cout << oscBank[0][1]->getSample();
		sampleVal += oscBank[0][1]->getSample();
	}

	for (int i = 0; i < amt[1];i++){
		sampleVal += oscBank[1][1]->getSample();
	}

	for (int i = 0; i < amt[2]; i++){
		sampleVal += oscBank[2][1]->getSample();
	}
	 */

//	std::cout << "sampleVal" << sampleVal << std::endl;

	/*
	for(int i = 0; i < 3; i++){

		for (int j = 0; j < amt[i]; j++){
			sampleVal += oscBank[i][j]->getSample();
		}
	}
	 */




//	std::cout << "Sample value: " << sampleVal << std::endl;

	return sampleVal;



//	std::cout << "Getting Sample\n";


//	std::cout << sampleVal << std::endl;
	return 0;
}

void Synth::tick(){


	for(int i = 0; i < 2; i++){

		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->tick();
		}
	}


//	std::cout << "tick\n";

}