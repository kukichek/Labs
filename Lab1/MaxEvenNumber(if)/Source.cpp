/**
3. ���� ������ �����. ������� ���������� ������ ����� ����� ���.
���� ��� �� ����������, �������� ����� "The number is not found".

������ �������, 1 ������, �����������

Sample Test �1
	1   40  -80 27  max_I = -80

Sample Test �2
	1   3   5   7   The number is not found

Sample Test �3
	2	2	9	2	max_I = 2
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d; // ������� ������
	int Ans = 1; // ����������, � ������� ����� ��������� ������

	cin >> a >> b >> c >> d;

	if ((a > Ans) && (a % 2 == 0)) {
		Ans = a;
	}

	if ((b > Ans) && (b % 2 == 0)) {
		Ans = b;
	}

	if ((c > Ans) && (c % 2 == 0)) {
		Ans = c;
	}

	if ((d > Ans) && (d % 2 == 0)) {
		Ans = d;
	}

	if (Ans % 2 == 0) {
		cout << Ans << endl;
	}
	else {
		cout << "The number is not found\n";
	}

	system("pause");

	return 0;
}