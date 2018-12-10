#include"TrainTimeInfo.h"
#include"commands.h"

int TrainTimeInfo::binarySearchUp(Time cur) {
	int n = trainList.size();
	int l = 0;
	int r = n - 1;
	int m = (l + r) / 2;
	while (l < r) {
		if (cur < trainList[m].getDepartureTime()) {
			r = m - 1;
		}
		else {
			l = m;
		}
		m = (l + r + 1) / 2;
	}
	if (l == 0 && (cur < trainList[l].getDepartureTime())) {
		l--;
	}
	return l + 1;
}

TrainTimeInfo::TrainTimeInfo(Vector<Train> enteredTrainList) : trainList(enteredTrainList) {
	insertionSort(trainList, compTime);
}

void TrainTimeInfo::setUserTime() {
	cout << "Enter, please, a time\n";
	cin >> userTime;
}

void TrainTimeInfo::getTimeInfo() {
	int posInList = binarySearchUp(userTime);
	if (posInList < trainList.size()) {
		cout << "Trains, which go after ";
		cout << userTime;
		cout << " are:\n";
		for (int i = posInList; i < trainList.size(); ++i) {
			cout << trainList[i] << endl;
		}
	}
	else {
		cout << "There is no trains which go later than " << userTime;
	}
}