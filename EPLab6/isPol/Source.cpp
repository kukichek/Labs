/*
Написать рекурсивную функцию, определяющую, является ли симметричной часть строки s, начиная с i-го элемента и кончая j-м

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt								The file is empty

Test case №2
	input.txt								output.txt
	3 1										The string is polynomial
	abab

Test case №3
	input.txt								output.txt
	1 3										The string is polynomial
	abab

Test case №4
	input.txt								output.txt
	0 3										The string isn't polynomial
	abab

Test case №5
	input.txt								output.txt
	0 7										The string is polynomial
	V3_""_3V
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