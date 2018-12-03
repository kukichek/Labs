/*
Найти сумму и произведение двух многочленов, заданных массивами своих коэффицентов.

Гамезо Валерия, 1 курс, информатика

Test Case №1
	2					The sum of polynomils is:
	2					2 2
	1 1					The product of polynomials is:
	1 1					1 2 1

Test Case №2
	3					The sum of polynomils is:
	2					3 1 1
	2 0 1				The product of polynomials is:
	1 1					2 2 1 1

Test Case №3
	5					Uncorrect data
	2
	0 0 2 0 1
	1 1
*/

#include<iostream>
#include<algorithm>
#include"commands.h"

using namespace std;

int main() {
	int sizeA = inN();
	int sizeB = inN();

	if ((sizeA > 0) && (sizeB > 0)) {
		int *a = new int[sizeA];
		int *b = new int[sizeB];

		inArray(a, sizeA);
		inArray(b, sizeB);

		if ((a[0] != 0) && (b[0] != 0)) {
			int sizeS = max(sizeA, sizeB); // размер массива суммы
			int *sum = new int[sizeS];
			addOfPols(a, sizeA, b, sizeB, sum, sizeS);

			int sizeP = sizeA + sizeB - 1; // размер массива произведения
			int *product = new int[sizeP];
			multOfPols(a, sizeA, b, sizeB, product, sizeP);

			cout << "The sum of polynomials is:\n";
			out(sum, sizeS);
			cout << "The product of polynomials is:\n";
			out(product, sizeP);
		}
		else {
			cout << "Uncorrect data\n";
		}
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}