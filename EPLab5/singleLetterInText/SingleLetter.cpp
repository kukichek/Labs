/*
Дан текст. В выходной файл записать только те буквы слов, 
которые встречаются в словах текста только один раз. 
Например, для текста процессор информация, то ответом должно быть: п е ф м а я.

Гамезо Валерия, 1 курс, инфортматика

Test case №1
	input.txt											output.txt
	Didn't know what time it was,						k o h m e s 
	The lights were low,								i g s r o 
	I leaned back on my radio,							l b c k m y r 
	Some cat was layin' down some rock n roll,			t y i d k
	Lotta soul, he said.								u h e i d						
	Then the loud sound did seem to fade,				l i m f a
	Came back like a slow voice							m b s w v
	On a wave of phase,									n w v f p h s
	That weren't no DJ,									h a w r o d j
	That was hazy cosmic jive.							w z y o m j v e	
*/



#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int chooseCorrectMin(int a, int b) {
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	return a < b ? a : b;
}

void processingLine(string line, ofstream& fout) {
	for (int i = 0; i < line.length(); ++i) {
		if (isalpha(line[i])) {
			int rightPos = max(line.rfind(toupper(line[i])), line.rfind(tolower(line[i])));
			int leftPos = chooseCorrectMin(line.find(toupper(line[i])), line.find(tolower(line[i])));
			if (rightPos == leftPos) {
				fout << char(tolower(line[i])) << ' ';
			}
		}
	}
}

int main() {
	ifstream fin("input.txt");
	string line;

	if (fin) {
		if (getline(fin, line)) {
			ofstream fout("output.txt");
			do {
				processingLine(line, fout);
				fout << endl;
			} while (getline(fin, line));
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