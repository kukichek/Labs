/*
Реализовать 4 функции на простейшие арифметические операции (+, -, *, /).
Каждая функция должна принимать два вещественных числа и возвращать результат операции в виде вещественного числа.
Напишите функцию, которая принимает указатель на функцию в качестве параметра. Добавьте меню,
в котором пользователь может выбрать желаемую операцию.

Гамезо Валерия, 1 курс, информатика

Test case №1
	6 0.7					The answer is: 6.7
	adding

Test case №2
	5 6						The answer is: -1
	substraction

Test case №3
	3 -0.66666666			The answer is: -2
	multiplication

Test case №4
	2 1.41					The answer is: 1.41844
	division
*/

#include<iostream>

using namespace std;

double adding(double a, double b) {
	return a + b;
}

double substraction(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

double division(double a, double b) {
	return a / b;
}

int testingOnCorrectnessOfIndex(int &index) { // проверка принимает ли индекс допустимые значения
	do {
		cout << "Choose index of an operation you want to carry out with these numbers:\n";
		cout << "0 - adding;\n";
		cout << "1 - substraction;\n";
		cout << "2 - multiplication;\n";
		cout << "3 - division;\n";
		cin >> index;
	} while ((index < 0) || (index > 3));
	return index;
}

double operation(double a, double b, double(*op)(double a, double b)) {
	return op(a, b);
}

double(*Operations[4])(double a, double b) = { adding, substraction, multiplication, division };

int main() {
	double a, b;
	cout << "Enter, please, numbers a, b that belongs to a quantity of real numbers\n";
	cin >> a >> b;

	int indexOfOperation; // храниться индекс операции в массиве указателей на функцию
	testingOnCorrectnessOfIndex(indexOfOperation);

	cout << "The answer is: " << operation(a, b, Operations[indexOfOperation]) << endl;

	system("pause");

	return 0;
}