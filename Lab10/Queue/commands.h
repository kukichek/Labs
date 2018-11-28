#pragma once
#include<fstream>
#include"Queue.h"

int countSteps(Queue<int> &X, Queue<int> &Y, int stepNum = 0);

bool pushToStack(std::ifstream &fin, Queue<int> &X);

void readData(std::ifstream &fin);