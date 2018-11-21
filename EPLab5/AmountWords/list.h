#pragma once

template <typename T> struct node {
	T element;
	int times = 1;
	node<T> *next;
};

template <typename T> class list {
private:
	node<T> root;
	node<T> *lastIt;
public:
	list(T value) {
		root.element = value;
		root.next = NULL;
		lastIt = &root;
	}
	void push(T value) {
		node<T> *lastNode = new node<T>;
		lastIt->next = lastNode;
		lastNode->element = value;
		lastNode->next = NULL;
		lastIt = lastNode;
	}
	node<T>* getRoot() {
		return &root;
	}
};
