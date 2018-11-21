/*
Дан текст, состоящий из предложений. Найти слово, 
которое встречается во всех предложениях текста, или сообщить, что такого слова нет.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt														output.txt
	a. a. a. a. b a. c a. a n b. b a n.								The word that is found in all sentences is "a"

Test case №2
	input.txt														output.txt
	But, got. Got but. But got. But! But? but						The word that is found in all sentences is "but"

Test case №3
	input.txt														There isn't any words that meets the conditions
	a. b. c. d. f

Test case №4
	input.txt														output.txt
	a. a. a. a. a													The word that is found in all sentences is "a"

Test case №5
	input.txt														
	. a. a. a. a. a													There isn't any words that meets the conditions
*/

using namespace std;

#include<iostream>
#include<fstream>
#include<string>
#include"fillArray.h"

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

int main() {
	ifstream fin("input.txt");
	string word;

	if (fin) {
		if (fin >> word) {
			int numberOfSentences = 0;
			int maxSentenceLen = 0;
			counter(fin, word, numberOfSentences, maxSentenceLen);
			fin.close();

			string **words = createArray(numberOfSentences, maxSentenceLen);
			fin.open("input.txt");
			filling(words, numberOfSentences, maxSentenceLen, fin);

			int i = 0;
			while ((i < maxSentenceLen) && (words[0][i] != "") && !checkingWord(words[0][i], words, numberOfSentences, maxSentenceLen)) {
				i++;
			}
			if (i < maxSentenceLen && words[0][i] != "") {
				ofstream fout("output.txt");
				fout << "The word that is found in all sentences is \"" << words[0][i] << '\"' << endl;
			} else {
				cout << "There isn't any words that meets the conditions\n";
			}
		}
		else {
			cout << "The file is empty\n";
		}
	}
	else {
		cout << "The file is not existing\n";
	}

	system("pause");

	return 0;
}
