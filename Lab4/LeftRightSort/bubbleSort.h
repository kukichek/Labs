#pragma once
#include"Basics.h"

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