/*
Дан текст, состоящий из предложений. Найти слово, 
которое встречается во всех предложениях текста, или сообщить, что такого слова нет.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt														output.txt
	a. a. a. a. b a. c a. a n b. b a n.								The word that is found in all sentences is "a"

Test case №2
	input.txt														output.txt
	But, got. Got but. But got. But! But? but						The word that is found in all sentences is "but"

Test case №3
	input.txt														There isn't any words that meets the conditions
	a. b. c. d. f

Test case №4
	input.txt														output.txt
	a. a. a. a. a													The word that is found in all sentences is "a"

Test case №5
	input.txt														
	. a. a. a. a. a													There isn't any words that meets the conditions
*/

using namespace std;

#include<iostream>
#include<fstream>
#include<string>
#include"GCDSentenceCommands.h"

int main() {
	openFile();

	system("pause");

	return 0;
}
