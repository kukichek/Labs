#include<iostream>
#include"Rational.h"
#include"gcd.h"

void Rational::reduce() {
	int div = gcd(a, b);
	a /= div;
	b /= div;
}

void Rational::add(Rational fIt, Rational sIt) {
	a = fIt.a * sIt.b + fIt.b * sIt.a;
	b = fIt.b * sIt.b;
	reduce();
}

void Rational::mult(Rational fIt, Rational sIt) {
	a = fIt.a * sIt.a;
	b = fIt.b * sIt.b;
	reduce();
}

void Rational::div(Rational fIt, Rational sIt) {
	a = fIt.a * sIt.b;
	b = fIt.b * sIt.a;
	if (b == 0) {
		std::cout << "Error, division by zero\n";
	} else {
		reduce();
	}
	
}

bool Rational::isEqual(Rational num) {
	return a * num.b == b * num.a;
}
bool Rational::isGreater(Rational num) {
	return a * num.b > b * num.a;
}

bool Rational::isLess(Rational num) {
	return a * num.b < b * num.a;
}

void Rational::print(std::ostream &cout) {
	if (b == 0) {
		cout << "Error, division by zero\n";
		return;
	}
	if (b == 1) {
		cout << a;
	} else {
		cout << a << '/' << b;
	}
}