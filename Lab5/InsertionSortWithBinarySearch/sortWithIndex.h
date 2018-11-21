#pragma once

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
	return;
}

int* binarySearchUpForInsert(int* cur, int *a, bool comp(int a, int b)) {
	// ищет максимальную позицию,
	// на которой может стоять заданный элемент в упорядоченном массиве
	int l = 0;
	int r = cur - a - 1;
	int m = (l + r) / 2;
	while (l < r) {
		if (comp(*cur, *(a + m))) {
			r = m - 1;
		}
		else {
			l = m;
		}
		m = (l + r + 1) / 2;
	}
	if (l == 0 && comp(*cur, a[l])) {
		l--;
	}
	return a + l + 1;
}

void insertionSortWithBinarySearch(int *a, int n, bool comp(int a, int b)) {
	for (int* i = a + 1; i != a + n; ++i) {
		int* k = binarySearchUpForInsert(i, a, comp);
		for (int* j = i; j != k; --j) {
			swap(*j, *(j - 1));
		}
	}
	return;
}

int getArraySize() {
	int n;
	std::cout << "Enter, please, a size of an array " << "\n";
	std::cin >> n;
	return n;
}

void arrayIn(int *a, int n) {
	std::cout << "Enter, please, elements of an array " << "\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	return;
}

void arrayOut(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
	return;
}