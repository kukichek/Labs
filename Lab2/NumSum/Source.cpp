/**
3. ���� ����������� ����� n. �������� ����� ���� ����� n.

������ �������, 1 ������, �����������

Sample Test �1
	143 The sum of numerals of the number n is 8

Sample Test �2
	5   The sum of numerals of the number n is 5

Sample Test �3
	0   Uncorrect data

Sample Test �4
	-5  Uncorrect data
**/

#include <iostream>

using namespace std;

int main() {
	int n;
	int NumeralS = 0; /// ����� ����

	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;

	if (n > 0) { /// �������� ��� �������
		while (n > 0) { /// ���������� ����� ����
			NumeralS += n % 10;
			n /= 10;
		}

		cout << "The sum of numerals of the number n is " << NumeralS << endl;
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}
