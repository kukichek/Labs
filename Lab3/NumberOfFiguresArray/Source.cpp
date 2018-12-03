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

int figures[10]; /// массив, хранящий кол-во цифр числа n

unsigned int input() { /// ввод n
	unsigned int n;
	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;
	return n;
}

void calculatingOfNumerals(unsigned int n) { /// ввод в массив кол-ва цифр, встречающихся в числе n
	while (n > 0) {
		figures[n % 10] ++;
		n /= 10;
	}
	return;
}

int numberOfFigures() { /// подсчет кол-ва различных цифр числа n
	int num = 0;
	for (int i = 0; i < 10; ++i) {
		if (figures[i] > 0) num++;
	}
	return num;
}

int main() {
	unsigned int n = input();

	calculatingOfNumerals(n);

	cout << "A number of different numerals of n is " << numberOfFigures() << endl;

	system("pause");

	return 0;
}