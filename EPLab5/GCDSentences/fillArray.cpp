#include<string>
#include<fstream>
#include"fillarray.h"

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