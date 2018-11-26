/*
Написать рекурсивную функцию для вычисления индекса максимального элемента массива из n элементов

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt								output.txt
	-7										A size of an array isn't correct
	0 4.5 14 -24.4 6

Test case №2
	input.txt								output.txt
	5										Max element is 14
	0 4.5 14 -24.4 6

Test case №3
	input.txt								output.txt
	0										A size of an array isn't correct
	5

Test case №4
	input.txt								output.txt
	1										Max element is 5
	5

Test case №5
	input.txt								The file is empty
*/

#include<iostream>
#include"fileLib.h"
#include"commands.h"

using namespace std;

int main() {
	ifstream fin("input.txt");
	string error;

	if (isValidFile(fin, error)) {
		readData(fin);
	} else {
		cout << error << endl;
	}

	system("pause");

	return 0;
}