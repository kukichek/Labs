/*
Добавить к некоторой последовательности А = (аi), i = 1..n, n <= 100,
наименьшее число элементов, чтобы получить арифметическую прогрессию
(например, 22 1 36 -> 1 8 15 22 29 36).

Гамезо Валерия, 1 курс, информатика

Test Case №1
	3					An arithmetical progression from an array is:
	22 1 36				1 8 15 22 29 36

Test Case №2
	0					Uncorrect data

Test Case №3
	1					There is no need to add elements to build an arithmetical progression
	1

Test Case №4
	2					There is no need to add elements to build an arithmetical progression
	1 2

Test Case №4
	3					An arithmetical progression from an array is:
	2 2 2				2 2 2
*/

#include<iostream>
#include"Basics.h"
#include"bubbleSort.h"
#include"commands.h"

using namespace std;

int main() {
	int n = inN(); // ввод размера массива

	if (n > 0) {
		int *a = new int[n];

		inArray(a, n);

		if (n > 2) {
			bubbleSort(a, n, comp); // сортировка

			int *remains = new int[n - 1];
			int delta = findDelta(a, n, remains); // нахождение разности арифметической прогрессии
			bubbleSort(remains, n - 1, comp);

			if (isPossibleToCreate(remains[0], remains[n - 2])) {
				cout << "An arithmetical progression from an array is:\n";
				buildAProgression(a, n, delta); // построение арифметической прогрессии из массива
			} else {
				cout << "It's impossible to build an arithmetical progression\n";
			}
		}
		else {
			cout << "There is no need to add elements to build an arithmetical progression\n";
		}
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}