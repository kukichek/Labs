#pragma once
#include"ClassNode.h"

template <class T> class Stack {
private:
	ClassNode<T>* top = nullptr; // top.el - element; top.p - pointer
public:
	void push(T value) {
		ClassNode<T> *newNode = new ClassNode<T>(value);
		newNode->p = top;
		top = newNode;
	}
	T pop() {
		if (!isEmpty()) {
			ClassNode<T> *temp = top;
			T element = temp->el;
			top = top->p;
			delete temp;
			return element;
		}
	}
	bool isEmpty() {
		return top == nullptr;
	}
	~Stack() {
		while (!isEmpty()) {
			this->pop();
		}
		delete top;
	}
};