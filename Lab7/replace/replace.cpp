/*
В данной строке все вхождения подстроки str1 заменить подстрокой str2.

Гамезо Валерия, 1 курс, информатика

Test case №1
	str1: can't
	str2: can
	input.txt										output.txt
	I can't run										I can run

Test case №2
	str1: I see a bird
	str2: 938fh283 29   !!&3&
	input.txt										output.txt
	I see a bird									938fh283 29   !!&3&
	I see a bird									938fh283 29   !!&3&
	I see a bird									938fh283 29   !!&3&	

Test case №3
	str1: I see a bird
	str2: 
	input.txt										output.txt
	I see a bird									
	I see a bird									
	I see a bird									
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include"cStrings.h"

const char* notExistingError = "The file is not existing\n";
const char* emptyFileError = "The file is empty\n";

using namespace std;

void getWords(char* str1, char* str2) {
	cout << "Enter, please, a string you want to replace\n";
	gets_s(str1, 1000);
	cout << "Enter, please, a string you want to be a replacement\n";
	gets_s(str2, 1000);
	return;
}

void findSubstring(char* initialString, char* str1, char* str2, ofstream& fout) {
	char *terminalString = new char[1000];
	strcpy(terminalString, initialString);

	char *positionOfSubstr = strstr(terminalString, str1);

	while (positionOfSubstr != NULL && ((positionOfSubstr - terminalString < strlen(terminalString)))) {
		terminalString = replace(terminalString, str1, str2);
	}

	fout << terminalString;
	return;
}

int main() {
	FILE *fileIn;
	
	char* initialString = new char[1000];
	char* str1 = new char[1000];
	char* str2 = new char[1000];
	getWords(str1, str2);

	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		if (fgets(initialString, 1000, fileIn) != NULL) {
			ofstream fout("output.txt");
			do {
				findSubstring(initialString, str1, str2, fout);
			} while (fgets(initialString, 1000, fileIn) != NULL);
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