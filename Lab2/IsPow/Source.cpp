/**
1. Дано число n. Определить, является ли оно степенью двойки.

Гамезо Валерия, 1 группа, информатика

Sample Test №1
	0   No, 0 isn't a power of two

Sample Test №2
	-5  No, -5 isn't a power of two

Sample Test №3
	1   Yes, 1 is a power of two

Sample Test №4
	3   No, 3 isn't a power of two

Sample Test №5
	8   Yes, 8 is a power of two
**/

#include <iostream>

using namespace std;

bool isPow(int n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	return n == 1 ? 1 : 0;
}

int main() {
	int n;

	cout << "Enter, please, a number n\n";
	cin >> n;

	if (n > 0) {
		if (isPow(n)) {
			cout << "Yes, " << n << " is a power of two\n";
		}
		else {
			cout << "No, " << n << " isn't a power of two\n";
		}
	}
	else { /// числа, меньше либо равные нулю не являются степенью двойки
		cout << "No, " << n << " isn't a power of two\n";
	}

	system("pause");

	return 0;
}
