#include<iostream>
#include"gcd.h"

int gcd(int a, int b) {
	if (a < b) {
		std::swap(a, b);
	}
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}