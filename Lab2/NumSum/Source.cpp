/**
3. Дано натуральное число n. Выведите сумму цифр числа n.

Гамезо Валерия, 1 группа, информатика

Sample Test №1
	143 The sum of numerals of the number n is 8

Sample Test №2
	5   The sum of numerals of the number n is 5

Sample Test №3
	0   Uncorrect data

Sample Test №4
	-5  Uncorrect data
**/

#include <iostream>

using namespace std;

int main() {
	int n;
	int NumeralS = 0; /// сумма цифр

	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;

	if (n > 0) { /// проверка для дураков
		while (n > 0) { /// вычисление суммы цифр
			NumeralS += n % 10;
			n /= 10;
		}

		cout << "The sum of numerals of the number n is " << NumeralS << endl;
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}
