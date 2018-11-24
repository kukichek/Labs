#include"Figure.h"
#include"Stack.h"

Figure::Figure(short int value) : f(value) {}

void Figure::execute(Stack<int> &result) {
	result.push(f);
}