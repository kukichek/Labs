/*
� ��������� ������� �������� n x n �������� ���������� �����, 
��������� ��� ��� ���� �������� �� �������� � ������� ��������� 
(3 � ���� ������ ������� �������� ����, 0 � ���� ���������, 1 � ���� ���� ����������� ������). 
����������:
�) ������� ����� ������� �������, ������� ���������,
�) ����� �������, �������� ��������� �����.

������ �������, 1 ����, �����������

Test case �1
	-4	5				Uncorrect data

Test case �2
	0	0				Uncorrect data

Test case �3
	3					An amount of point of the best team is 4
	0 1 3				A number of the worse team is 2
	1 0 0
	0 3 0
*/

#include<fstream>
#include"array.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int n;

int max(int a, int b) {
	return a > b ? a : b;
}

bool isCorrect(int a) {
	return a > 0;
}

void error() {
	fout << "Uncorrect data\n";
	return;
}

int sumOfPoints(int **a, int i) {
	int sum = 0;
	for (int j = 0; j < n; ++j) {
		sum += a[i][j];
	}
	return sum;
}

int pointBestTeam(int **a) {
	int maxPoint = 0;
	for (int i = 0; i < n; ++i) {
		maxPoint = max(maxPoint, sumOfPoints(a, i));
	}
	return maxPoint;
}

int indexWorseTeam(int **a) {
	int minPointIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (sumOfPoints(a, minPointIndex) > sumOfPoints(a, i)) {
			minPointIndex = i;
		}
	}
	return minPointIndex;
}

void out(int** a) { // �����
	fout << "An amount of point of the best team is " << pointBestTeam(a) << endl;
	fout << "A number of the worse team is " << indexWorseTeam(a) + 1 << endl;
	return;
}

int main() {
	fin >> n;
	if (isCorrect(n)) {
		int** a = createTwoDimensionalArray(n, n);
		inTwoDimensionalArray(a, n, n, fin);
		out(a);
		deleteTwoDimensionalArray(a, n);
	}
	else {
		error();
	}

	system("pause");

	return 0;
}
