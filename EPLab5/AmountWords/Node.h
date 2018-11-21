#pragma once

template <typename T> struct Node {
	T element;
	int times = 1;
	Node<T> *next;
};