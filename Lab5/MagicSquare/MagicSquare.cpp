/*
Дана квадратная матрица n-ого порядка, состоящая из целых чисел. 
Определить является ли она магическим квадратом

Гамезо Валерия, 1 курс, информатика

Test case №1
	16 3 2 13				This matrix is a magic square
	5 10 11 8
	9 6 7 12
	4 15 14 1

Test case №2
	1 2 3					This matrix isn't a magic square
	5 1 0
	2 0 4

Test case №3
	11 18 25 2 9			This matrix is a magic square
	10 12 19 21 3
	4 6 13 20 22
	23 5 7 14 16
	17 24 1 8 15

Test case #4
	-67	-1	-43				This matrix is a magic square
	-13	-37	-61
	-31	-73	-7
*/

#include<iostream>
#include"matrix.h"

using namespace std;

int colSum(int **a, int j, int n) { // подсчет суммы столбца
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i][j];
	}
	return sum;
}

int rowSum(int **a, int i, int n) { // подсчет суммы строки
	int sum = 0;
	for (int j = 0; j < n; ++j) {
		sum += a[i][j];
	}
	return sum;
}

int mainDiagonalSum(int **a, int n) { // подсчет суммы главной диагонали
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i][i];
	}
	return sum;
}

int secondaryDiagonalSum(int **a, int n) { // подсчет суммы побочной диагонали
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i][n - i - 1];
	}
	return sum;
}

int main() {
	int n = getMatrixSize();

	int **matrix = new int *[n];
	createMatrix(matrix, n);

	matrixIn(matrix, n);

	int sum = mainDiagonalSum(matrix, n);

	if (sum == secondaryDiagonalSum(matrix, n)) {
		int i = 0;
		while ((i < n) && (sum == rowSum(matrix, i, n) && (sum == colSum(matrix, i, n)))) {
			++i;
		}
		if (i == n) {
			cout << "This matrix is a magic square\n";
		} else {
			cout << "This matrix isn't a magic square\n";
		}
	}
	else {
		cout << "This matrix isn't a magic square\n";
	}

	system("pause");

	return 0;
}