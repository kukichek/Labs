#pragma once
#include<iostream>
#include"Train.h"
#include"Vector.h"

using namespace std;

bool compTime(Train a, Train b);

bool compAlpha(Train a, Train b);

void insertionSort(Vector<Train> &a, bool comp(Train a, Train b));

string getNameFile();

ifstream getStream(string nameOfFile);

void loadData(Vector<Train> &trainList, ifstream& fin);

int getOperationIndex();

void menu();