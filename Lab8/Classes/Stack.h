#pragma once
#include<iostream>
#include"ControlComplexNum.h"
#include"Node.h"

template <class T> class Stack {
private:
	Node<T>* top;
public:
	Stack() {
		top = NULL;
	}
	Stack(T value) {
		Node<T> *newNode = new Node<T>(value);
		top = newNode;
	}
	void push(T value) {
		Node<T> *newNode = new Node<T>(value);
		newNode->setPointer(top);
		top = newNode;
	}
	void pop() {
		if (top != NULL) {
			Node<T>* el = top;
			top = top->getPointer();
			delete el;
		}
	}
	void out() {
		Node<T> *curNode = top;
		ControlComplexNum controller;
		while (curNode != NULL) {
			controller.out(curNode->getElement());
			curNode = curNode->getPointer();
		}
		cout << endl;
	}
	~Stack() {
		while (top != NULL) {
			pop();
		}
	}
};