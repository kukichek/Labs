#pragma once

using namespace std;

int inN() { // ���� �����
	int n;

	cout << "Enter, please, a size of an array\n";
	cin >> n;

	return n;
}

void inArray(int *a, int n) { // ���� �������
	cout << "Enter, please, elements of an array\n";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	return;
}

bool comp(int a, int b) {
	return a < b;
}

int findDelta(int *a, int n, int *remains) { // ���������� �������� ����������
	for (int i = 0; i < n - 1; ++i) {
		remains[i] = a[i + 1] - a[i];
	}
	int delta = remains[0];
	for (int i = 1; i < n - 1; ++i) {
		delta = gcd(delta, remains[i]);
	}
	return delta;
}

void buildAProgression(int *a, int n, int delta) { // ���������� ����������
	int k = a[0];
	int i = 0;
	while (i < n) {
		if (k == a[i]) {
			i++;
		}
		cout << k << ' ';
		k += delta;
	}
	cout << endl;
	return;
}

bool isPossibleToCreate(int firstRemain, int lastRemain) {
	if (firstRemain) {
		return 1;
	}
	return firstRemain == lastRemain ? 1 : 0;
}