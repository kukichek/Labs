/**
2. Дано квадратное уравнение вида ax^2 + bx + c = 0. Определить корни уравнения

Гамезо Валерия, 1 группа, информатика

Sample Test №1
	1   2   1   x = -1

Sample Test №2
	1   1   1   No roots

Sample Test №3
	1   5   6   x1 = -3
				x2 = -2

Sample Test №4
	1   4   0   x1 = -4
				x2 = 0

Sample Test №5
	0   1   -5  The equation is not quadratic
				x = 5

Sample Test №6
	-1	0	9	x1 = 3
				x2 = -3

Sample Test №7
	0	0	9	No roots

Sample Test №8
	0	0	0	Infinite quantity of decisions
**/

#include <iostream>
#include <cmath>

using namespace std;

void getCoef(double &a, double &b, double &c) {
	cout << "Enter, please, coefficients of an equation\n";
	cin >> a >> b >> c;
	return;
}

int main()
{
	double a, b, c; /// коэффиценты при квадратном уравнении
	getCoef(a, b, c);
	double D; /// дискриминант

	if (a) {
		D = b * b - 4 * a * c; /// вычисление дискриминанта

		if (D < 0) {
			cout << "No roots\n";
		} else {
			if (D == 0) {
				cout << "x = " << (-1. * b) / 2. / a << endl;
			} else {
				cout << "x1 = " << (-1. * b - sqrt(D)) / 2. / a << endl;
				cout << "x2 = " << (-1. * b + sqrt(D)) / 2. / a << endl;
			}
		}

	} else {
		if (b) {
			cout << "The equation is not quadratic\n";
			cout << "x = " << -1 * c / b << endl;
		} else {
			if (c) {
				cout << "No roots\n";
			} else {
				cout << "Infinite quantity of decisions\n";
			}
		}
	}

	system("pause");

	return 0;
}