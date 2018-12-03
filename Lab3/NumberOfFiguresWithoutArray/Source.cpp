/*
Найти количество различных цифр в записи заданного натурального числа n

Гамезо Валерия, 1 курс, информатика

Test case №1
	10			A number of different numerals of n is 2

Test case №2
	01			A number of different numerals of n is 1

Test case №3
	1234567890	A number of different numerals of n is 10

Test case №4
	5555555		A number of different numerals of n is 1

Test case №5
	444404		A number of different numerals of n is 2

Test case №6
	142434		A number of different numerals of n is 4
*/

#include<iostream>

using namespace std;

int numberOfNumerals;

unsigned int input() { /// ввод n
	unsigned int n;
	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;
	return n;
}

void compare(unsigned int n) { /// сравнение определенной цифры числа n с остальными
	short int numeral = n % 10;
	n /= 10;

	bool isNotRepeat = 1;
	while (n > 0) {
		if (n % 10 == numeral) isNotRepeat = 0;
		n /= 10;
	}

	numberOfNumerals += isNotRepeat;
	return;
}

int main() {
	unsigned int n = input();

	while (n > 0) {
		compare(n);
		n /= 10;
	}

	cout << "A number of different numerals of n is " << numberOfNumerals << endl;

	system("pause");

	return 0;
}