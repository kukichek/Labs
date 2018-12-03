/**
4. По данному натуральному числу n найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/n!.
Количество действий должно быть пропорционально n.
Напишите программу, которая считывает значение n и выводит результат в виде действительного числа.
К чему будет стремиться эта сумма при росте числа n?

Гамезо Валерия, 1 группа, информатика

Sample Test №1
	0   Uncorrect data

Sample Test №2
	-7  Uncorrect data

Sample Test №3
	1   sum = 2

Sample Test №4
	5   sum = 2.71667

Sample Test №5
	9   sum = 2.71828
**/

#include <iostream>

using namespace std;

int main() {
	int n;
	int f = 1; /// факториал числа n
	double sum = 1; /// сумма прогрессии

	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;

	if (n > 0) { /// проверка для дураков
		for (int i = 1; i <= n; i++) { /// вычисление суммы
			f *= i;
			sum += 1. / f;
		}

		cout << "The sum in the form of 1+1/1!+1/2!+1/3!+...+1/n! is " << sum << endl; /// сумма стремится к е
	}
	else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}
