/*
2.	(4 �����) ����� ���� ��� ������ �������, ������� ��������� ���������:
<�������>::=<�����> | max(<�������>, <�������>) | min (<�������>, <�������>)
<�����>::=0  1  2  3  4  5  6  7  8  9
��������, 8 ��� max(4, min(3, 5)) ���  min(min(3, 5), max(2, max(3, 4))).
��������� �������� �������, ��������� ��������� ������ ����.

������ �������, 1 ����, �����������

Test case �1
	input.txt															output.txt
	max(1, max(2, max(3, max(4, max(max(5, 6), max(7, 8))))))			The result is 8

Test case �2
	input.txt															output.txt
	8																	The result is 8

Test case �3
	input.txt															output.txt
	max(4, min(3, 5))													The result is 4

Test case �4
	input.txt															output.txt
	min(min(3, 5), max(2, max(3, 4)))									The result is 3
*/

#include"commands.h"

int main() {
	openFile();

	system("pause");

	return 0;
}