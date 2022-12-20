// Filename: Oscillator.cpp
#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator()
{
  std::cout << "Oscillator - constructor\n";
}


Oscillator::~Oscillator() {
  std::cout << "Oscillator - destructor\n";
}

void Oscillator::setSamplerate(float samplerate) {
  this->samplerate = samplerate;
}

float Oscillator::getSample() {
//	float sampleVal = 0.5;
	sample = 0.1;
  	return sample;
}


//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO
  // add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}

void Oscillator::tick()
{
  // increment the phase to allow calculation of next sample
  phase += frequency / samplerate;
  // wrap the phase to interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // calculate sample for the incremented phase
  calculate();
}

//void Oscillator::print(int instance){
//	std::cout << "New instance ["<< instance << "]";
//}