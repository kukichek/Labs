#pragma once
#include<iostream>
#include"basics.h"

using namespace std;

template <typename T> void bubbleSort(T *a, int n, bool comp(T a, T b) = increasingComp) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (!comp(*(a + j), *(a + j + 1))) {
				swap(*(a + j), *(a + j + 1));
			}
		}
	}
	return;
}

template <typename T> void selectionSort(T *a, int n, bool comp(T a, T b) = increasingComp) {
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

template <typename T> void insertionSort(T *a, int n, bool comp(T a, T b) = increasingComp) {
	for (int i = 1; i < n; ++i) {
		int k = i - 1;
		while ((k >= 0) && (!comp(a[k], a[k + 1]))) {
			swap(a[k], a[k + 1]);
			--k;
		}
	}
	return;
}

template <typename T> void cocktailSort(T *a, int n, bool comp(T a, T b) = increasingComp) {
	int leftSide = 0;
	int rightSide = n - 1;
	while (leftSide < rightSide) {
		for (int i = leftSide; i < rightSide; ++i) {
			if (!comp(a[i], a[i + 1])) {
				swap(a[i], a[i + 1]);
			}
		}
		rightSide--;
		for (int i = rightSide; i > leftSide; --i) {
			if (!comp(a[i - 1], a[i])) {
				swap(a[i - 1], a[i]);
			}
		}
		leftSide++;
	}
	return;
}

template <typename T> void insertionSortWithBinarySearch(T *a, int n, bool comp(T a, T b) = increasingComp) {
	for (int i = 1; i < n; ++i) {
		int k = binarySearchUp(a[i], a, i, comp);
		for (int j = i; j > k; --j) {
			swap(a[j], a[j - 1]);
		}
	}
	return;
}

template <typename T> void oddEvenSort(T *a, int n, bool comp(T a, T b) = increasingComp) {
	for (int i = 0; i < n; ++i) {
		for (int j = (i + 1) % 2; j < n - 1; j += 2) {
			if (!comp(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}