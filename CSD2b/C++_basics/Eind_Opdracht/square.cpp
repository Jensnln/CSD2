// Filename: square.cpp
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "square.h"
#include "math.h"

Square::Square()
{
//  std::cout << "Square::Square constructor\n";
}

Square::~Square() {

}

void Square::setPwm(float frequency, float amount) {
	pwmSine.setFrequency(frequency);
	pwmAmt = amount;
	std::cout << pwmAmt;
	std::cout << frequency;
}

void Square::calculate() {
  sample = amplitude;
  float pwm = pwmSine.getSample() /2;
  pwmSine.tick();

  if(phase > 0.5 + (pwm * pwmAmt)) {
    sample *=-1.0f;
  }
}

// Return the sample value, overrides the method from the base class.
float Square::getSample() {
	return sample;
}




