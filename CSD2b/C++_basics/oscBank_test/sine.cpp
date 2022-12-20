//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "sine.h"
#include "math.h"

Sine::Sine()  {
  std::cout << "Sine::Sine constructor\n";
}

Sine::~Sine() {

}

void Sine::calculate() {
  sample = sin(M_PI * 2 * phase) * amplitude;
}

//float Sine::getSample() {
////	float sampleVal = sample;
//	return sample;
//}

void Sine::print(int instance){
	std::cout << "Sine[" << instance << "]" << std::endl;
}