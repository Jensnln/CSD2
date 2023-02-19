//
// Created by Jens on 14/02/2023.
//

#include "waveshaper.h"
WaveShaper::WaveShaper() {
	bufferSize = 2048;
	buffer = new float[bufferSize];

}

WaveShaper::WaveShaper(uint size) : buffer(new float[size]){
	bufferSize = size;
}

WaveShaper::~WaveShaper() {
	delete[] buffer;
}

void WaveShaper::calculate(const float& input, float& output) {
//	Make an index, scale the bipolar input value to the unipolar bufferSize.
	float index = (input + 1) * (bufferSize / 2 - 1);

//	Save the int value of the index in the i variable.
	int i = (int) index;

//	Subtract the decimals from the index value.
	float indexDecimal = index - (float) i;

//	std::cout << "i: " << i << " in: " << index << " iD: " << indexDecimal << std::endl;
//	std::cout << "b[i]: " << buffer[i] << " b[i+1]: " << buffer[i+1] << std::endl;
//	std::cout << "b[2048]: " << buffer[2048] << std::endl;
 	output = Util::linearMap(indexDecimal, buffer[i], buffer[i + 1]);
//	std::cout << "output [" << chan << "]: " << output << std::endl;

}

int WaveShaper::setChannel(int chan) {
	this->chan = chan;
}

void WaveShaper::setDrive(float k) {
	WriteToFile fileWriter("output.csv", true);

	for (int i = 0; i <= bufferSize -1; i++){
		float x = Util::mapInRange(i, 0.0f, bufferSize -1, -1.0f, 1.0f);
		buffer[i] = atan(x * k) / atan(k);
		fileWriter.write(std::to_string(buffer[i]) + "\n");
	}
}

