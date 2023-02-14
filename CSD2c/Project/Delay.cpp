//
// Created by Jens on 14/02/2023.
//

#include "Delay.h"
Delay::Delay() {
	buffer = new CircBuffer(10);
}
Delay::~Delay() {
}
 