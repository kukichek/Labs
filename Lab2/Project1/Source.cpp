/**
4. �� ������� ������������ ����� n ������� ����� ����� 1+1/1!+1/2!+1/3!+...+1/n!.
���������� �������� ������ ���� ��������������� n.
�������� ���������, ������� ��������� �������� n � ������� ��������� � ���� ��������������� �����.
� ���� ����� ���������� ��� ����� ��� ����� ����� n?

������ �������, 1 ������, �����������

Sample Test �1
	0   Uncorrect data

Sample Test �2
	-7  Uncorrect data

Sample Test �3
	1   sum = 2

Sample Test �4
	5   sum = 2.71667

Sample Test �5
	9   sum = 2.71828
**/

#include <iostream>

using namespace std;

int main() {
	int n;
	int f = 1; /// ��������� ����� n
	double sum = 1; /// ����� ����������

	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;

	if (n > 0) { /// �������� ��� �������
		for (int i = 1; i <= n; i++) { /// ���������� �����
			f *= i;
			sum += 1. / f;
		}

		cout << "The sum in the form of 1+1/1!+1/2!+1/3!+...+1/n! is " << sum << endl; /// ����� ��������� � �
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}
