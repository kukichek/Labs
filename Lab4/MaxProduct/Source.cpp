/*
Дан массив целых чисел, из этой последовательности выбрать три числа, произведение которых максимально.

Гамезо Валерия, 1 курс, информатика

Test Case №1
	2						The size of an array is too small

Test Case №2
	5
	1 2 3 4 5				Numbers, which product is maximal, are:
							5 4 3

Test Case №3
	5
	5 8 6 0 -9				Numbers, which product is maximal, are:
							8 6 5

Test Case №4
	5
	5 8 6 -35 -1			Numbers, which product is maximal, are:
							-35 -1 8

Test Case №5
	4
	4 -6 8 -2				Numbers, which product is maximal, are:
							-6 -2 8

Test Case №6
	5
	-5 -6 -31 -2 -27		Numbers, which product is maximal, are:
							-2 -5 -6

Test Case №7
	3
	-5 -6 -31				Numbers, which product is maximal, are:
							-31 -6 -5
*/

#include<iostream>
#include"bubbleSort.h"

using namespace std;

int inN() {
	int n;

	cout << "Enter, please, a size of an array\n";
	cin >> n;

	return n;
}

void inArray(int *a, int n) {
	cout << "Enter, please, elements of an array\n";

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	return;
}

bool comp(int a, int b) {
	return a < b;
}

int main() {
	int n = inN();

	if (n > 2) {
		int *a = new int[n];
		inArray(a, n);

		bubbleSort(a, n, comp);

		cout << "Numbers, which product is maximal, are:\n";

		if (a[n - 1] * a[n - 2] * a[n - 3] > a[0] * a[1] * a[n - 1]) {
			cout << a[n - 1] << ' ' << a[n - 2] << ' ' << a[n - 3] << endl;
		}
		else {
			cout << a[0] << ' ' << a[1] << ' ' << a[n - 1] << endl;
		}
	}
	else {
		cout << "The size of an array is too small\n";
	}

	system("pause");

	return 0;
}