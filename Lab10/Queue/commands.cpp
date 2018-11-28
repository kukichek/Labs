#include<iostream>
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

bool pushToStack(std::ifstream &fin, Queue<int> &X) {
	int n;
	fin >> n;
	if (n >= 0) {
		int temp;
		for (int i = 0; i < n; ++i) {
			fin >> temp;
			X.push(temp);
		}
		return 1;
	}
	else {
		std::cout << "Uncorrect data\n";
		return 0;
	}
}

void readData(std::ifstream &fin) {
	Queue<int> X, Y;
	if (!pushToStack(fin, X)) {
		return;
	}
	if (!pushToStack(fin, Y)) {
		return;
	}
	std::ofstream fout("output.txt");
	if (X.isEmpty() || Y.isEmpty()) {
		fout << "One of queues will be empty in 0 steps\n";
	} else {
		fout << "One of queues will be empty in " << countSteps(X, Y) << " steps\n";
	}
}