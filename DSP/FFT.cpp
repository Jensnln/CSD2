//
// Created by Jens on 09/02/2023.
//

#include <complex>
#include <iostream>
#include <vector>
#include "writeToFile.h"
using namespace std;

// Declaration of i.
complex <double> i(0.0f, 1.0f);

void FIR(int bins){
//	Write to .csv file for the python plotter.
	WriteToFile fileWriterA("a.csv", true);
	WriteToFile fileWriterP("p.csv", true);

	cout << "Bins: " << bins << endl;
	double Wfactor = M_PI / bins;

//	Ask amount of factors.
	int numFactors;
	std:: cout << "Enter the number of factors: ";
	std:: cin >> numFactors;

//	Enter the factors.
	vector <double> factors;
	for (int i = 0; i < numFactors; i++){
		double factor;
		std:: cout << "Enter factor " << i << ": ";
		std:: cin >> factor;
		factors.push_back(factor);
	}

//	Print all the factors.
	cout << "Factors: ";
	for(const auto& factor : factors){ cout << factor << " ";
	} cout << endl;


//// Fixed coefs.
//	for (int n = 0; n < bins + 1; n++){
////		Define coefs.
//		double c1 = 0.5;
//		double c2 = 0.5;
//
//		double W = Wfactor * n;
//		complex <double> H = c1 + c2 * exp(i * W);
//
//		cout << "a1: " << abs(H) << " ";
//		cout << "p1: " << arg(H) << endl;
//	}

//	Variable coefs.
	for (int n = 0; n < bins+1; n++){
//		Declare and reset.
		complex <double> H =  (0, 0);

		double W = Wfactor * n;

		for (int j = 0; j < factors.size(); j++){
			H += ( factors[j] * exp(-i * W * double(j - 1)) );
		}

//		cout << "H2: [" << n << "] " << H << " ";
		fileWriterA.write(std::to_string(abs(H)) + "\n");
		fileWriterP.write(std::to_string(arg(H)) + "\n");
		cout << "a2: " << abs(H) << " ";
		cout << "p2: " << arg(H) << endl;
	}

}

int main(){
	FIR(10);
	return 0;
}

