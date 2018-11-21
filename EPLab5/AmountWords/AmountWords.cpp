/*
Дан текст. Посчитать частоту слов в тексте.

Гамезо Валерия, 1 курс, информатика

Test case №1
	intput.txt												output.txt
	On my own												On	2
	On my own												my	2
															own	2

Test case №2
	intput.txt												output.txt
	May I have your attention please						May			2
	May I have your attention please						I			3
	Will the real Slim Shady please stand up				have		3
	I repeat will the real Slim Shady please stand up		your		2
	We are gonna have a problem here						attention	2
															please		4
															Will		1
															the			2
															real		2
															Slim		2
															Shady		2
															stand		2
															up			2
															repeat		1
															will		1
															We			1
															are			1
															gonna		1
															a			1
															problem		1
															here		1

*/

#include<iostream>
#include<fstream>
#include<string>
#include"list.h"

using namespace std;

bool isFound(string word, list<string> &listOfWords) {
	node<string>* curNode = listOfWords.getRoot();

	string curString = curNode->element;
	if (curString == word) {
		curNode->times++;
		return 1;
	}
	
	while (curNode->next != NULL) {
		curNode = curNode->next;
		curString = curNode->element;
		if (curString == word) {
			curNode->times++;
			return 1;
		}
	}

	return 0;
}

void out(list<string> listOfWords, ofstream& fout) {
	node<string>* curNode = listOfWords.getRoot();
	fout << curNode->element << "\t" << curNode->times << endl;
	while (curNode->next != NULL) {
		curNode = curNode->next;
		fout << curNode->element << "\t" << curNode->times << endl;
	}
	return;
}

int main() {
	ifstream fin("input.txt");
	string word;

	if (fin) {
		if (fin >> word) {
			ofstream fout("output.txt");
			list<string> listOfWords(word);
			while (fin >> word) {
				if (!isFound(word, listOfWords)) {
					listOfWords.push(word);
				}
			}
			out(listOfWords, fout);
		} else {
			cout << "The file is empty\n";
		}
	} else {
		cout << "The file is not existing\n";
	}

	system("pause");

	return 0;
}