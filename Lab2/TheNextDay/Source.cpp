/**
5. �������� ���������, ������� ��������� ���� ���������� ���.

������ �������, 1 ������, �����������

Sample Test �1
	28  2   1789    01.03.1789

Sample Test �2
	28  2   2000    29.02.2000

Sample Test �3
	28  2   2100    01.03.2100

Sample Test �4
	31  8   2156    01.09.2156

Sample Test �5
	1   2   2       02.02.2

Sample Test �6
	31  12  1999    01.01.2000

Sample Test �7
	32  12  1998    Uncorrect data

Sample Test �8
	4   14  1998    Uncorrect data

Sample Test �9
	31  9	2000    Uncorrect data
**/

#include <iostream>

using namespace std;

int d, m, y; /// ����, ����� � ���
int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; /// ������ � ������ ���� � ������ ������

void leapYear() { /// �������� �� ���������� ���
	if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0))) {
		months[1]++;
	}
	return;
}

bool isCorrectDate() { /// �������� ����
	if (y >= 0) {
		if ((m > 0) && (m < 13)) {
			if ((d > 0) && (d <= months[m - 1])) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void nextDay() { /// ���������� ���������� ���
	if (months[m - 1] < d + 1) {
		d = 1;
		m++;
		if (m > 12) {
			m = 1;
			y++;
		}
	}
	else {
		d++;
	}
	return;
}

void outF() { /// ��������� �����
	cout << "The next date is ";
	if (d < 10) {
		cout << "0";
	}
	cout << d << ".";
	if (m < 10) {
		cout << "0";
	}
	cout << m << ".";
	cout << y << endl;
	return;
}

int main() {
	cout << "Enter, please, a day, a month and a year\n";
	cin >> d >> m >> y;

	leapYear();

	if (isCorrectDate()) { /// �������� ����
		nextDay(); /// ���������� ���������� ���
		outF(); /// ��������� �����
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}