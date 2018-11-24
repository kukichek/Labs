/*
1.	(1 балл) Дано математическое выражение в виде строки символов. 
Напишите программу, которая определит, правильно ли расставлены скобки в выражении, 
если оно состоит из скобок типа: ( ) [ ] { }. (использовать структуру данных стек).

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt									output.txt
	()(){}{}{[]({}([]))}						The string is correct

Test case №2
	input.txt									output.txt
	(){}{[]({}([])}								The string is uncorrect

Test case №3
	input.txt									output.txt
	()45{HIIII!}{[boo]I({}([lalala]))}			The string is correct

Test case №4
	input.txt									The file "input.txt" is empty
		
Test case №5
	abracadabra.txt								The file "abracadabra.txt" is not existing
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"class.h"

using namespace std;

bool isBracket(char c) {
	bool isSquareBrackets = (c == '[') || (c == ']');
	bool isRoundBrackets = (c == '(') || (c == ')');
	bool isBraces = (c == '{') || (c == '}');
	if (isSquareBrackets || isRoundBrackets || isBraces) {
		return 1;
	}
	return 0;
}

void processingOfStack(char c, Stack<char> &bracketString) {
	if (!bracketString.isEmpty()) {
		char lastBracket = bracketString.getLast();
		if ((abs(lastBracket - c) == 1) || ((abs(lastBracket - c) == 2))) {
			bracketString.pop();
		} else {
			bracketString.push(c);
		}
	} else {
		bracketString.push(c);
	}
	return;
}

void processingOfString(char c, ifstream &fin) {
	ofstream fout("output.txt");
	Stack<char> bracketString;
	do {
		if (isBracket(c)) {
			processingOfStack(c, bracketString);
		}
	} while (fin >> c);
	if (bracketString.isEmpty()) {
		fout << "The string is correct\n";
	} else {
		fout << "The string is uncorrect\n";
	}
}

void processingOfFile(ifstream& fin, string nameOfFile) {
	char c;
	if (fin >> c) {
		processingOfString(c, fin);
	}
	else {
		cout << "The file \"" << nameOfFile << "\" is empty\n";
		return;
	}
}

void openFile() {
	string nameOfFile;
	cout << "Enter, please, a name of file you want to read data\n";
	cin >> nameOfFile;
	ifstream fin(nameOfFile);

	if (fin) {
		processingOfFile(fin, nameOfFile);
	} else {
		cout << "The file \"" << nameOfFile << "\" is not existing\n";
		return;
	}
}

int main() {
	openFile();

	system("pause");

	return 0;
}