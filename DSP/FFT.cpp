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
//	WriteToFile fileWriter("a.csv", true);
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


//	For loop for amount of bins.
	for (int n = 0; n < bins; n++){
		complex <double> H (0, 0);
		double W = Wfactor * n;

//		Testing.
		for (int j = 0; j < factors.size(); j++){
			H += (
					factors[j] *
					exp(i * (static_cast<double>(j) - 1) * W)
					);
//			cout << "factor [" << j << "]: " << factors[j] << endl;
		}

		cout << "H[" << n << "]: " << H << endl;
		cout << "a1: " << abs(H) << " ";
		cout << "p1: " << arg(H) << endl;




//		Good version.
		/*complex <double> */ H = 0.5 + (0.5*exp(i * W * static_cast<double> (n)));
		cout << "H2[" << n << "]: " << H << endl;
		cout << "a2: " << abs(H) << " ";
		cout << "p2: " << arg(H) << endl;

//		fileWriter.write(to_string(abs(H)) + "\n");
		fileWriterA.write(to_string(abs(H)) + "\n");
		fileWriterP.write(to_string(arg(H)) + "\n");
	}
}

int main(){

	FIR(4);
	return 0;
}

