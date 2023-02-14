//
// Created by Jens on 09/02/2023.
//
#include <complex>
#include <iostream>
using namespace std;

float values[10] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
complex <double> i(0.0f, 1.0f);


double FIR(int steps){
	double O = M_PI / steps;
	for (int n = 0; n < steps; n++){
		cout << "n: " << n << endl;
		double O_2 = O * n;

		double a = values[n];
		cout << "a: " << a << endl;
		double b = values[n-1];


		complex <double> X_n = exp(i * a * O_2);
		complex <double> X_nmin1 = exp(i * b * O_2);
		complex <double> Y_n = (X_n + X_nmin1) / 2.0;
		cout << "Y_n: " << Y_n << endl;

		complex <double> amp_response = abs(Y_n / X_n);
		cout << "amp_response: " << amp_response << endl;
	}
}




int main(){
	cout << "Absolute number: " << abs((1 + 0.5*sqrt(2) - 0.5*sqrt(2) * i) / 2.0 ) << endl;
	cout << "Absolute number: " << abs((1.0 + exp(-i * M_PI / 4.0)) / 2.0) << endl;
	FIR(4);

	return 0;
}

