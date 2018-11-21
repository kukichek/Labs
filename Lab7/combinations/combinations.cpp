/*
Дана строка. Посчитать в ней частоты всех двухбуквенных сочетаний 
без учета регистра и без учета символов, не являющихся буквами.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt									output.txt
	ABBA										The frequency of biiteral combinations is:
												ab : 1
												ba : 1
												bb : 1

Test case №2
	input.txt									output.txt
	abba										The frequency of biiteral combinations is:
												ab : 1
												ba : 1
												bb : 1

Test case №3
	input.txt									output.txt
	9 inch nails								The frequency of biiteral combinations is:
												ai : 1
												ch : 1
												il : 1
												in : 1
												ls : 1
												na : 1
												nc : 1

Test case №3
	input.txt									output.txt
	bababab BABABAB56							The frequency of biiteral combinations is:
	aBaBAbAb   BabA								ab : 11
												ba : 11												
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include"cStrings.h"

int frequencyDifCombinations[26 * 26];
const char* notExistingError = "The file is not existing\n";
const char* emptyFileError = "The file is empty\n";

using namespace std;

void plusCombination(char a, char b) {
	int number = 0;
	if (a - 'a' < 0) {
		number += a - 'A';
	} else {
		number += a - 'a';
	}
	number *= 26;

	if (b - 'a' < 0) {
		number += b - 'A';
	}
	else {
		number += b - 'a';
	}

	frequencyDifCombinations[number] ++;
	return;
}

void countCombinations(char* cString) {
	int n = strlen(cString);
	for (int i = 0; i < n - 1; ++i) {
		if (isalpha(cString[i]) && isalpha(cString[i + 1])) {
			plusCombination(cString[i], cString[i + 1]);
		}
	}

	return;
}

void outCombinationFrequency(ofstream &fout) {
	fout << "The frequency of biiteral combinations is:\n";
	for (int i = 0; i < 26 * 26; ++i) {
		if (frequencyDifCombinations[i]) {
			fout << char(i / 26 + 'a') << char(i % 26 + 'a') << " : " << frequencyDifCombinations[i] << endl;
		}
	}
	return;
}

int main() {
	FILE *fileIn;
	char* cString = new char[1000];

	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		if (fgets(cString, 1000, fileIn) != NULL) {
			ofstream fout("output.txt");
			do {
				countCombinations(cString);
			} while (fgets(cString, 1000, fileIn) != NULL);
			outCombinationFrequency(fout);
		}
		else {
			error(emptyFileError);
		}
	}
	else {
		error(notExistingError);
	}

	system("pause");

	return 0;
}