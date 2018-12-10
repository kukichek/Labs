#pragma once
#include<algorithm>

template <class T> class Vector {
private:
	int capacity;
	int vectorSize;
	T *a;
	void relocate(int newSize) {
		capacity = newSize;
		T *current = new T[capacity]();
		for (int i = 0; i < vectorSize; ++i) {
			current[i] = a[i];
		}
		delete[] a;
		a = current;
	}
	void checkLeftSize() {
		if (4 * vectorSize < capacity) {
			relocate(capacity / 4);
		}
	}
public:
	Vector(int n = 0) {
		vectorSize = n;
		capacity = std::max(n, 1);
		a = new T[capacity]();
	}
	Vector(Vector<T> &value) {
		capacity = value.capacity;
		a = new T[capacity];
		vectorSize = value.vectorSize;
		for (int i = 0; i < vectorSize; ++i) {
			a[i] = value[i];
		}
	}
	void operator = (Vector<T> value) {
		relocate(value.capacity);
		vectorSize = value.vectorSize;
		clear();
		for (int i = 0; i < vectorSize; ++i) {
			a[i] = value[i];
		}
	}
	void push_back(T value) {
		if (vectorSize >= capacity) {
			relocate(2 * capacity);
		}
		a[vectorSize] = value;
		vectorSize++;
	}
	void pop_back() {
		if (!isEmpty()) {
			vectorSize--;
			checkLeftSize();
		}
	}
	void insert(int it, T value) {
		if (vectorSize >= capacity) {
			relocate(2 * capacity);
		}
		vectorSize++;
		for (int i = vectorSize - 1; i > it; --i) {
			a[i] = a[i - 1];
		}
		a[it] = value;
	}
	void erase(int it) {
		for (int i = it + 1; i < vectorSize; ++i) {
			a[i - 1] = a[i];
		}
		vectorSize--;
		checkLeftSize();
	}
	void clear() {
		for (int i = 0; i < vectorSize; ++i) {
			a[i] = 0;
		}
	}
	void shrink_to_fit() {
		relocate(vectorSize);
	}
	bool isEmpty() {
		return vectorSize == 0;
	}
	T& operator[] (int n) {
		if ((n >= 0) && (n < vectorSize)) {
			return a[n];
		}
	}
	int size() {
		return vectorSize;
	}
	~Vector() {
		delete[] a;
		capacity = 0;
		vectorSize = 0;
	}
};