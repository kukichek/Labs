#pragma once
#include"Node.h"

template <typename T> class List {
private:
	Node<T> root;
	Node<T> *lastIt;
public:
	List(T value) {
		root.element = value;
		root.next = NULL;
		lastIt = &root;
	}
	void push(T value) {
		Node<T> *lastNode = new Node<T>;
		lastIt->next = lastNode;
		lastNode->element = value;
		lastNode->next = NULL;
		lastIt = lastNode;
	}
	Node<T>* getRoot() {
		return &root;
	}
};