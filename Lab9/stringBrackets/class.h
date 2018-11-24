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

template <class T> class node {
private:
	T element;
	node<T> *pointer = NULL;
public:
	node() {
		element = 0;
	}
	node(T value) {
		element = value;
	}
	T getElement() {
		return element;
	}
	node<T>* getPointer() {
		return pointer;
	}
	void setElement(T value) {
		element = value;
	}
	void setPointer(node<T>* value) {
		pointer = value;
	}
};

template <class T> class Stack {
private:
	node<T>* top;
public:
	Stack() {
		top = NULL;
	}
	Stack(T value) {
		node<T> *newNode = new node<T>(value);
		top = newNode;
	}
	void push(T value) {
		node<T> *newNode = new node<T>(value);
		newNode->setPointer(top);
		top = newNode;
	}
	void pop() {
		if (top != NULL) {
			top = top->getPointer();
		}
	}
	bool isEmpty() {
		return top == NULL;
	}
	T getLast() {
		if (top != NULL) {
			return top->getElement();
		} else {
			return NULL;
		}
	}
};

template <class T> class list {
private:
	node<T>* top;
public:
	list() {
		top = NULL;
	}
	list(T value) {
		node<T> *newNode = new node<T>(value);
		top = newNode;
	}
	bool isEmpty() {
		return top == NULL;
	}
	void push(T value) {
		node<T> *newNode = new node<T>(value);

		if (isEmpty()) {
			top = newNode;
		}
		else {
			node<T> **curNode = &top;
			while ((*curNode)->getPointer() != NULL) {
				node<T> *tempNode = (*curNode)->getPointer();
				curNode = &tempNode;
			}
			(*curNode)->setPointer(newNode);
		}
	}
	void pop() {
		if (!isEmpty()) {
			node<T> **curNode = &top;
			if ((*curNode)->getPointer() != NULL) {
				node<T> *nextNode = (*curNode)->getPointer();
				while (nextNode->getPointer() != NULL) {
					node<T> *tempNode = (*curNode)->getPointer();
					curNode = &tempNode;
					nextNode = nextNode->getPointer();
				}
				(*curNode)->setPointer(NULL);
			}
			else {
				top = NULL;
			}
		}
	}
};