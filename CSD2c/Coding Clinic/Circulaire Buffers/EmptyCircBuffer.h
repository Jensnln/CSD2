//
// Created by Dean on 05/02/2023.
//

#pragma once

class CircBuffer {
    using uint = unsigned int;

public:
    CircBuffer (uint size) : currentSize (size), buffer (new float[currentSize]) {
    }

    ~CircBuffer() {
        deleteBuffer();
    }


    void input (float value) {
    }

    float output() {
    }

    void setDistance (uint distance) {

    }

    void incrementHeads() {

    }

private:
    inline void wrapHeader (uint& head) {
		if (head >= currentSize) {
			head -= currentSize;
		}
	}

    inline void incrementWrite() {
		writeHead++;
		wrapHeader(writeHead);
    }

    inline void incrementRead() {
		readHead++;
		wrapHeader(readHead);
    }


    void deleteBuffer() {

    }

    float* buffer;
    uint currentSize { 0 };
	uint distance {};
    uint writeHead { 0 }, readHead { 0 };
};