#pragma once
#include<string>

using namespace std;

string** createArray(int n, int m);

bool isSentenceEnd(char c);

bool proccessing(string& word); // удаление знаков препинания из конца слова

template <typename T> T max(T a, T b);

void counter(ifstream& fin, string word, int &numberOfSentence, int &maxSentenceLen); // подсчет размеров двумерной матрицы, 
																					  // в которую будут заноситься слова,
																					  // где numberOfSentence - n, а maxSentenceLen - m

void filling(string** words, int n, int m, ifstream& fin); // заполнение двумерной матрицы словами

bool checkRow(string word, string *words, int m);

bool checkingWord(string word, string **words, int n, int m);

void findGeneralWord(ifstream &fin, int numberOfSentences, int maxSentenceLen);

void readData(ifstream &fin);

void openFile();