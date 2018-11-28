/*
2.	(5 ������) ����������� ����� Queue ����� �����. 
��������� ������� ���������� � ����� �������, ���������� � �� ������ �������.
���. ����� ������������� ������� �� ������� �������� ����� �� ������� ����� ���������� ���������� ��������.
����� ���� ��� ������� X � Y, ���������� ����� �����. 
�� ������ ������� ������������ ����������� �� ������ ����� x � y ��������������. 
���� x<y, �� ����� (x + y) ���������� � ����� ������� X, ����� ����� (x � y) ���������� � ����� ������� Y. 
���������� ���������� ����� �����, ����� ������� ���� �� �������� ������ ������.

������ �������, 1 ����, �����������

Test case �1
	input.txt								output.txt
	X: 1 2 3 4 5 6 7						One of queues will be empty in 8 steps
	Y: 4 3 2 1

Test case �2
	input.txt								output.txt
											The file is empty
Test case �3
	input.txt								output.txt
	X: 1 2 3 4 5 6 7						One of queues will be empty in 0 steps
	Y:

Test case �4
	input.txt								Uncorrect data
	7
	1 2 3 4 5 6 7
	-4
	1 2 3 4					
	
*/

#include<iostream>
#include<string>
#include"fileLib.h"
#include"commands.h"

using namespace std;

int main() {
	ifstream fin("input.txt");
	string error;
	if (isValidFile(fin, error)) {
		readData(fin);
	} else {
		cout << error << endl;
	}

	system("pause");

	return 0;
}