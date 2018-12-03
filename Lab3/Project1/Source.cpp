/*
����� ��� ����������� �����, �� ������������� ��������� ����� n, � ������� ��� ����� � ������ ����� ��������

������ �������, 1 ����, �����������

Test case �1
	-5		Uncorrect data

Test case �2
	1		There is no number that meets the conditions

Test case �3
	10		1       2       3       4       5       6       7       8       9

Test case �4
	11		1       2       3       4       5       6       7       8       9       10

Test case �5
	12		1       2       3       4       5       6       7       8       9       10
*/

#include<iostream>
#include<cmath>
#include"commands.h"

using namespace std;

int main() {
	int n = NaturalIn(); /// ���� ����� n (������� ��������� � ����������)

	if (n > 1) {
		for (int i = 1; i < n; i++) {
			if (isDif(i)) { /// ��������, �������� �� ��� ����� � ������ ����� i ����������
				cout << i << char(9);
			}
		}
	} else {
		if (n == 1) {
			cout << "There is no number that meets the conditions\n";
		} else {
			cout << "Uncorrect data\n";
		}
	}

	system("pause");

	return 0;
}