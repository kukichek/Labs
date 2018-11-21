#pragma once
#include<iostream>
using namespace std;

class complexNum {
private:
	double Re;
	double Im;
public:
	complexNum() {
		Re = 0;
		Im = 0;
	}
	complexNum(double a, double b) {
		Re = a;
		Im = b;
	}
	complexNum operator +(complexNum &b) {
		complexNum sum;
		sum.Re = Re + b.Re;
		sum.Im = Im + b.Im;
		return sum;
	}
	complexNum operator -(complexNum &b) {
		complexNum dif;
		dif.Re = Re - b.Re;
		dif.Im = Im - b.Im;
		return dif;
	}
	complexNum operator *(complexNum &b) {
		complexNum product;
		product.Re = Re * b.Re - Im * b.Im;
		product.Im = Re * b.Im + Im * b.Re;
		return product;
	}
	complexNum operator /(complexNum &b) {
		complexNum quot;
		quot.Re = (Re * b.Re + Im * b.Im) / (b.Re * b.Re + b.Im * b.Im);
		quot.Im = (b.Re * Im - Re * b.Im) / (b.Re * b.Re + b.Im * b.Im);
		return quot;
	}
	bool operator ==(complexNum &b) {
		return (Re * Re + Im * Im) == (b.Re * b.Re + b.Im * b.Im);
	}
	bool operator >(complexNum &b) {
		return (Re * Re + Im * Im) > (b.Re * b.Re + b.Im * b.Im);
	}
	bool operator <(complexNum &b) {
		return (Re * Re + Im * Im) < (b.Re * b.Re + b.Im * b.Im);
	}
	bool operator >=(complexNum &b) {
		return (Re * Re + Im * Im) >= (b.Re * b.Re + b.Im * b.Im);
	}
	bool operator <=(complexNum &b) {
		return (Re * Re + Im * Im) <= (b.Re * b.Re + b.Im * b.Im);
	}
	double getRe() {
		return Re;
	}
	double getIm() {
		return Im;
	}
	void setRe(double value) {
		Re = value;
	}
	void setIm(double value) {
		Im = value;
	}
};

class controlComplexNum {
public:
	complexNum in() {
		double a, b;
		cout << "Enter, please, a real and an imaginary parts of a complex number\n";
		cin >> a >> b;
		complexNum c(a, b);
		return c;
	}
	void out(complexNum a) {
		cout << a.getRe() << " + " << a.getIm() << "i\n";
	}
	complexNum sum(complexNum a, complexNum b) {
		return a + b;
	}
	complexNum max(complexNum a, complexNum b) {
		return a > b ? a : b;
	}
	complexNum min(complexNum a, complexNum b) {
		return b > a ? a : b;
	}
};

template <class T> class classNode {
public:
	T el;
	classNode* p = NULL;
	classNode(T value = NULL) :el(value) {}
};

template <class T> class stack {
private:
	classNode<T>* top = NULL; // top.el - element; top.p - pointer
public:
	void push(T value) {
		classNode<T> *newNode = new classNode<T>(value);
		newNode->p = top;
		top = newNode;
	}
	T pop() {
		if (!isEmpty()) {
			classNode<T> *temp = top;
			T element = temp->el;
			top = top->p;
			delete temp;
			return element;
		}
	}
	bool isEmpty() {
		return top == NULL;
	}
	~stack() {
		while (!isEmpty()) {
			this->pop();
		}
		delete top;
	}
};

template <class T> class list {
private:
	classNode<T>* top = NULL; // top.el - element; top.p - pointer
public:
	void push(T value) {
		classNode<T> *newNode = new classNode<T>(value);

		if (isEmpty()) {
			top = newNode;
		}
		else {
			classNode<T> **curNode = &top;
			while ((*curNode)->p != NULL) {
				curNode = &((*curNode)->p);
			}
			(*curNode)->p = newNode;
		}
	}
	T pop() {
		if (!isEmpty()) {
			T element;
			classNode<T> **curNode = &top;
			if ((*curNode)->p != NULL) {
				classNode<T> *nextNode = (*curNode)->p;
				while (nextNode->p != NULL) {
					curNode = &((*curNode)->p);
					nextNode = nextNode->p;
				}
				element = (*nextNode)->el;
				(*curNode)->p = NULL;
				delete nextNode;
			}
			else {
				element = top->el;
				top = NULL;
			}
			return element;
		}
	}
	bool isEmpty() {
		return top == NULL;
	}
	~list() {
		while (!isEmpty()) {
			this->pop();
		}
		delete top;
	}
};