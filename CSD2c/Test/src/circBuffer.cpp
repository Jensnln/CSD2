//
// Created by Jens on 08/02/2023.
//

#include "circBuffer.h"
// Makes new buffer of type float with uint size.
CircBuffer::CircBuffer (uint size) : buffer (new float[size]), currentSize (size)  {
	std::cout << "The circulair buffersize is: " << currentSize << std::endl;
}

// Deletes buffer.
CircBuffer::~CircBuffer() {
	deleteBuffer();
}

void CircBuffer::input(float value){
	buffer[writeHead] = value;
}

float CircBuffer::output(){
	return buffer[readHead];
}

void CircBuffer::setDistance (uint distance) {
	this->distance = distance;
	readHead = (writeHead - this->distance + currentSize) % currentSize;
//	std::cout << "The Distance is: " << distance << std::endl;
}

void CircBuffer::incrementHeads(){
	incrementWrite();
	incrementRead();
}


inline void CircBuffer::incrementWrite() {
	writeHead++;
	wrapHeader(writeHead);
}

inline void CircBuffer::incrementRead() {
	readHead++;
	wrapHeader(readHead);
}


inline void CircBuffer::wrapHeader (uint& head) {
	if (head >= currentSize) head = 0;
}

// Interpolates between two values in a buffer.
float CircBuffer::interpolate (float* buffer, float index, int size) {
	int indexInt = static_cast <int> (index);
	float frac = index - indexInt;

	int index1 = (indexInt + size - 1) % size;
	int index2 = (index1 + 1) % size;

	float a = buffer[index1];
	float b = buffer[index2];

	return a + frac * (b - a);
}

void CircBuffer::deleteBuffer() {
	delete[] buffer;
}

