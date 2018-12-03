#include<iostream>
#pragma once

int NaturalIn() { /// ввод натурального! n
	unsigned int n;
	std::cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	std::cin >> n;
	return n;
}

void compare(int n, int &numberOfDifNumerals) { /// сравнение текущей цифры с последующими
	short int numeral = n % 10; /// текуща€ цифра
	n /= 10; /// запись цифр правее текущей, скоторой будет идти сравнение

	bool isNotRepeat = 1;
	while (n > 0) {
		if (n % 10 == numeral) isNotRepeat = 0;
		n /= 10;
	}

	numberOfDifNumerals += isNotRepeat;
	return;
}

bool isDif(int n) { /// проверка, €вл€ютс€ ли все цифры в записи числа n различными
	int numberOfNumerals = floor(log10(n)) + 1; /// число всех цифр числа
	int numberOfDifNumerals = 0; /// счетчик различных цифр
	while (n > 0) {
		compare(n, numberOfDifNumerals); /// сравнение текущей цифры с последующими
		n /= 10;
	}
	return numberOfNumerals == numberOfDifNumerals;
}