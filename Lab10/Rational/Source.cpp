/*
Рациональная (несократимая) дробь представляется парой целых чисел (a,b), где a – числитель, b – знаменатель. 
Создать класс Rational для работы с рациональными дробями. Реализовать конструкторы: 
копирования и инициализации, а также методы:
a.	сложение add, (a,b) + (c,d) = (ad+bc,bd);
b.	умножение mul, (a,b) * (c,d) = (ac, bd);
c.	деление div, (a,b)/(c,d) = (ad,bc);
d.	сравнение equal, greater, less;
e.	вывод print.
Зам. Реализовать приватную функцию сокращения дроби reduce, 
которая обязательно вызывается при выполнении арифметических операций.

Гамезо Валерия, 1 курс, информатика

Test case №1 
	a(2, 3), b(2, 6)						1				
	c.add(a, b)
	c.print(cout)

Test case №2
	a(2, 3), b(2, 6)						2/9
	c.mult(a, b)
	c.print(cout)

Test case №3
	a(2, 3), b(0, 6)						Error, division by zero
	c.div(a, b)								

Test case №4
	a(2, 3), d(4, 6)						number 2/3 is equal than a number 4/6
	a.isEqual(d)

Test case №5
	a(2, 3), e(5, 3)						number 2/3 is less than a number 5/3
	a.isLess(e)								number 2/3 is not greater than a number 5/3

Test case №6
	a(0, 0), b(0, 0)						Error, division by zero
	c.div(a, b)
*/

#include<iostream>
#include"Rational.h"

using namespace std;

int main() {
	Rational a(2, 3), b(0, 6), c;
	/*Rational d(4, 6);
	c.add(a, b);
	c.print(cout);
	cout << endl;

	c.mult(a, b);
	c.print(cout);
	cout << endl;*/

	c.div(a, b);
	c.print(cout);
	cout << endl;

	/*if (a.isEqual(d)) {
		cout << "number ";
		a.print(cout);
		cout << " is equal than a number ";
		d.print(cout);
	} else {
		cout << "number ";
		a.print(cout);
		cout << " is not equal than a number ";
		d.print(cout);
	}
	cout << endl;*/

	/*Rational e(5, 3);
	if (a.isLess(e)) {
		cout << "number ";
		a.print(cout);
		cout << " is less than a number ";
		e.print(cout);
	} else {
		cout << "number ";
		a.print(cout);
		cout << " is not less than a number ";
		e.print(cout);
	}
	cout << endl;

	if (a.isGreater(e)) {
		cout << "number ";
		a.print(cout);
		cout << " is greater than a number ";
		e.print(cout);
	}
	else {
		cout << "number ";
		a.print(cout);
		cout << " is not greater than a number ";
		e.print(cout);
	}
	cout << endl;*/

	system("pause");

	return 0;
}