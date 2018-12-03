#pragma once

int NaturalIn() { /// ввод натурального! n
	unsigned int n;
	std::cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	std::cin >> n;
	return n;
}

int numeralOn(int n) {
	int amountOfNumerals = 1; // кол-во цифр в числе
	int decimals = 1; // десять в степени

	while (n > 9 * amountOfNumerals * decimals) {
		n -= 9 * amountOfNumerals * decimals;
		amountOfNumerals++;
		decimals *= 10;
	}

	n--;
	int currentNum = decimals + n / amountOfNumerals; // число, хранящее позицию k
	n %= amountOfNumerals; // позиция k в числе

	while (n > 0) {
		currentNum %= decimals;
		decimals /= 10;
		n--;
	}

	return currentNum / decimals;
}