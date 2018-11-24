#pragma once
#include<fstream>
#include"Stack.h"
#include"Node.h"

class CalcExpression {
private:
	Stack<Node*> elementSequence;
	Stack<int> result;
public:
	void addToSequence(char c, std::ifstream &fin);
	int findResult();
};