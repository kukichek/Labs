/*
1.	(1 балл) Дано математическое выражение в виде строки символов. 
Напишите программу, которая определит, правильно ли расставлены скобки в выражении, 
если оно состоит из скобок типа: ( ) [ ] { }. (использовать структуру данных стек).

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt									output.txt
	()(){}{}{[]({}([]))}						The string is correct

Test case №2
	input.txt									output.txt
	(){}{[]({}([])}								The string is uncorrect

Test case №3
	input.txt									output.txt
	()45{HIIII!}{[boo]I({}([lalala]))}			The string is correct

Test case №4
	input.txt									The file "input.txt" is empty
		
Test case №5
	abracadabra.txt								The file "abracadabra.txt" is not existing
*/

#include"commands.h"

int main() {
	openFile();

	system("pause");

	return 0;
}