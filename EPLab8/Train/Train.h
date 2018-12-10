#pragma once
#include<string>
#include"Time.h"

class Train {
protected:
	string destination;
	int trainNum;
	Time departureTime;
public:
	Train(string name = " ", int num = 0, Time time = Time(0, 0)) : destination(name), trainNum(num), departureTime(time) {}
	string getDestination();
	int getTrainNum();
	Time getDepartureTime();
	friend ifstream& operator >> (ifstream& in, Train &currentTrain);
	friend ostream& operator << (ostream& out, Train currentTrain);
};