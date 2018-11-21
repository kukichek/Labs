/*
»спользу€ датчик случайных чисел, заполнись двумерный массив (n x m) неповтор€ющимис€ числами

√амезо ¬алери€

Test case є1
	-4	5				Uncorrect data

Test case є2
	0	5				Uncorrect data

Test case є3
	1	1				0

Test case є4
	7	5				32 0 22 13 26 
						25 3 19 31 5 
						23 20 24 10 12 
						33 2 21 4 16 
						17 11 34 28 9 
						15 8 18 1 7 
						14 6 27 30 29
*/
#include<fstream>
#include<ctime>
#include"array.h"

using namespace std;

int n, m;
ifstream fin("input.txt");
ofstream fout("output.txt");

template <typename T> void null(T* b, int n) {
	for (int i = 0; i < n; ++i) {
		b[i] = NULL;
	}
	return;
}

int difRandom(bool *isUsedNumber, int upperLimit) { // генераци€ неповтор€ющегос€ рандомного числа не большего чем upperLimit
	int randomNum = rand() % upperLimit;
	int i = 0;
	while (randomNum || isUsedNumber[i]) {
		if (!isUsedNumber[i]) {
			randomNum--;
		}
		i++;
	}
	isUsedNumber[i] = 1;
	return i;
}

void randomFilling(int **a) { // заполнение массива n * m числами от 0 до n * m - 1
	srand(time(NULL));
	bool *isUsedNumber = new bool[n * m];
	null(isUsedNumber, n * m);

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			a[i][j] = difRandom(isUsedNumber, i * m + j + 1);
		}
	}

	delete[] isUsedNumber;
	return;
}

bool isCorrect(int a, int b) {
	return ((a > 0) && (b > 0));
}

void error() {
	fout << "Uncorrect data\n";
	return;
}

int main() {
	fin >> n >> m;
	if (isCorrect(n, m)) {
		int **a = createTwoDimensionalArray(n, m);
		randomFilling(a);
		outTwoDimensionalArray(a, n, m, fout);
		deleteTwoDimensionalArray(a, n);
	} else {
		error();
	}

	system("pause");

	return 0;
}

