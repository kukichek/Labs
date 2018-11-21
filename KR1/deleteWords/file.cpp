#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include"file.h"

using namespace std;

void error(const char* typeOfError) {
	cout << typeOfError << endl;
	return;
}

bool isEmpty(char* string) {
	return string != NULL ? 1 : 0;
}

int getLen() {
	int requiredLen;
	do {
		cout << "Enter, please, a length of a words you want to delete\n";
		cin >> requiredLen;
	} while (requiredLen < 1);
	return requiredLen;
}

bool isConsonant(char* word, int requiredLen) {
	if (strlen(word) == requiredLen) {
		if (isalpha(word[0])) {
			char c = toupper(word[0]);
			if ((c != 'A') && (c != 'I') && (c != 'E') && (c != 'O') && (c != 'U')) {
				return 1;
			}
		}
	}
	return 0;
}