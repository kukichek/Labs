/*
Двумерная матрица задает высоты соответствующих клеток местности. Переход возможен в соседние клетки 
по горизонтали или вертикали, если высота соседа меньше (как стекает вода).

1. Определить все клетки, в которые можно попасть из заданной;
2. Определить самую удаленную клетку, в котороую можно попасть из заданной;
3. Найти путь для подзадачи 2.

Зам.
1) Используйте поиск в ширину для решения задачи;
2) Для тестирования подготовить достаточно большие матрицы;
При выводе показывать матрицу исходную и матрицу с результирующим путем
(выделяя его, например, каким-то символом).

Гамезо Валерия, 1 курс, информатика

Test case №1
	2 1 3 2									From given point (3,3) you can get to positions:
	1 0 1 0									(3,2)
	3 1 2 1									(4,3)
	2 0 1 2									(3,4)
											(2,3)
	(3,3)									(4,2)
											(2,2)
											(2,4)
											The furthest point is (2,4)
											The path to the furthest point is:
											2 1 3 2
											1 0 1 0
											3 1 # 1
											2 # # 2

Test case №2
	2 1 3 2									From given point (1,1) you can get to positions:
	1 0 1 0									(2,1)
	3 1 2 1									(1,2)
	2 0 1 2									(2,2)
											The furthest point is (2,2)
	(1,1)									The path to the furthest point is:
											# # 3 2
											1 # 1 0
											3 1 2 1
											2 0 1 2

Test case №3
	2 1 3 2									From given point (3,1) you can get to positions:
	1 0 1 0									(4,1)
	3 1 2 1									(3,2)
	2 0 1 2									(2,1)
											(4,2)
	(3,1)									(2,2)
											The furthest point is (2,2)
											The path to the furthest point is:
											2 1 # 2
											1 # # 0
											3 1 2 1
											2 0 1 2

Test case №4
	2 1 3 2									From given point (2,2) you can get to positions:
	1 0 1 0									NULL
	3 1 2 1
	2 0 1 2	

	(2,2)

Test case №5
	2 1 3 2									Uncorrect coordinates
	1 0 1 0									
	3 1 2 1
	2 0 1 2	

	(0,0)

*/

#include<iostream>
#include<fstream>
#include"TwoDimensionalArray.h"

using namespace std;

int n, m;

bool isCorrectPos(int x, int y) { // проверка, выходит ли точка за пределы массива
	if ((x >= 0) && (x < m)) {
		if ((y >= 0) && (y < n)) {
			return 1;
		}
	}
	return 0;
}

void addingPosToQueue(char **field, bool **isBeen, int *queue, int *dist, int *from, int curX, int curY, int x, int y, int curPosInQueue, int &lastPosInQueue) {
	// реализация поиска в ширину при помощи массива queue
	if (isCorrectPos(x, y)) {
		if (!isBeen[y][x] && (field[curY][curX] > field[y][x])) {
			cout << '(' << x + 1 << ',' << y + 1 << ")\n";
			isBeen[y][x] = 1;
			queue[lastPosInQueue] = (y) * m + x;
			dist[lastPosInQueue] = dist[curPosInQueue] + 1;
			from[lastPosInQueue] = curPosInQueue;
			lastPosInQueue++;
		}
	}
	return;
}

void outOfPoints(char **field, int *queue, int *from, int &lastPosInQueue) {
	// вывод точек и путя
	if (lastPosInQueue != 1) {
		lastPosInQueue--;
		cout << "The furthest point is (" << queue[lastPosInQueue] % m + 1 << ',' << queue[lastPosInQueue] / m + 1 << ")\n";
		cout << "The path to the furthest point is:\n";
		
		while (lastPosInQueue >= 0) {
			field[queue[lastPosInQueue] / m][queue[lastPosInQueue] % m] = '#';
			lastPosInQueue = from[lastPosInQueue];
		}
		matrixOut(field, n, m);
	}
	else {
		cout << "NULL\n";
	}
	return;
}

int main() {
	ifstream fin("input.txt");
	fin >> n >> m;

	if ((n > 0) && (m > 0)) {
		char **field = new char*[n]; // поле с заданными высотами
		createMatrix(field, m);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				fin >> field[i][j];
			}
		}

		matrixOut(field, n, m);

		bool **isBeen = new bool*[n]; // матрица, в которой хранится, были ли мы в этой точке
		createMatrix(isBeen, m);
		matrixNull(isBeen, n, m);

		int *queue = new int[n * m]; // массив, имитирующий очередь, где curPosInQueue - начало очереди, а lastPosInQueue - ее конец
		int *dist = new int[n * m]; // кратчайшее расстояние от заданной точки
		int *from = new int[n * m]; // откуда мы пришли в эту точку

		int x0, y0;
		cout << "Enter, please, coordinates x, y of a starting position\n";
		cin >> x0 >> y0;
		x0--;
		y0--;

		if (isCorrectPos(x0, y0)) {
			int curPosInQueue = 0;
			int lastPosInQueue = 1;

			queue[curPosInQueue] = y0 * m + x0;
			dist[curPosInQueue] = 0;
			from[curPosInQueue] = -1;

			cout << "From given point (" << x0 + 1 << ',' << y0 + 1 << ") you can get to positions:\n";

			while (curPosInQueue < lastPosInQueue) {
				int x = queue[curPosInQueue] % m;
				int y = queue[curPosInQueue] / m;

				addingPosToQueue(field, isBeen, queue, dist, from, x, y, x, y - 1, curPosInQueue, lastPosInQueue);
				addingPosToQueue(field, isBeen, queue, dist, from, x, y, x + 1, y, curPosInQueue, lastPosInQueue);
				addingPosToQueue(field, isBeen, queue, dist, from, x, y, x, y + 1, curPosInQueue, lastPosInQueue);
				addingPosToQueue(field, isBeen, queue, dist, from, x, y, x - 1, y, curPosInQueue, lastPosInQueue);

				curPosInQueue++;
			}

			outOfPoints(field, queue, from, lastPosInQueue);
		} else {
			cout << "Uncorrect coordinates\n";
		}
	} else {
		cout << "Uncorrect data\n";
	}

	system("pause");

	return 0;
}