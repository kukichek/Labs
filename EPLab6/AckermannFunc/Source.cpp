/*
Написать рекурсивную функцию для вычисления значения так называемой функции Аккермана для неотрицательных чисел n и m. 
Функция Аккермана A(n, m) определяется следующим образом:
m + 1, если n = 0;
A(n, m) = А(n - 1, 1), если n ≠ 0, m = 0;
A(n - 1, A(n, m- 1)), если n >0, m >0.

Гамезо Валерия, 1курс, информатика
*/

#include<iostream>
#include"commands.h"

int main() {
	int n, m;
	getNums(n, m);

	std::cout << "Ackermann function (" << n << ", " << m << ") is " << A(n, m) << std::endl;

	system("pause");

	return 0;
}