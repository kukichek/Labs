/*
ƒан двумерный массив ненулевых целых чисел (n x m). 
ќпределить, сколько раз элементы массива мен€ют знак 
(принима€, что массив просматриваетс€ построчно сверху вниз, а в каждой строке Ц слева направо).

√амезо ¬алери€, 1 курс, информатика

Test case є1
	-4	5				Uncorrect data

Test case є2
	0	5				Uncorrect data

Test case є3
	1	1				An amount of times elements change their signs is 0
	1

Test case є4
	3 3					An amount of times elements change their signs is 5
	1 -2 5
	6 7 -8
	5 11 -5

Test case є5
	3 3					An amount of times elements change their signs is 4
	1 2 5
	-6 7 8
	-5 11 5

Test case є6
	3 3					An amount of times elements change their signs is 0
	-1 -1 -1
	-1 -1 -1
	-1 -1 -1
*/

#include<fstream>
#include"array.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int n, m;

bool isCorrect(int a, int b) {
	return (a > 0) && (b > 0);
}

void error() {
	fout << "Uncorrect data\n";
	return;
}

bool isDifSigns(int a, int b) {
	return (a * 1. / b) < 0;
}

int counter(int** a) { // счетчик различных элементов
	int k = 0;
	for (int i = 0; i < n * m - 1; ++i) {
		k += isDifSigns(*(*(a + i / m) + i % m), *(*(a + (i + 1) / m) + (i + 1) % m));
	}
	return k;
}

void out(int** a) { // вывод ответа, содержащего кол-во смены знаков
	fout << "An amount of times elements change their signs is " << counter(a) << endl;
	return;
}

int main() {
	fin >> n >> m;
	if (isCorrect(n, m)) {
		int** a = createTwoDimensionalArray(n, m);
		inTwoDimensionalArray(a, n, m, fin);
		out(a);
		deleteTwoDimensionalArray(a, n);
	}
	else {
		error();
	}

	system("pause");

	return 0;
}