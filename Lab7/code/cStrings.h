#pragma once

void error(const char* typeOfError); // ��������� �� ������� ��� ������ �� �����

char* deleteWord(char* word, char* initialString); // �������� ����� word �� ������ 
												   // (� ������ ����, ��� ����� word ���� � �������� ������)

bool isEqual(char* word1, char* word2); // ���������� ��� ������ �� ���������

char* turnOverWord(char* word); // �������������� ����� ����� �������