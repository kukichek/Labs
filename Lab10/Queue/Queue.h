#pragma once
#include"ClassNode.h"

template <class T> class Queue {
private:
	ClassNode<T> *head = nullptr;
	ClassNode<T> *tail = nullptr;
public:
	Queue() {}
	Queue(T value) {
		ClassNode<T> *newNode = new ClassNode<T>(value);
		head = newNode;
		tail = newNode;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	void push(T value) {
		if (!isEmpty()) {
			ClassNode<T> *newNode = new ClassNode<T>(value);
			tail->p = newNode;
			tail = newNode;
		}
		else {
			ClassNode<T> *newNode = new ClassNode<T>(value);
			head = newNode;
			tail = newNode;
		}
	}
	T pop() {
		if (!isEmpty()) {
			T element = head->el;
			ClassNode<T> *lastNode = head;
			head = head->p;
			delete lastNode;
			return element;
		}
	}
	~Queue() {
		while (!isEmpty()) {
			pop();
		}
	}
};