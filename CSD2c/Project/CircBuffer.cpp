//
// Created by Jens on 08/02/2023.
//

#include "CircBuffer.h"

CircBuffer::CircBuffer (uint size) : currentSize (size), buffer (new float[currentSize]) {
	std::cout << "The circulair buffersize is: " << currentSize << std::endl;
}

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
	std::cout << "The Distance is: " << distance << std::endl;
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

void CircBuffer::deleteBuffer() {
	delete[] buffer;
}

