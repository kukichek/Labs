#pragma once
#include<fstream>
#include<string>

using namespace std;

bool isWord(string s);

void checkEntriesA(string first, string second, ofstream& fout);

void checkEntriesB(string first, string second, ofstream& fout);

void findEntries(ifstream &fin);

void openFile();
