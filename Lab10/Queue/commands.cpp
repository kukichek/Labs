#include"commands.h"

int countSteps(Queue<int> &X, Queue<int> &Y, int stepNum) {
	int x = X.pop();
	int y = Y.pop();
	if (x < y) {
		X.push(x + y);
	}
	else {
		Y.push(x - y);
	}
	if (X.isEmpty() || Y.isEmpty()) {
		return stepNum;
	}
	else {
		return countSteps(X, Y, stepNum + 1);
	}
}

bool isCor(int n) {
	return n >= 0;
}

void readData(std::ifstream &fin) {
	int n1, n2;
	Queue<int> X, Y;
	fin >> n1;
	if (isCor(n1)) {
		int temp;
		for (int i = 0; i < n1; ++i) {
			fin >> temp;
			X.push(temp);
		}
	}
	fin >> n2;
	if (isCor(n2)) {
		int temp;
		for (int i = 0; i < n2; ++i) {
			fin >> temp;
			Y.push(temp);
		}
	}
	std::ofstream fout("output.txt");
	fout << "One of queues will be empty in " << countSteps(X, Y) << " steps\n";
}