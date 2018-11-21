#pragma once
#include<iostream>

template <typename T> void createMatrix(T **a, int n) { // создание двумерной матрицы
	for (int i = 0; i < n; ++i) {
		a[i] = new T[n];
	}
	return;
}

void matrixNull(bool **a, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = 0;
		}
	}
	return;
}

template <typename T> void matrixOut(T **a, int n, int m) { // вывод двумерной матрицы
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << "\n";
	}
	return;
}