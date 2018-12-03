/*
Напечатать в порядке возрастания все простые несократимые дроби,
заключенные между 0 и 1, знаменатели которых меньше заданного числа n

Гамезо Валерия, 1 курс, информатика

Test case №1
	-1		Uncorrect data

Test case №2
	1		0/1
			1/1

Test case №3
	3		0/1
			1/3
			1/2
			2/3
			1/1

Test case №4
	6		0/1
			1/6
			1/5
			1/4
			1/3
			2/5
			1/2
			3/5
			2/3
			3/4
			4/5
			5/6
			1/1
*/

#include<iostream>
#include"commands.h"

using namespace std;

int main() {
	int n = NaturalIn(); /// ввод числа

	if (n > 0) {
		vector <int> numenator; // вектор числителей
		vector <int> denominator; // вектор знаменателей
		numenator.insert(numenator.begin(), 1);
		numenator.insert(numenator.begin(), 0);
		denominator.insert(denominator.begin(), 1);
		denominator.insert(denominator.begin(), 1);
		if (n != 1) {
			for (int i = 2; i <= n; i++) {
				iterationFareySequence(numenator, denominator, i); // генерирование дробей
			}
		}
		outF(numenator, denominator); // вывод
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}