#include<fstream>
#include"CalcExpression.h"
#include"Stack.h"
#include"Node.h"
#include"Figure.h"
#include"Operation.h"

void CalcExpression::addToSequence(char c, std::ifstream &fin) {
	do {
		if (c == 'm') {
			fin >> c;
			Operation *temp = new Operation;
			if (c == 'a') {
				temp->operationIndex = 1;
			}
			else {
				temp->operationIndex = 0;
			}
			elementSequence.push(temp);
		}
		else {
			if (c >= '0' && c <= '9') {
				Figure *temp = new Figure;
				temp->f = c - '0';
				elementSequence.push(temp);
			}
		}
	} while (fin >> c);
	return;
}

int CalcExpression::findResult() {
	while (!elementSequence.isEmpty()) {
		Node *temp = elementSequence.pop();
		temp->execute(result);
	}
	int res = result.pop();
	return res;
}