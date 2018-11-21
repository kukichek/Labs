/*
Дан двумерный массив (n x m). Найти: 
а) число пар одинаковых соседних элементов в каждой строке; 
б) число пар одинаковых соседних элементов в каждом столбце

Гамезо Валерия, 1 курс, информатика


Test case №1
	-4	5				Uncorrect data

Test case №2
	0	5				Uncorrect data

Test case №3
	1	1				An amount of equal pairs of a row 1 is 0
	1
						An amount of equal pairs of a col 1 is 0

Test case №4
	3 3					An amount of equal pairs of a row 1 is 1
	1 1 2				An amount of equal pairs of a row 2 is 0
	1 2 1				An amount of equal pairs of a row 3 is 1
	2 1 1				
						An amount of equal pairs of a col 1 is 1
						An amount of equal pairs of a col 2 is 0
						An amount of equal pairs of a col 3 is 1

Test case №5
	3 3					An amount of equal pairs of a row 1 is 2
	-1 -1 -1			An amount of equal pairs of a row 2 is 2
	-1 -1 -1			An amount of equal pairs of a row 3 is 2
	-1 -1 -1
						An amount of equal pairs of a col 1 is 2
						An amount of equal pairs of a col 2 is 2
						An amount of equal pairs of a col 3 is 2
*/

#include<fstream>
#include"array.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int n, m;

bool isCorrect(int a, int b) {
	return (a > 0) && (b > 0);
}

void error() {
	fout << "Uncorrect data\n";
	return;
}

int countPairsRow(int** a, int i) { // счетчик одинаковых пар смежных чисел в строке
	int k = 0;
	for (int j = 0; j < m - 1; ++j) {
		k += (a[i][j] == a[i][j + 1]);
	}
	return k;
}

int countPairsCol(int** a, int j) { // счетчик одинаковых пар смежных чисел в столбце
	int k = 0;
	for (int i = 0; i < n - 1; ++i) {
		k += (a[i][j] == a[i + 1][j]);
	}
	return k;
}

void out(int** a) { // вывод
	for (int i = 0; i < n; ++i) {
		fout << "An amount of equal pairs of a row " << i + 1 << " is " << countPairsRow(a, i) << endl;
	}
	fout << endl;
	for (int j = 0; j < m; ++j) {
		fout << "An amount of equal pairs of a col " << j + 1 << " is " << countPairsCol(a, j) << endl;
	}
	return;
}

int main() {
	fin >> n >> m;
	if (isCorrect(n, m)) {
		int** a = createTwoDimensionalArray(n, m);
		inTwoDimensionalArray(a, n, m, fin);
		out(a);
		deleteTwoDimensionalArray(a, n);
	}
	else {
		error();
	}

	system("pause");

	return 0;
}