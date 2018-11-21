#include<iostream>
#include<fstream>
#include"array.h"

int getArraySize() {
	int n;
	std::cout << "Enter, please, a size of an array\n";
	std::cin >> n;
	return n;
}

void inArray(int* a, int n, std::istream& streamIn) {
	for (int i = 0; i < n; ++i) {
		streamIn >> a[i];
	}
	return;
}

void outArray(int* a, int n, std::ostream& streamOut) {
	for (int i = 0; i < n; ++i) {
		streamOut << a[i] << ' ';
	}
	return;
}

void nullArray(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = NULL;
	}
	return;
}

int** createTwoDimensionalArray(int n, int m) {
	int** a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	return a;
}

void inTwoDimensionalArray(int** a, int n, int m, std::istream& streamIn) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			streamIn >> a[i][j];
		}
	}
	return;
}

void outTwoDimensionalArray(int** a, int n, int m, std::ostream& streamOut) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			streamOut << a[i][j] << ' ';
		}
		streamOut << "\n";
	}
	return;
}

void nullTwoDimensionalArray(int** a, int n, int m) {
	for (int i = 0; i < n; ++i) {
		nullArray(a[i], m);
	}
	return;
}

void deleteTwoDimensionalArray(int** a, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	return;
}