#pragma once

template <typename T> bool increasingComp(T a, T b) {
	return a < b;
}

template <typename T> bool subsidingComp(T a, T b) {
	return a > b;
}

int binarySearchUp(int cur, int *a, int n, bool comp(int a, int b)) { // ищет максимальную позицию, на которой может стоять заданный элемент в упорядоченном массиве
	int l = 0;
	int r = n - 1;
	int m = (l + r) / 2;
	while (l < r) {
		if (comp(cur, *(a + m))) {
			r = m - 1;
		}
		else {
			l = m;
		}
		m = (l + r + 1) / 2;
	}
	if (l == 0 && comp(cur, a[l])) {
		l--;
	}
	return l + 1;
}