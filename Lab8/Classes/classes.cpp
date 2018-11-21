/*
����������� ���������� � ������������������ ������ � ������������ �������.
1.	����������� ����� ������������ �����. ����� ������ ���������:
�	������������, � ��� ����� ����������� �� ��������� � ����������� �����������;
�	������ ��������, ���������, ���������, �������, ������������, ��������� ��� ����������� ����� (�������� �� �������� ������ �������);

2.	����������� ������ ����� � �������� ��� ������ � ��������� ������������ �����, ��������� ��������� ������. ����������� �������� ���������� � �������� ��������� �/�� ��������� ������.
3.	����������� ������ ��������� ��� ������ � ��������� ������������ �����, ��������� ��������� ������. ����������� �������� ���������� � �������� ��������� �/�� ��������� ������.

��������:
1)	�������� ��������� ������ � ������������ ����.
2)	��� ������ � ������������ ������� � ��� ��������� ����� ����������� ��������������� ������. ��� ��������� ������������ ����� � ����� ����������� ���� ������������ �����.
3)	�������������� ������ �� ������� ����������� �����, ����� ����������/���������� �� ����� ������� ����������� �����,  � ����� �������� �������� ������� � ���� � ������� � ������ �������� �� ���� �������� ������.

������ �������, 1 ����, �����������
*/

#include<iostream>
#include"class.h"

using namespace std;

complexNum* createNums(int n) {
	complexNum *complexArray = new complexNum[n];
	controlComplexNum controller;
	for (int i = 0; i < n; ++i) {
		complexArray[i] = controller.in();
	}
	return complexArray;
}

void findMax(complexNum* complexArray, int n) {
	complexNum extremum = complexArray[0];
	controlComplexNum controller;
	for (int i = 1; i < n; ++i) {
		extremum = controller.max(extremum, complexArray[i]);
	}

	cout << "The maximal element of an array is ";
	controller.out(extremum);
	cout << endl;
	return;
}

void findMin(complexNum* complexArray, int n) {
	complexNum extremum = complexArray[0];
	controlComplexNum controller;
	for (int i = 1; i < n; ++i) {
		extremum = controller.min(extremum, complexArray[i]);
	}
	cout << "The minimal element of an array is ";
	controller.out(extremum);
	cout << endl;
	return;
}

void checkListStack(complexNum* complexArray, int n) {
	controlComplexNum controller;
	list<complexNum> complexList;
	stack<complexNum> complexStack;
	for (int i = 0; i < n; ++i) {
		complexList.push(complexArray[i]);
		complexStack.push(complexArray[i]);
	}
	cout << "The initial list of complex nums is:\n";
	complexList.out();
	cout << "The initial stack of complex nums is:\n";
	complexStack.out();

	int amountOfDeletedNums;
	do {
		cout << "Enter, please, a number of nums you want to delete from a list and a stack\n";
		cin >> amountOfDeletedNums;
	} while (amountOfDeletedNums < 0);
	
	for (int i = 0; i < amountOfDeletedNums; ++i) {
		complexList.pop();
		complexStack.pop();
	}

	cout << "The terminal list of complex nums is:\n";
	complexList.out();
	cout << "The terminal stack of complex nums is:\n";
	complexStack.out();
}

void testingOfNums() {
	int n;
	do {
		cout << "Enter, plaese, a size of an array of complex nums you want to create\n";
		cin >> n;
	} while (n <= 0 || n > 50);
	complexNum *complexArray = createNums(n);

	findMax(complexArray, n);

	findMin(complexArray, n);
	
	checkListStack(complexArray, n);
}

int main() {
	testingOfNums();

	system("pause");

	return 0;
}