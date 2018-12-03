/*
��� ��������� n ����� ��� ������� ��� ����������� �����
(����������� ���������� �����, ������ ����� ���� ����� ���������, �� ������ ������ �����).

������ �������, 1 ����, �����������

Test case �1
	-5			Uncorrect data

Test case �2
	1			There is no number that meets the conditions

Test case �3
	5			There is no number that meets the conditions

Test case �4
	30			Perfect numbers less than n are:
				6       28

Test case �5
	8129		Perfect numbers less than n are:
				6       28      496     8128

Test case �6
*/

#include<iostream>

using namespace std;

bool isEmpty = 1; // ���������, ���������� ����������, �� ���� �� ������� ��� ����������� �����, ������� n

int NaturalIn() { /// ���� ������������! n
	unsigned int n;
	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;
	return n;
}

bool isPerfect(int n) { // �������� �� ������������
	int sum = 0; // ����� ��������� �����
	for (int i = 1; 2 * i <= n; ++i) {
		if (n % i == 0)
			sum += i;
	}
	if (n == sum) {
		if (isEmpty) {
			isEmpty = 0;
			cout << "Perfect numbers less than n are:\n";
		}
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n = NaturalIn();

	if (n > 0) { // �������� ������
		for (int i = 1; i < n; i++) {
			if (isPerfect(i)) // �������� �� ������������
				cout << i << char(9);
		}
		if (isEmpty) {
			cout << "There is no number that meets the conditions\n";
		}
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}
