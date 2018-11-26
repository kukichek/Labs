#include<string>
#include<fstream>
#include<iostream>
#include"commands.h"

using namespace std;

string** createArray(int n, int m) {
	string **words = new string *[n];
	for (int i = 0; i < n; ++i) {
		words[i] = new string[m];
	}
	return words;
}

bool isSentenceEnd(char c) {
	bool eos = (c == '.') || (c == '!') || (c == '?');
	return eos;
}

bool proccessing(string& word) {
	char c = word[word.length() - 1];
	if (!isalnum(c)) {
		word.erase(word.length() - 1);
	}
	word[0] = tolower(word[0]);
	return isSentenceEnd(c);
}

template <typename T> T max(T a, T b) {
	return a < b ? b : a;
}

void counter(ifstream& fin, string word, int &numberOfSentence, int &maxSentenceLen) {
	int sentenceLen = 0;
	char c;
	do {
		sentenceLen++;
		c = word[word.length() - 1];
		if (isSentenceEnd(c)) {
			maxSentenceLen = max(maxSentenceLen, sentenceLen);
			sentenceLen = 0;
			numberOfSentence++;
		}
	} while (fin >> word);
	if (!isSentenceEnd(c)) {
		numberOfSentence++;
	}
	return;
}

void filling(string** words, int n, int m, ifstream& fin) {
	int curI = 0;
	int curJ = 0;
	string word;
	while (fin >> word) {
		bool isEOS = proccessing(word);
		words[curI][curJ] = word;
		if (isEOS) {
			curJ = 0;
			curI++;
		}
		else {
			curJ++;
		}
	}
	return;
}

bool checkRow(string word, string *words, int m) {
	int i = 0;
	for (int i = 0; i < m; ++i) {
		if (word == words[i]) {
			return 1;
		}
	}
	return 0;
}

bool checkingWord(string word, string **words, int n, int m) {
	bool isFound = 1;
	for (int i = 1; i < n; ++i) {
		isFound = isFound && checkRow(word, words[i], m);
	}
	return isFound;
}

void findGeneralWord(string **words, int numberOfSentences, int maxSentenceLen) {
	int i = 0;
	while ((i < maxSentenceLen) && (words[0][i] != "") && !checkingWord(words[0][i], words, numberOfSentences, maxSentenceLen)) {
		i++;
	}
	if (i < maxSentenceLen && words[0][i] != "") {
		ofstream fout("output.txt");
		fout << "The word that is found in all sentences is \"" << words[0][i] << '\"' << endl;
	}
	else {
		cout << "There isn't any words that meets the conditions\n";
	}
}

void readData(ifstream &fin) {
	string word;

	if (fin >> word) {
		int numberOfSentences = 0;
		int maxSentenceLen = 0;
		counter(fin, word, numberOfSentences, maxSentenceLen);
		fin.close();

		string **words = createArray(numberOfSentences, maxSentenceLen);
		fin.open("input.txt");
		filling(words, numberOfSentences, maxSentenceLen, fin);

		findGeneralWord(words, numberOfSentences, maxSentenceLen);
	}
	else {
		cout << "The file is empty\n";
	}
}

void openFile() {
	ifstream fin("input.txt");

	if (fin) {
		readData(fin);
	}
	else {
		cout << "The file is not existing\n";
	}
}