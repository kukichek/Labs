#pragma once
#include"Node.h"

class Figure : public Node {
public:
	short int f;
	Figure(short int value = -1);
	void execute(Stack<int> &result);
};