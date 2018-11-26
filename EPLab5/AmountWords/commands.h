#pragma once
#include<string>
#include<fstream>
#include"List.h"

using namespace std;

bool isFound(string word, List<string> &listOfWords);

void out(List<string> listOfWords, ofstream& fout);

void makeList(ifstream &fin, string word);

void openFile();