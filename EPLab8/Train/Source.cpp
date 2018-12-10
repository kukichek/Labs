/*
Определить класс с именем TRAIN, содержащий следующие поля: название пункта назначения; номер поезда; время отправления. 
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа TRAIN.
Разработать консольное приложение, выполняющую следующие действия:
Разработать меню пользователя.
	ввод данных осуществлять из файла, имя которого вводит пользователь, данные помещать в список объектов типа TRAIN;
	отсортировать записи по времени отправления поезда;
	отсортировать записи в алфавитном порядке по названиям пунктов назначения;
	вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени, если таких поездов нет, 
выдать на дисплей соответствующее сообщение.
	вывод на экран информации о поездах, направляющихся в пункт, название которого введено с клавиатуры, если таких поездов нет, 
выдать на дисплей соответствующее сообщение.

Гамезо Валеря, 1 курс, информатика

Test case №1
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	2
	List of train wasn't loaded
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	1
	Enter, please, a name of a file you want to read data from
	error.rxr
	The file is not found
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	4

Test case №2
	Choose an operation you want to execute:										in1.txt
	1 - load data from a file;														b
	2 - get information about trains which go after a definite time;				1
	3 - get information about trains which go to a definite destination;			00:00
	4 - exit;																		a
	1																				2
	Enter, please, a name of a file you want to read data from						00:00
	in1.txt																			h
	Choose an operation you want to execute:										3
	1 - load data from a file;														09:28
	2 - get information about trains which go after a definite time;				b
	3 - get information about trains which go to a definite destination;			4
	4 - exit;																		09:30
	2																				g
	Enter, please, a time															5
	00:00																			07:55
	Trains, which go after 00:00 are:
	g                             5         07:55
	h                             3         09:28
	b                             4         09:30
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	3
	Enter, please, a destination
	b
	Trains, which go to b are:
	b                             4         09:30
	b                             1         00:00
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	2
	Enter, please, a time
	12:01
	There is no trains which go later than 12:01
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	4

Test case #3
	Choose an operation you want to execute:										in2.txt
	1 - load data from a file;														Riga
	2 - get information about trains which go after a definite time;				87
	3 - get information about trains which go to a definite destination;			20:38
	4 - exit;																		Warszawa
	1																				127
	Enter, please, a name of a file you want to read data from						15:23
	in2.txt																			Kyiv
	Choose an operation you want to execute:										94
	1 - load data from a file;														14:13
	2 - get information about trains which go after a definite time;				Berlin
	3 - get information about trains which go to a definite destination;			13
	4 - exit;																		11:55
	3																				Vilnius
	Enter, please, a destination													805
	Vilnius																			12:30
	Trains, which go to Vilnius are:												Kyiv
	Vilnius                       29        06:23									86
	Vilnius                       805       12:30									22:40
	Choose an operation you want to execute:										Kyiv
	1 - load data from a file;														31
	2 - get information about trains which go after a definite time;				10:10
	3 - get information about trains which go to a definite destination;			Vilnius
	4 - exit;																		29
	2																				06:23
	Enter, please, a time
	00:00
	Trains, which go after 00:00 are:
	Vilnius                       29        06:23
	Kyiv                          31        10:10
	Berlin                        13        11:55
	Vilnius                       805       12:30
	Kyiv                          94        14:13
	Warszawa                      127       15:23
	Riga                          87        20:38
	Kyiv                          86        22:40
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	3
	Enter, please, a destination
	Kyiv
	Trains, which go to Kyiv are:
	Kyiv                          31        10:10
	Kyiv                          86        22:40
	Kyiv                          94        14:13
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	3
	Enter, please, a destination
	Moskva
	There is no trains which go to Moskva
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	2
	Enter, please, a time
	22:00
	Trains, which go after 22:00 are:
	Kyiv                          86        22:40
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	4

Test case №4
	Choose an operation you want to execute:										in3.txt
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	1
	Enter, please, a name of a file you want to read data from
	in3.txt
	The file is not found
	Choose an operation you want to execute:
	1 - load data from a file;
	2 - get information about trains which go after a definite time;
	3 - get information about trains which go to a definite destination;
	4 - exit;
	4
*/

#include"commands.h"

int main() {
	menu();

	system("pause");

	return 0;
}