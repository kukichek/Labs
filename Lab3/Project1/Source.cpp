/*
Найти все натуральные числа, не превосходящие заданного числа n, у которых все цифры в записи числа различны

Гамезо Валерия, 1 курс, информатика

Test case №1
	-5		Uncorrect data

Test case №2
	1		There is no number that meets the conditions

Test case №3
	10		1       2       3       4       5       6       7       8       9

Test case №4
	11		1       2       3       4       5       6       7       8       9       10

Test case №5
	12		1       2       3       4       5       6       7       8       9       10
*/

#include<iostream>
#include<cmath>
#include"commands.h"

using namespace std;

int main() {
	int n = NaturalIn(); /// ввод числа n (функция находится в библиотеке)

	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (isDif(i)) { /// проверка, являются ли все цифры в записи числа i различными
				cout << i << char(9);
			}
		}
	} else {
		if (n == 1) {
			cout << "There is no number that meets the conditions\n";
		} else {
			cout << "Uncorrect data\n";
		}
	}

	system("pause");

	return 0;
}