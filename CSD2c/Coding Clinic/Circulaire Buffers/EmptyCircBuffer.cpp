#pragma once
#include "EmptyCircBuffer.h"

CircBuff::CircBuffer (uint size) : currentSize (size), buffer (new float[currentSize]) {
}

CircBuff::~CircBuffer() {
	deleteBuffer();
}


main(){
//	Input a value in the buffer.
	input();
	return 0;
}

void CircBuff::incrementHeads(){
	input();
	incrementWrite();

	if (readHead > distance){
		output();
		incrementRead();
	}
}



void CircBuffer::input(float value){
//	Insert value on right index.
	buffer[writeHead] = value;
}

float CircBuff::output(){
	return buffer[readHead];
}



