/*
Написать программу, которая содержит функцию, 
принимающую в качестве аргумента указатели на два массива (A и B)
и размеры массивов. Функция проверяет, является ли массив B подмножеством/подстрокой
массива A и возвращает указатель на начало найденного фрагмента,
если элемента нет, возвращает ноль.

Гамезо Валерия, 1 курс, информатика

Test case №1
	A: 1 1 3 2 2				A quantity B isn't a substring of a quantity A
	B: 1 2						A quantity B is a subset of a quantity A

Test case №2
	A: 2						A quantity B isn't a substring of a quantity A
	B: 2 2 2 2					A quantity B is a subset of a quantity A

Test case №3
	A: 1 2 3 4					A quantity B isn't a substring of a quantity A
	B: 5 6						A quantity B isn't a subset of a quantity A

Test case №4
	A: 1 2 3 4 5 6 7			A quantity B is a substring of a quantity A
	B: 4 5 6					A quantity B is a subset of a quantity A
*/

#include<iostream>
#include"basics.h"
#include"sorts.h"

using namespace std;

bool comp(int a, int b) {
	return a < b;
}

int getArraySize(char A) {
	int n;
	cout << "Enter, please, a size of an array " << A << endl;
	cin >> n;
	return n;
}

void arrayIn(int *a, char A, int n) {
	cout << "Enter, please, elements of an array " << A << endl;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	return;
}

int* posOfSubstr(int *A, int n, int* B, int m) { 
	// выводит 0, если В не является подстрокой А, и указатель на вход В в монжестве А - если является
	int i = 0;
	bool isSubs = 0;
	while ((i < n - m + 1) && !isSubs) {
		isSubs = 1;
		for (int j = 0; j < m; ++j) {
			if (B[j] != A[i + j]) {
				isSubs = 0;
			}
		}
		++i;
	}
	return isSubs ? A + i - 1 : 0;
}

bool isSubSet(int *a, int n, int *b, int m) { // проверка, является ли множество В подмножеством А
	insertionSortWithBinarySearch(a, n, comp);
	for (int i = 0; i < m; ++i) {
		if (binarySearchUp(b[i], a, n, comp) == -1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n = getArraySize('A');
	int m = getArraySize('B');

	if (n > 0 && m > 0) {
		int *A = new int[n];
		arrayIn(A, 'A', n);

		int *B = new int[m];
		arrayIn(B, 'B', m);

		if (posOfSubstr(A, n, B, m) != 0) {
			cout << "A quantity B is a substring of a quantity A\n";
		} else {
			cout << "A quantity B isn't a substring of a quantity A\n";
		}

		if (isSubSet(A, n, B, m)) {
			cout << "A quantity B is a subset of a quantity A\n";
		} else {
			cout << "A quantity B isn't a subset of a quantity A\n";
		}
	} else {
		cout << "Uncorrect data\n";
	}	

	system("pause");

	return 0;
}