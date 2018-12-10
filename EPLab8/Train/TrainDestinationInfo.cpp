#include"TrainDestinationInfo.h"

int TrainDestinationInfo::binarySearchDown(string cur) {
	int n = trainList.size();
	int l = 0;
	int r = n - 1;
	int m = (l + r) / 2;
	while (l < r) {
		if (cur <= trainList[m].getDestination()) {
			r = m;
		}
		else {
			l = m + 1;
		}
		m = (l + r) / 2;
	}
	if (l == -1) {
		return l;
	}
	return trainList[l].getDestination() == cur ? l : -1;
}

TrainDestinationInfo::TrainDestinationInfo(Vector<Train> enteredTrainList) : trainList(enteredTrainList) {
	insertionSort(trainList, compAlpha);
}

void TrainDestinationInfo::setUserDestination() {
	cout << "Enter, please, a destination\n";
	cin >> userDestination;
}
void TrainDestinationInfo::getDestinationInfo() {
	int posInList = binarySearchDown(userDestination);
	if (posInList != -1) {
		cout << "Trains, which go to ";
		cout << userDestination;
		cout << " are:\n";
		for (int i = posInList; trainList[i].getDestination() == userDestination; ++i) {
			cout << trainList[i] << endl;
		}
	}
	else {
		cout << "There is no trains which go to " << userDestination << endl;
	}
}