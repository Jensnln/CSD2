//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "square.h"
#include "math.h"

Square::Square()
{
  std::cout << "Square::Square constructor\n";
}

Square::~Square() {

}

void Square::calculate() {
  sample = amplitude;
  if(phase > 0.5) {
    sample *=-1.0f;
  }
}

//float Square::getSample() {
////	float sampleVal = sample;
//	return sample;
//}

void Square::print(int instance){
	std::cout << "Square[" << instance << "]" << std::endl;
}


