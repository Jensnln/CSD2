//
// Created by Jens on 14/02/2023.
//

#include "Waveshaper.h"

Waveshaper::Waveshaper(uint size) : bufferSize(size), buffer(new float[bufferSize]) {
}

Waveshaper::~Waveshaper() {
	delete buffer[];
}

float Waveshaper::output(float input){
	float index = (input + 1) * (bufferSize / 2);

	int i = (int) index;

	float indexDecimals = index - (float)i;

	return linearMap(indexDecimals, buffer[i], buffer[i + 1]);
}

void Waveshaper::setDrive(float k) {
	for (int i = 0; i < bufferSize; i++){
		float x = mapInRage(i, 0.0f, bufferSize, -1.0f, 1.0f);
		buffer[i] = atan(x * k) / atan(k);
	}
}

