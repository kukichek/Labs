/*
Дан код программы на С++. Вывести построчно все операции и частоту их использования в программе.

Гамезо Валерия, 1 курс, информатика
*/

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include"cStrings.h"

const char* notExistingError = "The file is not existing";
const char* emptyFileError = "The file is empty";

int operations[22];
const char* stringCin = "cin";
const char* stringCout = "cout";
int countCin;
int countCout;

void outWithoutNull(const char* sign, int i, ofstream &fout) {
	if (operations[i]) {
		fout << '\"' << sign << "\": " << operations[i] << endl;
	}
	return;
}

void out(ofstream& fout) {
	operations[20] -= 2 * countCout;
	operations[21] -= 2 * countCin;

	for (int i = 12; i < 22; ++i) {
		operations[i] /= 2;
	}

	fout << "The frequency of operations in given code is:\n";

	outWithoutNull("=", 0, fout);
	outWithoutNull("~", 1, fout);
	outWithoutNull("|", 2, fout);
	outWithoutNull("!", 3, fout);
	outWithoutNull("^", 4, fout);
	outWithoutNull("*", 5, fout);
	outWithoutNull("/", 6, fout);
	outWithoutNull("+", 7, fout);
	outWithoutNull("-", 8, fout);
	outWithoutNull("%", 9, fout);
	outWithoutNull("<", 10, fout);
	outWithoutNull(">", 11, fout);
	outWithoutNull(">=", 12, fout);
	outWithoutNull("<=", 13, fout);
	outWithoutNull("==", 14, fout);
	outWithoutNull("&&", 15, fout);
	outWithoutNull("||", 16, fout);
	outWithoutNull("!=", 17, fout);
	outWithoutNull("++", 18, fout);
	outWithoutNull("--", 19, fout);
	outWithoutNull("<<", 20, fout);
	outWithoutNull(">>", 21, fout);

	return;
}

void counter(char* string) {
	int n = strlen(string);
	for (int i = 0; i < n; ++i) {
		switch (string[i]) {
		case '=':
			if (string[i + 1] == '=' || string[i - 1] == '=') {
				operations[14]++;
				break;
			}
			if (string[i - 1] == '!') {
				operations[17] ++;
				break;
			}
			if (string[i - 1] == '>') {
				operations[12]++;
				break;
			}
			if (string[i - 1] == '<') {
				operations[13]++;
				break;
			}
			operations[0]++;
			break;
		case '~':
			operations[1]++;
			break;
		case '|':
			if (string[i + 1] == '|' || string[i - 1] == '|') {
				operations[16]++;
				break;
			}
			operations[2]++;
			break;
		case '!':
			if (string[i + 1] == '=') {
				operations[17]++;
				break;
			}
			operations[3]++;
			break;
		case '^':
			operations[4]++;
			break;
		case '*':
			operations[5]++;
			break;
		case '/':
			operations[6]++;
			break;
		case '+':
			if (string[i + 1] == '+' || string[i - 1] == '+') {
				operations[18]++;
				break;
			}
			operations[7]++;
			break;
		case '-':
			if (string[i + 1] == '-' || string[i - 1] == '-') {
				operations[19]++;
				break;
			}
			operations[8]++;
			break;
		case '%':
			operations[9]++;
			break;
		case '<':
			if (string[i + 1] == '<' || string[i - 1] == '<') {
				operations[20]++;
				break;
			}
			if (string[i + 1] == '=') {
				operations[13]++;
				break;
			}
			operations[10]++;
			break;
		case '>':
			if (string[i + 1] == '>' || string[i - 1] == '>') {
				operations[21]++;
				break;
			}
			if (string[i + 1] == '=') {
				operations[12]++;
				break;
			}
			operations[11]++;
			break;
		}
	}
	if (strstr(string, stringCin) != NULL) {
		countCin++;
	}
	if (strstr(string, stringCout) != NULL) {
		countCout++;
	}
	return;
}

int main() {
	FILE *fileIn;

	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		char *initialString = new char[1000];

		if (fgets(initialString, 1000, fileIn) != NULL) {
			ofstream fout("output.txt");
			do {
				counter(initialString);
			} while (fgets(initialString, 1000, fileIn) != NULL);

			out(fout);
		} else {
			error(emptyFileError);
		}
	} else {
		error(notExistingError);
	}

	system("pause");

	return 0;
}