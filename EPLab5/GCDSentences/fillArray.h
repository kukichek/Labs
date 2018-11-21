#pragma once
#include<string>

using namespace std;

string** createArray(int n, int m);

bool isSentenceEnd(char c);

bool proccessing(string& word); // удаление знаков препинания из конца слова

template <typename T> T max(T a, T b);

void counter(ifstream& fin, string word, int &numberOfSentence, int &maxSentenceLen); // подсчет размеров двемерной матрицы, 
																					  // в которую будут заноситься слова,
																					  // где numberOfSentence - n, а maxSentenceLen - m

void filling(string** words, int n, int m, ifstream& fin); // заполнение двумерной матрицы словами