#pragma once
#include"Node.h"

class Operation : public Node {
public:
	bool operationIndex; // 1 - max; 0 - min
	Operation(bool value = 0);
	void execute(Stack<int> &result);
};