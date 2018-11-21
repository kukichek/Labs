/*
Реализовать 3 функции, каждая из которых принимает указатель на массив и кол-во элементов
и возвращает указатель на новый массив. Первая функция ищет простые числа и заносит их в новый массив,
вторая - все числа, кратные трем, третья - все четные числа. Напишите функцию,
которая принимает указатель на функцию в качестве параметра. Добавьте меню, в котором пользователь может выбрать
желаемую операцию.

Гамезо Валерия, 1 курс, информатика

Test case №1
	5									Prime numbers of the array are:
	0 0 0 0 0							NULL
	find prime numbers

Test case №2
	5									Even numbers of the array are:
	0 0 0 0 0							0 0 0 0 0
	find even numbers

Test case №3
	-5									Uncorrect data

Test case №4
	5									Numbers of the array divisible by 3 are:
	1 32 34 57 -3						57 -3
	find numbers divisible by 3


*/

#include<iostream>
#include"array.h"
#define INF 2147483647

using namespace std;

int testingOnCorrectnessOfIndex(int &index) {
	do {
		cout << "Choose index of an operation you want to carry out with the array:\n";
		cout << "0 - find prime numbers;\n";
		cout << "1 - find numbers divisible by 3;\n";
		cout << "2 - find even numbers;\n";
		cin >> index;
	} while ((index < 0) || (index > 2));
	return index;
}

bool isPrime(int a) {
	if (a > 1) {
		for (int i = 2; i * i <= a; ++i) {
			if (a % i == 0) {
				return 0;
			}
		}
	}
	else {
		return 0;
	}
	return 1;
}

int* findPrime(int *a, int n) {
	int* b = new int[n];
	nullArray(b, n);
	int curPosInAnArray = 0; // позиция, на которую будет ставиться новое найденное число

	for (int i = 0; i < n; ++i) {
		if (isPrime(a[i])) {
			b[curPosInAnArray] = a[i];
			curPosInAnArray++; // на выходе curPosInAnArray будет хранить размер массива b
		}
	}

	cout << "Prime numbers of the array are:\n";

	return b;
}

int* findNumsDivBy3(int *a, int n) {
	int* b = new int[n];
	nullArray(b, n);
	int curPosInAnArray = 0; // позиция, на которую будет ставиться новое найденное число

	for (int i = 0; i < n; ++i) {
		if (a[i] % 3 == 0) {
			b[curPosInAnArray] = a[i];
			curPosInAnArray++; // на выходе curPosInAnArray будет хранить размер массива b
		}
	}

	cout << "Numbers of the array divisible by 3 are:\n";

	return b;
}

int* findEven(int *a, int n) {
	int* b = new int[n];
	nullArray(b, n);
	int curPosInAnArray = 0; // позиция, на которую будет ставиться новое найденное число

	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) {
			b[curPosInAnArray] = a[i];
			curPosInAnArray++; // на выходе curPosInAnArray будет хранить размер массива b
		}
	}

	cout << "Even numbers of the array are:\n";

	return b;
}

int* (*operations[3])(int*, int) = {findPrime, findNumsDivBy3, findEven};

int* processingOfAnInquiry(int* a, int n, int* (*operation)(int *a, int n)) {
	return operation(a, n);
}

void out(int* a, int n) {
	if (a[0] != INF) {
		int i = 0;
		while ((a[i] != INF) && (i < n)) {
			cout << a[i] << ' ';
			++i;
		}
	}
	else {
		cout << "NULL\n";
	}
	return;
}

void menu(int* a, int n) {
	int indexOfOperation;
	testingOnCorrectnessOfIndex(indexOfOperation);

	int* answer = processingOfAnInquiry(a, n, operations[indexOfOperation]);

	out(answer, n);
}

int main() {
	int n = getArraySize();
	
	if (n > 0) {
		int* a = createArray(n);
		inArray(a, n);

		menu(a, n);
	} else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}