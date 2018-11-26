#include"commands.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isWord(string s) {
	for (int i = 0; i < s.length(); ++i) {
		if (!isalpha(s[i])) {
			return 0;
		}
	}
	return 1;
}

void checkEntriesA(string first, string second, ofstream& fout) {
	fout << "a) ";
	for (int i = 0; i < first.length(); ++i) {
		int pos = second.find(first[i]);
		if (pos != -1) {
			fout << "yes ";
			second.replace(pos, 1, "#");
		}
		else {
			fout << "no ";
		}
	}
	fout << endl;
	return;
}

void checkEntriesB(string first, string second, ofstream& fout) {
	fout << "b) ";
	for (int i = 0; i < first.length(); ++i) {
		if (i == first.find(first[i])) {
			int pos = second.find(first[i]);
			if (pos != -1) {
				fout << "yes ";
				second.replace(pos, 1, "#");
			}
			else {
				fout << "no ";
			}
		}
	}
	fout << endl;
	return;
}

void findEntries(ifstream &fin) {
	string firstWord, secondWord;
	if (fin >> firstWord) {
		fin >> secondWord;
		if (isWord(firstWord) && isWord(secondWord)) {
			ofstream fout("output.txt");
			checkEntriesA(firstWord, secondWord, fout);
			checkEntriesB(firstWord, secondWord, fout);
		}
		else {
			cout << "Uncorrect data\n";
		}
	}
	else {
		cout << "The file is empty\n";
	}
}

void openFile() {
	ifstream fin("input.txt");

	if (fin) {
		findEntries(fin);
	}
	else {
		cout << "The file is not existing\n";
	}
}
