//
// Created by Jens on 14/02/2023.
//

#include "Effect.h"

Effect::Effect() {
}
Effect::~Effect() {
}

void Effect::prepare (int sampleRate) {
	this->sampleRate = sampleRate;
}

void Effect::input(float input){
}

float Effect::output(){
	outputVal = input();
	return outputVal;
}

void Effect::setDryWet(float dryWet) {
//	Set range to 0-1.
	if(dryWet > 1) dryWet = 1;
	else if(dryWet < 0) dryWet = 0;
	this->dryWet = dryWet;
}