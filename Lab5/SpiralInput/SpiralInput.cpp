/*
Заполнить квадратную матрицу (n * n) натуральными четными числами 2, 4, 6, 8, ...
по сходящейся к центру спирали.

Гамезо Валерия, 1 курс, информатика

Test case №1
	-5				Uncorrect data

Test case №2
	1				2

Test case №3
	5				2       4       6       8       10
					32      34      36      38      12
					30      48      50      40      14
					28      46      44      42      16
					26      24      22      20      18

Test case №4
	8				2       4       6       8       10      12      14      16
					56      58      60      62      64      66      68      18
					54      96      98      100     102     104     70      20
					52      94      120     122     124     106     72      22
					50      92      118     128     126     108     74      24
					48      90      116     114     112     110     76      26
					46      88      86      84      82      80      78      28
					44      42      40      38      36      34      32      30
*/

#include<iostream>
#include"matrix.h"

using namespace std;

void spiralFilling(int **a, int n, int forwardBackDirection = 1, int upDownDirection = 0) { // заполнение матрицы спиралькой
	int i = 0;
	int j = 0;
	int curValue = 0;

	while (curValue < 2 * n * n) {
		curValue += 2;
		a[i][j] = curValue;
		bool isCorrectRowPos = (i + upDownDirection > -1) && (i + upDownDirection < n);
		bool isCorrectColPos = (j + forwardBackDirection > -1) && (j + forwardBackDirection < n);
		if (!isCorrectColPos || !isCorrectRowPos || a[i + upDownDirection][j + forwardBackDirection]) {
			if (upDownDirection) {
				upDownDirection *= -1;
			}
			swap(upDownDirection, forwardBackDirection);
		}
		i += upDownDirection;
		j += forwardBackDirection;
	}

	return;
}

int main() {
	int n = getMatrixSize();

	if (n > 0) {
		int **matrix = new int *[n];
		createMatrix(matrix, n);
		nullMatrix(matrix, n);

		spiralFilling(matrix, n);
		matrixOut(matrix, n);
	} else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}