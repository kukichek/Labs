/*
Дана строка. «Перевернуть» в строке все слова (
например: «Жили были дед и баба» - «илиЖ илыб дед и абаб»). 
Зам. Исходную строку не менять

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt										output.txt
	Everybody dance now!							ydobyrevE ecnad !won

Test case №2
	input.txt										output.txt
	I have got no roots								I evah tog on stoor
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include"cStrings.h"

const char* notExistingError = "The file is not existing\n";
const char* emptyFileError = "The file is empty\n";
const char* separartors = " ,\n\t";

using namespace std;

char* turnOverString(char* word, char* initialString) {
	char* terminalStringBegin = new char[1000];
	char* terminalStringEnd = new char[1000];
	char *positionOfWord = strstr(initialString, word);

	terminalStringBegin[positionOfWord - initialString] = '\0';
	strncpy(terminalStringBegin, initialString, positionOfWord - initialString);
	strcpy(terminalStringEnd, positionOfWord + strlen(word));
	
	word = turnOverWord(word);

	strcat(terminalStringBegin, word);
	strcat(terminalStringBegin, terminalStringEnd);

	delete[] terminalStringEnd;
	return terminalStringBegin;
}

void findWords(char* cString, ofstream& fout) {
	char* temporaryString = new char[1000];
	strcpy(temporaryString, cString);
	char *terminalString = new char[1000];
	strcpy(terminalString, cString);
	char* foundWord = strtok(temporaryString, separartors);

	while (foundWord != NULL) {
		terminalString = turnOverString(foundWord, terminalString);
		foundWord = strtok(NULL, separartors);
	}
	fout << terminalString << endl;
	return;
}

int main() {
	FILE *fileIn;
	char* cString = new char[1000];

	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		if (fgets(cString, 1000, fileIn) != NULL) {
			ofstream fout("output.txt");
			findWords(cString, fout);
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