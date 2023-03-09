//
// Created by Jens on 06/03/2023.
//

#include "OnePole.h"
//#include "saw.h"
#include <iostream>
using namespace std;

int main () {
	OnePole onePole;
//	Saw saw;
//	cout << saw.getSample() << endl;
	onePole.setCoefficient(0.5);
	for (int i = -3; i < 100; i++){
		if (i == 0) cout << onePole.output(1.0) << endl;
		else cout << onePole.output(0.0) << endl;
	}

	return 0;
}