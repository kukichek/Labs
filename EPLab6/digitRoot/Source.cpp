/*
�������� ����������� ������� ���������� ��������� ����� ������������ �����. 
�������� ������ ������� ����� ���������� ��������� �������: ���� ������� ��� ����� ����� �����, 
����� ��� ����� ��������� ����� � ��������� ���� �������, �� � ���������� ����� �������� ����������� ����� (�����), 
������� � ���������� �������� ������ ������� �����. ��������: 15 634 -> 19 ->10 -> 1

������ �������, 1 ����, �����������

Test case �1
	15634						A digit root of number 15634 is 1

Test case �2
	5							A digit root of number 5 is 5

Test case �3
	123456789					A digit root of number 123456789 is 9
*/

#include<iostream>
#include"commands.h"

int main() {
	int n = getNum();
	std::cout << "A digit root of number " << n << " is " << digitRoot(n) << std::endl;
 
	system("pause");

	return 0;
}
