#pragma once

using namespace std;

int inN() { // ввод размера массива
	int n;

	cout << "Enter, please, a size of an array\n";
	cin >> n;

	return n;
}

void inArray(int *a, int n) { // ввод массива
	cout << "Enter, please, elements of an array\n";

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	return;
}

void null(int *a, int n) { //обнуление массивов
	for (int i = 0; i < n; ++i) {
		a[i] = 0;
	}
	return;
}

void addOfPols(int *a, int sizeA, int *b, int sizeB, int *c, int sizeC) { // сложение многочленов
	null(c, sizeC);

	for (int i = 0; i < sizeA; ++i) {
		c[i] += a[i];
	}
	for (int i = 0; i < sizeB; ++i) {
		c[i] += b[i];
	}
	return;
}

void multOfPols(int *a, int sizeA, int *b, int sizeB, int *c, int sizeC) { // умножение многочленов
	null(c, sizeC);

	for (int i = 0; i < sizeA; ++i) {
		for (int j = 0; j < sizeB; ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
	return;
}

void out(int *a, int n) { // вывод массивов
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return;
}