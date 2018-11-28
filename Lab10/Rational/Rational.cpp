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
	reduce();
}

bool Rational::isEqual(Rational num) {
	return a * num.b == b * num.a;
}
bool Rational::greater(Rational num) {
	return a * num.b > b * num.a;
}

bool Rational::less(Rational num) {
	return a * num.b < b * num.a;
}

void Rational::print(std::ostream &cout) {
	if (b == 1) {
		cout << a;
	} else {
		cout << a << '/' << b;
	}
}