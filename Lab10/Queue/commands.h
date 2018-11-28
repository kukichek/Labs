#pragma once
#include<fstream>
#include"Queue.h"

int countSteps(Queue<int> &X, Queue<int> &Y, int stepNum = 0);

bool isCor(int n);

void readData(std::ifstream &fin);