#pragma once

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
	return;
}

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}