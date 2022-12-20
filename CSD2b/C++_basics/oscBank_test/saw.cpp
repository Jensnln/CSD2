//
// Created by Jens on 20/12/2022.
//

#include "saw.h"

Saw::Saw(){
	std::cout << "Saw::Saw constructor\n";
}

Saw::~Saw() {

}

void Saw::calculate() {

	sample = (phase * 2 -1) * amplitude;
}


float Saw::getSample() {
	return sample;
}


void Saw::print(int instance) {
	std::cout << "Saw[" << instance << "]" << std::endl;
}