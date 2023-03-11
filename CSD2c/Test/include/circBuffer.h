//
// Created by Dean on 05/02/2023.
//

#pragma once
#include <iostream>
#include <cmath>

class CircBuffer {
    using uint = unsigned int;

public:
    CircBuffer (uint size);
    ~CircBuffer();

    void input (float value);
    float output();

    void setDistance (uint distance);
    void incrementHeads();

	float interpolate (float* buffer, float index, int size);

    inline void wrapHeader (uint& head);
    inline void incrementWrite();
    inline void incrementRead();

    void deleteBuffer();
    float* buffer;
	uint distance;
    uint currentSize { 0 };
    uint writeHead { 0 }, readHead { 0 };
};