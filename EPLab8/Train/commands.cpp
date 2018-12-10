#include"commands.h"
#include"TrainDestinationInfo.h"
#include"TrainTimeInfo.h"
#include"fileLib.h"

using namespace std;

bool compTime(Train a, Train b) {
	return a.getDepartureTime() < b.getDepartureTime() ? 1 : 0;
}

bool compAlpha(Train a, Train b) {
	return a.getDestination() < b.getDestination() ? 1 : 0;
}

void insertionSort(Vector<Train> &a, bool comp(Train a, Train b)) {
	for (int i = 1; i < a.size(); ++i) {
		int k = i - 1;
		while ((k >= 0) && (!comp(a[k], a[k + 1]))) {
			swap(a[k], a[k + 1]);
			--k;
		}
	}
	return;
}

string getNameFile() {
	string name;
	cout << "Enter, please, a name of a file you want to read data from\n";
	cin >> name;
	return name;
}

ifstream getStream(string nameOfFile) {
	ifstream fin(nameOfFile);
	return fin;
}

void loadData(Vector<Train> &trainList, ifstream& fin) {
	Train curTrain;
	while (fin >> curTrain) {
		trainList.push_back(curTrain);
	}
	return;
}

int getOperationIndex() {
	int operationIndex;
	cout << "Choose an operation you want to execute:\n";
	cout << "1 - load data from a file;\n";
	cout << "2 - get information about trains which go after a definite time;\n";
	cout << "3 - get information about trains which go to a definite destination;\n";
	cout << "4 - exit;\n";
	cin >> operationIndex;
	return operationIndex;
}

void menu() {
	Vector<Train> trainList;
	ifstream fin;
	string error;
	int index = getOperationIndex();
	while (index != 4) {
		switch (index) {
		case 1:
			fin = getStream(getNameFile());
			if (isValidFile(fin, error)) {
				while (!trainList.isEmpty()) {
					trainList.pop_back();
				}
				loadData(trainList, fin);
			}
			else {
				cout << error << endl;
			}
			break;
		case 2:
			if (!trainList.isEmpty()) {
				TrainTimeInfo timeInfo(trainList);
				timeInfo.setUserTime();
				timeInfo.getTimeInfo();
			}
			else {
				cout << "List of train wasn't loaded\n";
			}
			break;
		case 3:
			if (!trainList.isEmpty()) {
				TrainDestinationInfo destinationInfo(trainList);
				destinationInfo.setUserDestination();
				destinationInfo.getDestinationInfo();
			}
			else {
				cout << "List of train wasn't loaded\n";
			}
			break;
		}
		index = getOperationIndex();
	}
}