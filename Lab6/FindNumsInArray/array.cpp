#include<iostream>
#include"array.h"
#define INF 2147483647

int getArraySize() {
	int n;
	std::cout << "Enter, please, a size of an array\n";
	std::cin >> n;
	return n;
}

int* createArray(int n) {
	int* a = new int[n];
	return a;
}

void inArray(int* a, int n) {
	std::cout << "Enter, please, elements of an array\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	return;
}

void nullArray(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = INF;
	}
	return;
}

/*int** createTwoDimensionalArray(int n, int m) {
	int** a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	return a;
}*/

/*void inTwoDimensionalArray(int** a, int n, int m) {
	std::cout << "Enter, please, elements of an array\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	return;
}*/

/*void outTwoDimensionalArray(int** a, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << "\n";
	}
	return;
}*/