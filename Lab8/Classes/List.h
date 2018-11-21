#pragma once
#include<iostream>
#include"ControlComplexNum.h"
#include"Node.h"

template <class T> class List {
private:
	Node<T>* top;
public:
	List() {
		top = NULL;
	}
	List(T value) {
		Node<T> *newNode = new Node<T>(value);
		top = newNode;
	}
	bool isEmpty() {
		return top == NULL;
	}
	void push(T value) {
		Node<T> *newNode = new Node<T>(value);

		if (isEmpty()) {
			top = newNode;
		}
		else {
			Node<T> **curNode = &top;
			while ((*curNode)->getPointer() != NULL) {
				Node<T> *tempNode = (*curNode)->getPointer();
				curNode = &tempNode;
			}
			(*curNode)->setPointer(newNode);
		}
	}
	void pop() {
		if (!isEmpty()) {
			Node<T> **curNode = &top;
			if ((*curNode)->getPointer() != NULL) {
				Node<T> *nextNode = (*curNode)->getPointer();
				while (nextNode->getPointer() != NULL) {
					Node<T> *tempNode = (*curNode)->getPointer();
					curNode = &tempNode;
					nextNode = nextNode->getPointer();
				}
				delete nextNode;
				(*curNode)->setPointer(NULL);
			}
			else {
				top = NULL;
			}
		}
	}
	void out() {
		Node<T> *curNode = top;
		ControlComplexNum controller;
		while (curNode != NULL) {
			controller.out(curNode->getElement());
			curNode = curNode->getPointer();
		}
	}
	~List() {
		while (!isEmpty()) {
			pop();
		}
	}
};