#include<algorithm>
#include"Operation.h"
#include"Stack.h"

Operation::Operation(bool value) : operationIndex(value) {}

void Operation::execute(Stack<int> &result) {
	int a, b;
	a = result.pop();
	b = result.pop();
	if (operationIndex) {
		result.push(std::max(a, b));
	}
	else {
		result.push(std::min(a, b));
	}
};