#pragma once

void error(const char* typeOfError); // ��������� �� ������� ��� ������ �� �����

char* deleteWord(char* word, char* initialString); // �������� ����� word �� ������ 
												   // (� ������ ����, ��� ����� word ���� � �������� ������)

bool isEqual(char* word1, char* word2); // ���������� ��� ������ �� ���������

char* turnOverWord(char* word); // �������������� ����� ����� �������

char* replace(char* initialString, char* str1, char* str2); // �������� ��������� str1 � ������ �� str2
															// (� ������ ����, ��� ��������f str1 ���� � �������� ������)