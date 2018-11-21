/*
Дан двумерный массив (n x m). Определить количество различных элементов в нем

Гамезо Валерия, 1 курс, информатика

Test case №1
	-4	5				Uncorrect data

Test case №2
	0	5				Uncorrect data

Test case №3
	1	1				A number of different elements of an array is 1
	1

Test case №4
	7	5				A number of different elements of an array is 35
	32 0 22 13 26
	25 3 19 31 5
	23 20 24 10 12
	33 2 21 4 16
	17 11 34 28 9
	15 8 18 1 7
	14 6 27 30 29

Test case №5
	3	3				A number of different elements of an array is 4
	1 2 3
	1 2 3
	1 2 4
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

bool isSingle(int **a, int iCurrent, int jCurrent) {  // проверка, которое засчитывает последнее вхождение числа
	for (int i = iCurrent * m + jCurrent + 1; i < n * m; ++i) {
		if (a[iCurrent][jCurrent] == *(*(a + i/m) + i % m)) {
			return 0;
		}
	}
	return 1;
}

int counter(int** a) { // счетчик различных элементов
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			k += isSingle(a, i, j);
		}
	}
	return k;
}

void out(int** a) { // вывод числа элементов
	fout << "A number of different elements of an array is " << counter(a) << endl;
	return;
}

int main() {
	fin >> n >> m;
	if (isCorrect(n, m)) {
		int** a = createTwoDimensionalArray(n, m);
		inTwoDimensionalArray(a, n, m, fin);
		out(a);
		deleteTwoDimensionalArray(a, n);
	} else {
		error();
	}

	system("pause");

	return 0;
}