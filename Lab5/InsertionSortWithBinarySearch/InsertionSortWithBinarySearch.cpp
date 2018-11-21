/*
Написать функцию, которая производит двоичный поиск места размещения нового элемента
в упорядоченном массиве и возвращает указатель на место включения нового элемента.
С помощью данной функции реализовать сортировку вставками

Гамезо Валерия, 1 курс, информатика

Test case №1
	6				
	9 8 0 -5 7 -3			-5 -3 0 7 8 9

Test case №2
	0						Uncorrect data

Test case №3
	1
	5						5

Test case №4
	2
	6 5						5 6
*/

#include<iostream>
#include"sortWithIndex.h"

using namespace std;

bool comp(int a, int b) {
	return a < b;
}

int main() {
	int n = getArraySize();

	if (n > 0) {
		int *a = new int[n];
		arrayIn(a, n);

		insertionSortWithBinarySearch(a, n, comp);

		arrayOut(a, n);
	} else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}