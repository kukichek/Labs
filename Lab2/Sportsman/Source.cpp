/**
2. � ������ ���� ��������� �������� x ����������,
� ����� �� ������ ���� ���������� ������ �� 10% �� ����������� ��������.
�� ������� ����� y ���������� ����� ���,
�� ������� ������ ���������� �������� �� ����� y ����������.
x � y � �������������� �����, ����� � ����� �����.

������ �������, 1 ������, �����������

Sample Test �1
	10  20  A sportsman will run not less than 20 km in the next 9 days

Sample Test �2
	5   3   A sportsman will run not less than 20 km in the next 1 days

Sample Test �3
	0   1   Uncorrect data
**/

#include <iostream>

using namespace std;

int main() {
	double x; /// ���-�� ��, ������� ��������� ��������� � ������ ����
	double y; /// �������� ���-�� ��
	int i = 1; /// ������� ����

	cout << "Enter, please, a number of km a sportsman runs and a number of km a sportsman must run in the next few days\n";
	cin >> x >> y;

	if (x > 0) {
		while (x <= y) {
			i++;
			x *= 1.1;
		}

		cout << "A sportsman will run not less than " << y << " km in the next " << i << " days\n";
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}