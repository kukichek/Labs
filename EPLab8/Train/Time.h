#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Time {
private:
	int h, m;
	void check();
public:
	Time(int hour = 0, int minute = 0);
	friend ifstream& operator >> (ifstream& in, Time &currentDate);
	friend ostream& operator << (ostream& out, Time currentDate);
	bool operator < (Time b);
	bool operator != (Time b);
	friend istream& operator >> (istream& in, Time &currentDate);
};