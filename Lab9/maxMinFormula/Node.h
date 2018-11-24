#pragma once
#include"Stack.h"

class Node {
public:
	virtual void execute(Stack<int> &result) = 0;
};