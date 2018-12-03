/**
3. ���� ������ �����. ������� ���������� ������ ����� ����� ���.
���� ��� �� ����������, �������� ����� "The number is not found".

������ �������, 1 ������, �����������

Sample Test �1
	1   40  -80 27  max_I = 40

Sample Test �2
	1   3   5   7   The number is not found

Sample Test �3
	2	2	9	2	max_I = 2
**/

#include <iostream>
#include <cmath>
#define INF 1

using namespace std;

int main()
{
	int m[4]; /// ������� ������
	int max_I = INF; /// ����������, � ������� ����� ��������� �����

	for (int i = 0; i < 4; i++) {
		cin >> m[i]; /// ���� ������
	}

	for (int i = 0; i < 4; i++) {
		if ((m[i] % 2 == 0) && (m[i] > max_I)) {
			max_I = m[i];
		}
	} /// ����� ��������

	if (max_I == INF) {
		cout << "The number is not found\n";
	}
	else {
		cout << max_I << endl;
	}

	system("pause");

	return 0;
}
