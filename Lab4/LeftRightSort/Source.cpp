/*
Дан массив целых чисел. Реализовать функцию для обработки массива целых чисел.
Функция находит минимальный элемент массива и сортирует все элементы левее его по убыванию,
а правее его – по возрастанию. Функция возвращает индекс минимального элемента.

Гамезо Валерия, 1 курс, информатика

Test Case №1
	5
	1 5 4 3 2			The position of a minimal element is 1
						1 2 3 4 5

Test Case №2
	5
	2 3 4 5 1			The position of a minimal element is 5
						5 4 3 2 1

Test Case №3
	5
	4 5 1 3 2			The position of a minimal element is 3
						5 4 1 2 3

Test Case №4
	3
	3 1 2				The position of a minimal element is 2
						3 1 2
*/

#include<iostream>
#include"bubbleSort.h"

using namespace std;

int inN() { // ввод размера массива
	int n;

	cout << "Enter, please, a size of an array\n";
	cin >> n;

	return n;
}

void inArray(int *a, int n) { // ввод массива
	cout << "Enter, please, elements of an array\n";

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	return;
}

bool leftComp(int a, int b) { // сортировка по убыванию
	return a > b;
}

bool rightComp(int a, int b) { // сортировка по возрастанию
	return a < b;
}

int findMinP(int *a, int n) { // нахождение позиции минимального элемента
	int minP = 0;

	for (int i = 1; i < n; ++i) {
		if (a[i] < a[minP]) {
			minP = i;
		}
	}

	if (0 < minP - 1) { // сортировка левой части массива
		bubbleSort(a, minP, leftComp);
	}
	if (minP + 1 < n - 1) { // сортировка правой части массива
		bubbleSort(a + minP + 1, n - minP - 1, rightComp);
	}

	return minP;
}

void outArray(int *a, int n) { // вывод массива
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	int n = inN(); // ввод размера массива

	if (n > 0) {
		int *a = new int[n]; // массив данных
		inArray(a, n); // ввод данных массива

		cout << "The position of a minimal element is " << findMinP(a, n) + 1 << endl; // вывод позиции
		outArray(a, n); // вывод массива
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}