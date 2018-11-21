#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<fstream>
#include"cStrings.h"

using namespace std;

void error(const char* typeOfError) {
	cout << typeOfError << endl;
	return;
}

char* deleteWord(char* word, char* initialString) {
	char *positionOfWord = strstr(initialString, word);
	char* terminalStringBegin = new char[1000];
	char *terminalStringEnd = new char[1000];
	terminalStringBegin[positionOfWord - initialString] = '\0';
	strncpy(terminalStringBegin, initialString, positionOfWord - initialString);
	strcpy(terminalStringEnd, positionOfWord + strlen(word));
	strcat(terminalStringBegin, terminalStringEnd);

	delete[] terminalStringEnd;
	return terminalStringBegin;
}

bool isEqual(char* word1, char* word2) {
	if (strlen(word1) == strlen(word2)) {
		for (int i = 0; i < strlen(word1); ++i) {
			if (word1[i] != word2[i]) {
				return 0;
			}
		}
	}
	else {
		return 0;
	}
	return 1;
}