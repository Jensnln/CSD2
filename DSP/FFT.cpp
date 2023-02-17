//
// Created by Jens on 09/02/2023.
//
#include <complex>
#include <iostream>
using namespace std;

// Declaration of i.
complex <double> i(0.0f, 1.0f);

double FIR(int bins){
	cout << "Bins: " << bins << endl;
	double factor = M_PI / bins;

	for (int n = 0; n < bins; n++){
		cout << "bin [" << n  << "]: ";
		double W = factor * n;

		complex <double> H = 0.5 + (0.5*exp(i * W * static_cast <double>(n)));
		cout << "a: " << abs(H) << " ";
		cout << "p: " << arg(H) << endl;
	}
}

int main(){
	FIR(4);
	return 0;
}

