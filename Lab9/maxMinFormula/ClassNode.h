#pragma once

template <class T> class ClassNode {
public:
	T el;
	ClassNode* p = nullptr;
	ClassNode(T value = 0) :el(value) {}
};