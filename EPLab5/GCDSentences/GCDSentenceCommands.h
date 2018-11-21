#pragma once
#include<string>

using namespace std;

string** createArray(int n, int m);

bool isSentenceEnd(char c);

bool proccessing(string& word); // �������� ������ ���������� �� ����� �����

template <typename T> T max(T a, T b);

void counter(ifstream& fin, string word, int &numberOfSentence, int &maxSentenceLen); // ������� �������� ��������� �������, 
																					  // � ������� ����� ���������� �����,
																					  // ��� numberOfSentence - n, � maxSentenceLen - m

void filling(string** words, int n, int m, ifstream& fin); // ���������� ��������� ������� �������

bool checkRow(string word, string *words, int m);

bool checkingWord(string word, string **words, int n, int m);

void findGeneralWord(ifstream &fin, int numberOfSentences, int maxSentenceLen);

void readData(ifstream &fin);

void openFile();