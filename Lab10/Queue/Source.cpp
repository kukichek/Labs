/*
2.	(5 баллов) Разработать класс Queue целых чисел. 
Очередной элемент включается в хвост очереди, исключение – из головы очереди.
Зам. Можно реализовывать очередь на массиве конечной длины со сдвигом после исключения очередного элемента.
Пусть даны две очереди X и Y, содержащие целые числа. 
Из каждой очереди одновременно извлекается по одному числу x и y соответственно. 
Если x<y, то число (x + y) помещается в конец очереди X, иначе число (x – y) помещается в конец очереди Y. 
Необходимо определить число шагов, через которые одна из очередей станет пустой.

Гамезо Валерия, 1 курс, информатика

Test case №1
	input.txt								output.txt
	X: 1 2 3 4 5 6 7						One of queues will be empty in 8 steps
	Y: 4 3 2 1

Test case №2
	input.txt								output.txt
											The file is empty
Test case №3
	input.txt								output.txt
	X: 1 2 3 4 5 6 7						One of queues will be empty in 0 steps
	Y:

Test case №4
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