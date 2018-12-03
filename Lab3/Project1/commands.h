#include<iostream>
#pragma once

int NaturalIn() { /// ���� ������������! n
	unsigned int n;
	std::cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	std::cin >> n;
	return n;
}

void compare(int n, int &numberOfDifNumerals) { /// ��������� ������� ����� � ������������
	short int numeral = n % 10; /// ������� �����
	n /= 10; /// ������ ���� ������ �������, �������� ����� ���� ���������

	bool isNotRepeat = 1;
	while (n > 0) {
		if (n % 10 == numeral) isNotRepeat = 0;
		n /= 10;
	}

	numberOfDifNumerals += isNotRepeat;
	return;
}

bool isDif(int n) { /// ��������, �������� �� ��� ����� � ������ ����� n ����������
	int numberOfNumerals = floor(log10(n)) + 1; /// ����� ���� ���� �����
	int numberOfDifNumerals = 0; /// ������� ��������� ����
	while (n > 0) {
		compare(n, numberOfDifNumerals); /// ��������� ������� ����� � ������������
		n /= 10;
	}
	return numberOfNumerals == numberOfDifNumerals;
}