/**
2. В первый день спортсмен пробежал x километров,
а затем он каждый день увеличивал пробег на 10% от предыдущего значения.
По данному числу y определите номер дня,
на который пробег спортсмена составит не менее y километров.
x и y – действительные числа, ответ – целое число.

Гамезо Валерия, 1 группа, информатика

Sample Test №1
	10  20  A sportsman will run not less than 20 km in the next 9 days

Sample Test №2
	5   3   A sportsman will run not less than 20 km in the next 1 days

Sample Test №3
	0   1   Uncorrect data
**/

#include <iostream>

using namespace std;

int main() {
	double x; /// кол-во км, которое пробегает спортсмен в первый день
	double y; /// заданное кол-во км
	int i = 1; /// счетчик дней

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