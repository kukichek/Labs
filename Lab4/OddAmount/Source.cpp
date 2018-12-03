/*
Дан массив целых чисел, в котором все числа кроме одного встречаются четное кол-во раз. Найти это число

Гамезо Валерия, 1 курс, информатика

Test Case №1
	1
	1					A number that meets odd amount of times is 1

Test Case №2
	3
	1 2 1				A number that meets odd amount of times is 2

Test Case №3
	7
	8 5 4 8 5 8 8		A number that meets odd amount of times is 4

Test Case №4
	7
	-9 0 -5 -9 -9 0 -9	A number that meets odd amount of times is -5

Test Case №5
	0					Uncorrect data
*/

#include<iostream>

using namespace std;

int inN() { // ввод натурального числа – размера массива
	int n;

	cout << "Enter, please, a size of array\n";
	cin >> n;

	return n;
}

void inArray(int *a, int n) { // ввод массива
	cout << "Enter, please, elements of an array\n";

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	return;
}

int main() {
	int n = inN(); // размер динамического массива

	if (n > 0) {
		int *a = new int[n]; // массив данных

		inArray(a, n); // ввод массива

		int ans = a[0]; // переменная, в которой будет храниться число, которое встречается в массиве нечетное число раз

		for (int i = 1; i < n; ++i) {
			ans = ans ^ a[i];
		}

		cout << "A number that meets odd amount of times is " << ans << endl;
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}