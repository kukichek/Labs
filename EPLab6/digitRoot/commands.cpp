#include<iostream>
#include"commands.h"

int digitRoot(int n) {
	if (n < 10) {
		return n;
	}
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return digitRoot(sum);
}

int getNum() {
	int n;
	do {
		std::cout << "Enter, please, a number n that belongs to a quantity of natural numbers\n";
		std::cin >> n;
	} while (n < 1);
	return n;
}