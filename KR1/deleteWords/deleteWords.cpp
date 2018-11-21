/*
Из текста удалить все слова заданной длины, начинающиеся на согласную

Гамезо Валерия, 1 курс, информатика

Test case №1
	Enter, please, a length of a words you want to delete
	5
	initial string:
	ahjke hereg shd wkj

	terminal string:
	ahjke  shd wkj

Test case №2
	Enter, please, a length of a words you want to delete
	5
	initial string:
	ghjke aereg shd wkj
	drgo erg elrg kewev
	jrbv rebre ge r

	terminal string:
	 aereg shd wkj
	drgo erg elrg 
	jrbv  ge r
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include"file.h"

using namespace std;

const char* notExistingError = "The file is not existing";
const char* emptyFileError = "The file is empty";
const char separators[] = " ,\t\n";
int requiredLen;

char* deleteWord(char* initialString, char* word) {
	char *positionOfWord = strstr(initialString, word);
	char *terminalStringBegin = new char[1000];
	char *terminalStringEnd = new char[1000];
	terminalStringBegin[positionOfWord - initialString] = '\0';
	strncpy(terminalStringBegin, initialString, positionOfWord - initialString); /// TO DO!
	strcpy(terminalStringEnd, positionOfWord + requiredLen);
	strcat(terminalStringBegin, terminalStringEnd);

	delete[] terminalStringEnd;
	return terminalStringBegin;
}

char* findWords(char* initialString, ofstream& fout) {
	char *word;
	char *terminalString = new char[1000];
	strcpy(terminalString, initialString);
	char *temporaryString = new char[1000];
	strcpy(temporaryString, initialString);
	bool isFoundWord = 0;

	word = strtok(temporaryString, separators);

	while (word != NULL) {
		if (isConsonant(word, requiredLen)) {
			terminalString = deleteWord(terminalString, word);
			isFoundWord = 1;
		}
		word = strtok(NULL, separators);
	}

	delete[] word;
	delete[] temporaryString;
	return terminalString;
}

void cuttingStrings(FILE* fileIn, char *initialString) {
	ofstream fout("output.txt");
	
	do {
		fout << findWords(initialString, fout);
	} while (fgets(initialString, 1000, fileIn) != NULL);

	fout.close();
}

void processingOfFile(FILE* fileIn) {
	char *initialString = new char[1000];
	fgets(initialString, 1000, fileIn);

	if (isEmpty(initialString)) {
		cuttingStrings(fileIn, initialString);
	}
	else {
		error(emptyFileError);
	}

	fclose(fileIn);
}

int main() {
	requiredLen = getLen();
	FILE *fileIn = fopen("input.txt", "rt");

	if (fileIn != NULL) {
		processingOfFile(fileIn);
	} else {
		error(notExistingError);
	}

	system("pause");

	return 0;
}