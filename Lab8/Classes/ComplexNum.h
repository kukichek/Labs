#pragma once
#include<iostream>
using namespace std;

class ComplexNum {
private:
	double Re;
	double Im;
public:
	ComplexNum();
	ComplexNum(double a, double b);
	ComplexNum operator +(ComplexNum &b);
	ComplexNum operator -(ComplexNum &b);
	ComplexNum operator *(ComplexNum &b);
	ComplexNum operator /(ComplexNum &b);
	bool operator ==(ComplexNum &b);
	bool operator >(ComplexNum &b);
	bool operator <(ComplexNum &b);
	bool operator >=(ComplexNum &b);
	bool operator <=(ComplexNum &b);
	double getRe();
	double getIm();
	void setRe(double value);
	void setIm(double value);
};