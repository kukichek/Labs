#include"ComplexNum.h"

ComplexNum::ComplexNum() {
	Re = 0;
	Im = 0;
}
ComplexNum::ComplexNum(double a, double b) {
	Re = a;
	Im = b;
}
ComplexNum ComplexNum::operator +(ComplexNum &b) {
	ComplexNum sum;
	sum.Re = Re + b.Re;
	sum.Im = Im + b.Im;
	return sum;
}
ComplexNum ComplexNum::operator -(ComplexNum &b) {
	ComplexNum dif;
	dif.Re = Re - b.Re;
	dif.Im = Im - b.Im;
	return dif;
}
ComplexNum ComplexNum::operator *(ComplexNum &b) {
	ComplexNum product;
	product.Re = Re * b.Re - Im * b.Im;
	product.Im = Re * b.Im + Im * b.Re;
	return product;
}
ComplexNum ComplexNum::operator /(ComplexNum &b) {
	ComplexNum quot;
	quot.Re = (Re * b.Re + Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	quot.Im = (b.Re * Im - Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);
	return quot;
}
bool ComplexNum::operator ==(ComplexNum &b) {
	return (Re * Re + Im * Im) == (b.Re * b.Re + b.Im * b.Im);
}
bool ComplexNum::operator >(ComplexNum &b) {
	return (Re * Re + Im * Im) > (b.Re * b.Re + b.Im * b.Im);
}
bool ComplexNum::operator <(ComplexNum &b) {
	return (Re * Re + Im * Im) < (b.Re * b.Re + b.Im * b.Im);
}
bool ComplexNum::operator >=(ComplexNum &b) {
	return (Re * Re + Im * Im) >= (b.Re * b.Re + b.Im * b.Im);
}
bool ComplexNum::operator <=(ComplexNum &b) {
	return (Re * Re + Im * Im) <= (b.Re * b.Re + b.Im * b.Im);
}
double ComplexNum::getRe() {
	return Re;
}
double ComplexNum::getIm() {
	return Im;
}
void ComplexNum::setRe(double value) {
	Re = value;
}
void ComplexNum::setIm(double value) {
	Im = value;
}