/*
1. �������� ������� �������� � ������� �����. ����������:
�) ���������� �� ������� � �����;
b) ���������� �� ���� � ��������;

������ �������, 1 ������, �����������

Sample Test �1
	3.14    4		The square does not fit in the circle
					The circle fits in the square

Sample Test �2
	3.142   2		The square fits in the circle
					The circle does not fit in the square

Sample Test �3
	10      -10		Uncorrect data

Sample Test �4
	17		17		The square does not fit in the circle
					The circle does not fit in the square
*/

#include <iostream>
#include <cmath>

using namespace std;

double getSquare(const char* nameOfFigure) {
	double square;
	cout << "Enter, please, a square of a " << nameOfFigure << endl;
	cin >> square;
	while (square < 0) {
		cout << "Uncorrect data, please, try again\n" << endl;
		cin >> square;
	}
	return square;
}

double findRadius() {
	double circleS = getSquare("circle");
	return sqrt(circleS / acos(-1.));
}

double findSide() {
	double squareS = getSquare("square");
	return sqrt(squareS);
}

bool isCircleFit(double r, double a) {
	return 2 * r <= a;
}

bool isSquareFit(double r, double a) {
	return a / sqrt(2.) <= r;
}

void out(bool variant) {
	if (variant) {
		cout << "fits";
	} else {
		cout << "does not fit";
	}
	return;
}

int main()
{
	double r = findRadius(); // ������ �����
	double a = findSide(); // ������� ��������

	cout << "a) The square "; // ��������, ����� �� ��������� ������� � �����
	out(isSquareFit(r, a));
	cout << " in the circle\n";

	cout << "b) The circle "; // ��������, ����� �� ��������� ���� � ��������
	out(isCircleFit(r, a));
	cout << " in the square\n";

	system("pause");

	return 0;
}