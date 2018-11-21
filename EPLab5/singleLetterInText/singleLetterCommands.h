#pragma once
#include<string>
#include"singleLetterCommands.h"

using namespace std;

int max(int a, int b);

int chooseCorrectMin(int a, int b);

void processingLine(string line, ofstream& fout);

void openFile();