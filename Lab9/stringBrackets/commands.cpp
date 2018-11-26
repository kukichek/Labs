#include<iostream>
#include"commands.h"

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
		char lastBracket = bracketString.pop();
		bool cond = (abs(lastBracket - c) == 1) || ((abs(lastBracket - c) == 2));
		if (!cond) {
			bracketString.push(lastBracket);
			bracketString.push(c);
		}
	}
	else {
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
	}
	else {
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
	}
	else {
		cout << "The file \"" << nameOfFile << "\" is not existing\n";
		return;
	}
}