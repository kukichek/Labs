#pragma once
#include"commands.h"

class TrainDestinationInfo {
private:
	Vector<Train> trainList;
	string userDestination;
	int binarySearchDown(string cur);
public:
	TrainDestinationInfo(Vector<Train> enteredTrainList);
	void setUserDestination();
	void getDestinationInfo();
};