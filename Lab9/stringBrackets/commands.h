#pragma once
#include<fstream>
#include<string>
#include"Stack.h"

bool isBracket(char c);

void processingOfStack(char c, Stack<char> &bracketString);

void processingOfString(char c, std::ifstream &fin);

void processingOfFile(std::ifstream& fin, std::string nameOfFile);

void openFile();