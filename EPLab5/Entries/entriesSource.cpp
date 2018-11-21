/*
Даны два слова. Для каждой буквы первого слова (а) в том числе для повторяющихся в этом слове букв; б) повторяющиеся буквы первого слова не рассматривать) определить, входит ли она во второе слово.
Например, если заданные слова процессор и информация, то для букв первого из них ответом должно быть:
а) нет да да да нет нет нет нет нет, б) нет да да да нет нет.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt				The file is empty

Test case №2
	input.txt				Uncorrect data
	9wf2 ^7^80	

Test case №3
	input.txt				output.txt
	processor information	a) no yes yes no no no no yes no 
							b) no yes yes no no no 

Test case №4
	input.txt				output.txt
	ssssss s				a) yes no no no no no 
							b) yes 
*/

#include"entriesCommands.h"

int main() {
	openFile();

	system("pause");

	return 0;
}