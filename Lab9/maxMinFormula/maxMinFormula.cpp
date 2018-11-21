/*
2.	(4 балла) Пусть дана без ошибок формула, имеющая следующий синтаксис:
<формула>::=<цифра> | max(<формула>, <формула>) | min (<формула>, <формула>)
<цифра>::=0  1  2  3  4  5  6  7  8  9
Например, 8 или max(4, min(3, 5)) или  min(min(3, 5), max(2, max(3, 4))).
Вычислить значение формулы, используя структуру данных стек.

Гамезо Валерия, 1 курс, информатика
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include"class.h"

using namespace std;

class calcExpression {
private:
	string formula;
	stack<node> elementSequence;
	stack<int> result;
public:
	calcExpression(string value = "") : formula(value) {}
	bool isEmpty() {
		return formula == "";
	}
};

class node {
public:
	virtual void execute() {};
};

class figure: public node {
public:
	short int f;
	void execute() {};
};

class operation {
public:
	bool operationIndex; // 1 - max; 0 - min
	void execute() {};
};

void readData(ifstream &fin) {
	string formula;
	fin >> formula;
	calcExpression expression(formula);
	if (!expression.isEmpty()) {

	} else {
		cout << "The file is empty\n";
	}
}

void openFile() {
	string nameOfFile;
	cout << "Enter, please, a name of a file you want to read data from\n";
	cin >> nameOfFile;
	ifstream fin(nameOfFile);
	if (fin) {
		readData(fin);
	} else {
		cout << "The file \"" << nameOfFile << "\" doesn't exist\n";
	}
}

int main() {
	openFile();

	system("pause");

	return 0;
}