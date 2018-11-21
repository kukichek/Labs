/*
Дана матрица размера m x n. Перестроить матрицу, переставляя в ней строки так, 
чтобы сумма элементов в строках полученной матрицы возрастала.

Гамезо Валерия, 1 курс, информатика

Test case №1
	Enter, please, a height and a width of an array
	0 -5
	Enter, please, a height and a width of an array
	0 4
	Enter, please, a height and a width of an array
	3 3
	Enter, please, elements of an array
	0 3 4
	2 1 3
	4 -2 3
	Sorted array is:
	4 -2 3
	2 1 3
	0 3 4

Test case №2
	
*/

#include<iostream>
#include"sorts.h"
#include"array.h"

using namespace std;

int n, m;

void getNMArray() {
	do {
		cout << "Enter, please, a height and a width of an array\n";
		cin >> n >> m;
	} while ((n < 1) || (m < 1));
	return;
}

bool comp(int *a, int *b) {
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < m; ++i) {
		sumA += a[i];
		sumB += b[i];
	}
	return sumA < sumB;
}

int main() {
	getNMArray();
	int **a = createTwoDimensionalArray(n, m);
	cout << "Enter, please, elements of an array\n";
	inTwoDimensionalArray(a, n, m, cin);

	insertionSort(a, n, comp);

	cout << "Sorted array is:\n";
	outTwoDimensionalArray(a, n, m, cout);

	system("pause");

	return 0;
}