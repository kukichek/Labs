#pragma once

void createMatrix(int **a, int n) { // создание двумерной матрицы
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	return;
}

void matrixIn(int **a, int n) { // ввод двумерной матрицы
	std::cout << "Enter, please, elements of a matrix\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> a[i][j];
		}
	}
	return;
}

int getMatrixSize() { // ввод размера массива
	int n;
	std::cout << "Enter, please, a size of a square matrix\n";
	std::cin >> n;
	return n;
}

void nullMatrix(int **a, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 0;
		}
	}
	return;
}