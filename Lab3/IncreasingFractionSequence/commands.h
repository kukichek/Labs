#include<vector>
#pragma once

using namespace std;

int NaturalIn() { /// ввод натурального! n
	unsigned int n;
	cout << "Enter, please, number n that belongs to a quantity of natural numbers\n";
	cin >> n;
	return n;
}

void outF(vector <int> numenator, vector <int> denominator) {
	for (int i = 0; i < numenator.size(); i++) {
		cout << numenator[i] << "/" << denominator[i] << endl;
	}
	return;
}

void iterationFareySequence(vector <int> &numenator, vector <int> &denominator, int n) { // генерирование дробей
	int it = 0; // текущая позиция в векторе
	while (it + 1 < numenator.size()) {
		if (denominator[it] + denominator[it + 1] <= n) {
			it++;
			numenator.insert(numenator.begin() + it, numenator[it] + numenator[it - 1]);
			denominator.insert(denominator.begin() + it, denominator[it] + denominator[it - 1]);
		}
		it++;
	}
	return;
}