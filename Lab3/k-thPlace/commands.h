#pragma once

int NaturalIn() { /// ���� ������������! n
	unsigned int n;
	std::cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	std::cin >> n;
	return n;
}

int numeralOn(int n) {
	int amountOfNumerals = 1; // ���-�� ���� � �����
	int decimals = 1; // ������ � �������

	while (n > 9 * amountOfNumerals * decimals) {
		n -= 9 * amountOfNumerals * decimals;
		amountOfNumerals++;
		decimals *= 10;
	}

	n--;
	int currentNum = decimals + n / amountOfNumerals; // �����, �������� ������� k
	n %= amountOfNumerals; // ������� k � �����

	while (n > 0) {
		currentNum %= decimals;
		decimals /= 10;
		n--;
	}

	return currentNum / decimals;
}