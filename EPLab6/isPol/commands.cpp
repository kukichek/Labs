#include<string>
#include"commands.h"

bool isPol(int i, int j, std::string s) {
	if (i >= j) {
		return 1;
	}
	else {
		if (s[i] == s[j]) {
			return isPol(i + 1, j - 1, s);
		}
		else {
			return 0;
		}
	}
}

bool isCorrect(int &a, int &b, int n) {
	bool moreThanZero = (a >= 0) && (b >= 0);
	bool lessThanLen = (a < n) && (b < n);
	if (a > b) {
		std::swap(a, b);
	}
	return moreThanZero && lessThanLen;
}

void readData(std::ifstream &fin) {
	int i, j;
	std::string s;
	fin >> i >> j;
	fin >> s;
	std::ofstream fout("output.txt");
	if (isCorrect(i, j, s.length())) {
		if (isPol(i, j, s)) {
			fout << "The string is polynomial\n";
		}
		else {
			fout << "The string isn't polynomial\n";
		}
	}
	else {
		fout << "Uncorrect indexes\n";
	}
}