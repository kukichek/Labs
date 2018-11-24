#include<iostream>
#include<string>
#include"CalcExpression.h"

using namespace std;

void readData(ifstream &fin) {
	CalcExpression formula;
	char symbol;
	if (fin >> symbol) {
		formula.addToSequence(symbol, fin);
		ofstream fout("output.txt");
		fout << "The result is " << formula.findResult() << endl;
	}
	else {
		cout << "The file is empty\n";
	}
}

void openFile() {
	string nameOfFile;
	cout << "Enter, please, a name of a file you want to read data from\n";
	cin >> nameOfFile;
	ifstream fin(nameOfFile);
	if (fin) {
		readData(fin);
	}
	else {
		cout << "The file \"" << nameOfFile << "\" doesn't exist\n";
	}
}