#include<iostream>
#include"commands.h"

void getNums(int &n, int &m) {
	do {
		std::cout << "Enter, please, numbers n, m more than 0\n";
		std::cin >> n >> m;
	} while (n < 0 || m < 0);
	return;
}

int A(int n, int m) {
	if (n == 0) {
		return m + 1;
	}
	if (m == 0) {
		return A(n - 1, 1);
	}
	return A(n - 1, A(n, m - 1));
}
