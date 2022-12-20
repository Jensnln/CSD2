
// Filename: Synth.cpp
//

#include "synth.h"

Synth::Synth() {

}

Synth::~Synth() {
}

void Synth::init(){

	std::cout << "How many sines? "; std::cin >> amt[0];
	std::cout << "How many squares? "; std::cin >> amt[1];
	std::cout << "How many saws? "; std::cin >> amt[2];
	std::cout << "Fundamental "; std::cin >> fundamental;
	std::cout << "\n";


//	Calculating the total amount of oscillators'
	oscAmt += sineAmt + squareAmt + sawAmt;


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

/* // Debugging code to check if all the oscillators got made.
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->print(j);
		}
	}
 */

	setFreq();
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

	return sampleVal;
}

//	Function to tick all the oscs to the next phase step.
void Synth::tick(){

//	For loop foor all the osc types, then another for loop with "i < amt[i]" to tick the oscs in specific array.
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->tick();
		}
	}
}

void Synth::setFreq(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < amt[i]; j++){
			oscBank[i][j]->setFrequency(fundamental + (j * fundamental));
		}
	}
}