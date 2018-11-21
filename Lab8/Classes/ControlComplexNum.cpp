#include<iostream>
#include"ControlComplexNum.h"
#include"ComplexNum.h"

ComplexNum ControlComplexNum::in() {
	double a, b;
	cout << "Enter, please, a real and an imaginary parts of a complex number\n";
	cin >> a >> b;
	ComplexNum c(a, b);
	return c;
}
void ControlComplexNum::out(ComplexNum a) {
	cout << a.getRe() << " + " << a.getIm() << "i\n";
}
ComplexNum ControlComplexNum::sum(ComplexNum a, ComplexNum b) {
	return a + b;
}
ComplexNum ControlComplexNum::max(ComplexNum a, ComplexNum b) {
	return a > b ? a : b;
}
ComplexNum ControlComplexNum::min(ComplexNum a, ComplexNum b) {
	return b > a ? a : b;
}