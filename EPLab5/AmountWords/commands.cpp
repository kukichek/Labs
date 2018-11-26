#include<iostream>
#include<string>
#include<fstream>
#include"List.h"
#include"Node.h"
#include"commands.h"

using namespace std;

bool isFound(string word, List<string> &listOfWords) {
	Node<string>* curNode = listOfWords.getRoot();

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

void out(List<string> listOfWords, ofstream& fout) {
	Node<string>* curNode = listOfWords.getRoot();
	fout << curNode->element << "\t" << curNode->times << endl;
	while (curNode->next != NULL) {
		curNode = curNode->next;
		fout << curNode->element << "\t" << curNode->times << endl;
	}
	return;
}

void makeList(ifstream &fin, string word) {
	ofstream fout("output.txt");
	List<string> listOfWords(word);
	while (fin >> word) {
		if (!isFound(word, listOfWords)) {
			listOfWords.push(word);
		}
	}
	out(listOfWords, fout);
}

void openFile() {
	ifstream fin("input.txt");
	string word;

	if (fin) {
		if (fin >> word) {
			makeList(fin, word);
		}
		else {
			cout << "The file is empty\n";
		}
	}
	else {
		cout << "The file is not existing\n";
	}
}