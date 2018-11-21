#include<iostream>
#include<fstream>
#include<string>
#include"singleLetterCommands.h"

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int chooseCorrectMin(int a, int b) {
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	return a < b ? a : b;
}

void processingLine(string line, ofstream& fout) {
	for (int i = 0; i < line.length(); ++i) {
		if (isalpha(line[i])) {
			int rightPos = max(line.rfind(toupper(line[i])), line.rfind(tolower(line[i])));
			int leftPos = chooseCorrectMin(line.find(toupper(line[i])), line.find(tolower(line[i])));
			if (rightPos == leftPos) {
				fout << char(tolower(line[i])) << ' ';
			}
		}
	}
}

void openFile() {
	ifstream fin("input.txt");

	if (fin) {
		string line;
		if (getline(fin, line)) {
			ofstream fout("output.txt");
			do {
				processingLine(line, fout);
				fout << endl;
			} while (getline(fin, line));
		}
		else {
			cout << "The file is empty\n";
		}
	}
	else {
		cout << "The file is not existing\n";
	}
}