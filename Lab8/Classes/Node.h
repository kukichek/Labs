#pragma once

template <class T> class Node {
private:
	T element;
	Node<T> *pointer = NULL;
public:
	Node() {
		element = 0;
	}
	Node(T value) {
		element = value;
	}
	T getElement() {
		return element;
	}
	Node<T>* getPointer() {
		return pointer;
	}
	void setElement(T value) {
		element = value;
	}
	void setPointer(Node<T>* value) {
		pointer = value;
	}
};