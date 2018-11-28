#pragma once
#include<iostream>

class Rational {
private:
	int a, b; // a Ц числитель, b Ц знаменатель
	void reduce();
public:
	Rational(int num = 0, int den = 1) : a(num), b(den) {}
	void add(Rational fIt, Rational sIt);
	void mult(Rational fIt, Rational sIt);
	void div(Rational fIt, Rational sIt);
	bool isEqual(Rational num);
	bool isGreater(Rational num);
	bool isLess(Rational num);
	void print(std::ostream &cout);
};