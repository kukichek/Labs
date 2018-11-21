#pragma once
#include"basics.h"

void bubbleSort(int *a, int n, bool comp(int a, int b)) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (!comp(*(a + j), *(a + j + 1))) {
				swap(*(a + j), *(a + j + 1));
			}
		}
	}
	return;
}

void selectionSort(int *a, int n, bool comp(int a, int b)) {
	for (int i = 0; i < n; ++i) {
		int pos = i;
		for (int j = i + 1; j < n; ++j) {
			if (!comp(*(a + pos), *(a + j))) {
				pos = j;
			}
		}
		swap(*(a + pos), *(a + i));
	}
	return;
}

void insertionSort(int *a, int n, bool comp(int a, int b)) {
	for (int i = 1; i < n; ++i) {
		int k = i - 1;
		while ((!comp(a[k], a[k + 1])) && (k >= 0)) {
			swap(a[k], a[k + 1]);
			--k;
		}
	}
	return;
}

void insertionSortWithBinarySearch(int *a, int n, bool comp(int a, int b)) {
	for (int i = 1; i < n; ++i) {
		int k = binarySearchUpForInsert(a[i], a, i, comp);
		for (int j = i; j > k; --j) {
			swap(a[j], a[j - 1]);
		}
	}
	return;
}

void oddEvenSort(int *a, int n, bool comp(int a, int b)) {
	for (int i = 0; i < n; ++i) {
		for (int j = (i + 1) % 2; j < n - 1; j += 2) {
			if (!comp(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
