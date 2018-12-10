#pragma once
#include"Vector.h"
#include"Train.h"
#include"Time.h"

class TrainTimeInfo {
private:
	Vector<Train> trainList;
	Time userTime;
	int binarySearchUp(Time cur);
public:
	TrainTimeInfo(Vector<Train> enteredTrainList);
	void setUserTime();
	void getTimeInfo();
};