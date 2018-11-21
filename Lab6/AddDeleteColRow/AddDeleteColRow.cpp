/*
–еализовать 4 функции. ƒобавьте меню, в котором пользователь может выбрать желаемую операцию:
a.	—оздать функцию, вставл€ющую строку в двумерный динамический массив в указанную позицию.
b.	—оздать функцию, вставл€ющую столбец в двумерный динамический массив в указанную позицию.
c.	—оздать функцию, удал€ющую заданную строку двумерного динамического массива.
d.	—оздать функцию, удал€ющую заданный столбец двумерного динамического массива.

√амезо ¬алери€, 1 курс, 1 группа
*/

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

int n, m;

int** createTwoDimensionalArray(int n, int m) {
	int **a = new int *[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	return a;
} 

void inTwoDimensionalArray(int **a, int n, int m) {
	cout << "Enter, please, elements of an array\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	return;
}

void outTwoDimensionalArray(int **a, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return;
}

int** inputByHand() {
	do {
		cout << "Enter, please, numbers n and m greater than 0\n";
		cin >> n >> m;
	} while ((n < 1) || (m < 1));

	int **a = createTwoDimensionalArray(n, m);
	inTwoDimensionalArray(a, n, m);

	return a;
}

int randomGenerationInLimits(int l, int r) {
	return rand() % (r - l + 1) + l;
}

void randomGenerationOfAnArray(int **a, int l, int r) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = randomGenerationInLimits(l, r);
		}
	}
	return;
}

void checkingOfLimits(int &l, int &r, string type) {
	do {
		cout << "Enter, please, lower and upper limits of " << type << endl;
		cin >> l >> r;
	} while ((l < 1) || (r < 1));
	if (l > r) {
		int x = l;
		l = r;
		r = x;
	}
	return;
}

int** inputRandom() {
	srand(time(NULL));
	int leftLimitOfN, rightLimitOfN;
	checkingOfLimits(leftLimitOfN, rightLimitOfN, "a number n");

	int leftLimitOfM, rightLimitOfM;
	checkingOfLimits(leftLimitOfM, rightLimitOfM, "a number m");

	n = randomGenerationInLimits(leftLimitOfN, rightLimitOfN);
	m = randomGenerationInLimits(leftLimitOfM, rightLimitOfM);

	int **a = createTwoDimensionalArray(n, m);

	int leftLimit, rightLimit;
	cout << "Enter, please, lower and upper limits of elements of an array\n";
	cin >> leftLimit >> rightLimit;
	if (leftLimit > rightLimit) {
		int x = leftLimit;
		leftLimit = rightLimit;
		rightLimit = x;
	}

	randomGenerationOfAnArray(a, leftLimit, rightLimit);

	return a;
}

int** inputFromFile() {
	string NameOfFile;
	cout << "Enter, please, a name of a file (with an expansion) you want to have data read\n";
	cin >> NameOfFile;

	ifstream fin(NameOfFile);
	fin >> n >> m;

	int **a = createTwoDimensionalArray(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fin >> a[i][j];
		}
	}

	return a;
}

int** (*inputOperats[3])() = {inputByHand, inputRandom, inputFromFile};

int chooseTheWayOfGenerationOfAnArray() {
	int indexOfAnOperation;
	do {
		cout << "Choose, please, the way of generation of an array\n";
		cout << "0 - entering by hand\n";
		cout << "1 - random inputing\n";
		cout << "2 - reading from a file\n";
		cin >> indexOfAnOperation;
	} while ((indexOfAnOperation < 0) || (indexOfAnOperation > 2));
	return indexOfAnOperation;
}

int** enteringMenu() {
	int indexOfAnOperation = chooseTheWayOfGenerationOfAnArray();
	int** a = (inputOperats[indexOfAnOperation])();

	return a;
}

void deleteArray(int **a) {
	for (int i = 0; i < n; ++i) {
		delete a[i];
	}
	return;
}

int** deleteRow(int **a) {
	int rowNumber;
	do {
		cout << "Enter, please, a number of row you want to delete\n";
		cin >> rowNumber;
	} while ((rowNumber < 1) || (rowNumber > n));
	rowNumber--;

	for (int i = rowNumber; i < n - 1; ++i) {
		swap(a[i], a[i + 1]);
	}
	n--;
	delete a[n];
	return a;
}

int** deleteCol(int **a) {
	int colNumber;
	do {
		cout << "Enter, please, a number of col you want to delete\n";
		cin >> colNumber;
	} while ((colNumber < 1) || (colNumber > m));
	colNumber--;

	int **b = createTwoDimensionalArray(n, m - 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < colNumber; ++j) {
			b[i][j] = a[i][j];
		}
		for (int j = colNumber; j < m - 1; ++j) {
			b[i][j] = a[i][j + 1];
		}
	}
	deleteArray(a);
	m--;
	return b;
}

int** insertRow(int **a) {
	int rowNumber;
	do {
		cout << "Enter, please, a number of row in which you want to insert new elements\n";
		cin >> rowNumber;
	} while ((rowNumber < 1) || (rowNumber > n + 1));
	rowNumber--;

	int *addingRow = new int[m];
	cout << "Enter, please, elements you want to insert\n";
	for (int i = 0; i < m; ++i) {
		cin >> addingRow[i];
	}

	int **b = new int*[n + 1];
	for (int i = 0; i < rowNumber; ++i) {
		b[i] = a[i];
	}
	b[rowNumber] = addingRow;
	for (int i = rowNumber; i < n; ++i) {
		b[i + 1] = a[i];
	}
	delete[] a;
	n++;
	return b;
}

int* insertElement(int *a, int colNumber, int element) {
	int *b = new int[m + 1];
	for (int i = 0; i < colNumber; ++i) {
		b[i] = a[i];
	}
	b[colNumber] = element;
	for (int i = colNumber; i < m; ++i) {
		b[i + 1] = a[i];
	}
	delete[] a;
	return b;
}

int** insertCol(int **a) {
	int colNumber;
	do {
		cout << "Enter, please, a number of row in which you want to insert new elements\n";
		cin >> colNumber;
	} while ((colNumber < 1) || (colNumber > m + 1));
	colNumber--;

	int **b = new int*[n];
	int *addingCol = new int[n];
	cout << "Enter, please, elements of a column you want to insert\n";
	for (int i = 0; i < n; ++i) {
		cin >> addingCol[i];
	}

	for (int i = 0; i < n; ++i) {
		b[i] = insertElement(a[i], colNumber, addingCol[i]);
	}
	delete[] a;
	m++;
	return b;
}

int** (*operationsWithArray[4])(int **a) = { insertRow, insertCol, deleteRow, deleteCol };

int** actionWithAnArrayMenu(int **a) {
	int indexOfAnOperation;
	do {
		cout << "Choose, please, an operation you want to do with an array\n";
		cout << "0 - insert row\n";
		cout << "1 - insert column\n";
		cout << "2 - delete row\n";
		cout << "3 - delete column\n";
		cin >> indexOfAnOperation;
	} while ((indexOfAnOperation > 3) || (indexOfAnOperation < 0));
	return (*operationsWithArray[indexOfAnOperation])(a);
}

int main() {
	int** a = enteringMenu();
	cout << "An initial array is:\n";
	outTwoDimensionalArray(a, n, m); 

	a = actionWithAnArrayMenu(a);
	outTwoDimensionalArray(a, n, m);

	system("pause");

	return 0;
}