#pragma once

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
	return;
}

int binarySearchUpForInsert(int cur, int *a, int n, bool comp(int a, int b)) { 
	// ищет максимальную позицию,
	// на которой может стоять заданный элемент в упорядоченном массиве
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

int binarySearchUp(int cur, int *a, int n, bool comp(int a, int b)) { 
	// ищет максимальную позицию, элемент которой равен заданному,
	// если такового нет - возвращает ноль
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
	if (a[l] != cur) {
		return -1;
	}
	return l;
}