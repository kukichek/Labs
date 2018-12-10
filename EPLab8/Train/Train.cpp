#include<iomanip>
#include"Train.h"

string Train::getDestination() {
	return destination;
}

int Train::getTrainNum() {
	return trainNum;
}

Time Train::getDepartureTime() {
	return departureTime;
}

ifstream& operator >> (ifstream& in, Train &currentTrain) {
	//getline(in, currentTrain.destination);
	in >> currentTrain.destination;
	in >> currentTrain.trainNum;
	in >> currentTrain.departureTime;
	return in;
}

ostream& operator << (ostream& out, Train currentTrain) {
	out.fill(' ');
	out.setf(ios::left);
	out << setw(30) << currentTrain.destination;
	out << setw(10) << currentTrain.trainNum;
	out << currentTrain.departureTime;
	return out;
}