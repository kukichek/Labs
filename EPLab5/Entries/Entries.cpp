/*
Даны два слова. Для каждой буквы первого слова (а) в том числе для повторяющихся в этом слове букв; б) повторяющиеся буквы первого слова не рассматривать) определить, входит ли она во второе слово.
Например, если заданные слова процессор и информация, то для букв первого из них ответом должно быть:
а) нет да да да нет нет нет нет нет, б) нет да да да нет нет.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt				The file is empty

Test case №2
	input.txt				Uncorrect data
	9wf2 ^7^80	

Test case №3
	input.txt				output.txt
	processor information	a) no yes yes no no no no yes no 
							b) no yes yes no no no 

Test case №4
	input.txt				output.txt
	ssssss s				a) yes no no no no no 
							b) yes 
*/

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
			second.replace (pos, 1, "#");
		} else {
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

int main() {
	ifstream fin("input.txt");
	string firstWord, secondWord;

	if (fin) {
		if (fin >> firstWord) {
			fin >> secondWord;
			if (isWord(firstWord) && isWord(secondWord)) {
				ofstream fout("output.txt");
				checkEntriesA(firstWord, secondWord, fout);
				checkEntriesB(firstWord, secondWord, fout);
			} else {
				cout << "Uncorrect data\n";
			}
		} else {
			cout << "The file is empty\n";
		}
	} else {
		cout << "The file is not existing\n";
	}

	system("pause");

	return 0;
}