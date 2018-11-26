#include<algorithm>
#include<fstream>
#include"commands.h"

double findMax(int n, double *a) {
	if (n == 1) {
		return a[0];
	}
	else {
		return std::max(a[0], findMax(n - 1, a + 1));
	}
}

bool isCorrect(int n) {
	return n > 0;
}

void readData(std::ifstream &fin) {
	int n;
	fin >> n;
	std::ofstream fout("output.txt");
	if (isCorrect(n)) {
		double *a = new double[n];
		for (int i = 0; i < n; ++i) {
			fin >> a[i];
		}
		fout << "Max element is " << findMax(n, a) << std::endl;
	} else {
		fout << "A size of an array isn't correct\n";
	}
	return;
}