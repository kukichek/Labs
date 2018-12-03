/*
����� k-�� ����� � ���� ����, ������������ �� ������ ������ ����������� �����,
������� � 1: 12345678910111213�

������ �������, 1 ����, �����������

Test case �1
	-1		Uncorrect data

Test case �2
	2		A numeral standing on the place number 2 is 2

Test case �3
	11		A numeral standing on the place number 11 is 0

Test case �4
	5135	A numeral standing on the place number 5135 is 5
*/

#include<iostream>
#include"commands.h"

using namespace std;

int main() {
	int k = NaturalIn();

	if (k > 0) {
		cout << "A numeral standing on the place number " << k << " is " << numeralOn(k) << endl;
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}