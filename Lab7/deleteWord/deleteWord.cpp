/*
Удалить из строки заданное слово.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt										output.txt
	five years										 years

	word, you want to delete:
	five

Test case №2
	input.txt										output.txt
	five years										five

	word, you want to delete:
	years

Test case №3
	input.txt										output.txt
	five five five									

	word, you want to delete:
	five
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdio>
#include"cStrings.h"

using namespace std;

const char* separartors = " ,\n\t"; 
const char* notExistingError = "The file is not existing";
const char* emptyFileError = "The file is empty";

char* getWord() {
	char* word = new char [100];
	cout << "Enter, please, a word you need to delete from the text\n"; 
	cin >> word;
	return word;
}

void findWords(char* word, char* initialString, ofstream& fout) {
	char* temporaryString = new char[1000];
	strcpy(temporaryString, initialString);
	char *terminalString = new char[1000];
	strcpy(terminalString, initialString);
	char* foundWord = strtok(temporaryString, separartors);

	while (foundWord != NULL) {
		if (isEqual(foundWord, word)) {
			terminalString = deleteWord(word, terminalString);
		}
		foundWord = strtok(NULL, separartors);
	}
	fout << terminalString << endl;
	return;
}

void readingOfFile(FILE* fileIn, char* word) {
	char *initialString = new char[1000];

	if (fgets(initialString, 1000, fileIn) != NULL) {
		ofstream fout("output.txt");
		do {
			findWords(word, initialString, fout);
		} while (fgets(initialString, 1000, fileIn) != NULL);
	}
	else {
		error(emptyFileError);
	}

	fclose(fileIn);
}

using namespace std;

int main() {
	char *word = getWord();
	FILE *fileIn;

	if (fopen_s(&fileIn, "input.txt", "rt") == NULL) {
		readingOfFile(fileIn, word);
	}
	else {
		error(notExistingError);
	}

	system("pause");

	return 0;
}