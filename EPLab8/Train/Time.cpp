#include<iomanip>
#include"Time.h"

void Time::check() {
	int diff;
	diff = m / 60;
	m %= 60;
	if (m < 0) {
		diff--;
		m += 60;
	}
	h += diff;
	h %= 24;
	if (h < 0) {
		h += 24;
	}
	return;
}

Time::Time(int hour, int minute) : h(hour), m(minute) {
	check();
}

ifstream& operator >> (ifstream& in, Time &currentDate) {
	char separator;
	in >> currentDate.h >> separator >> currentDate.m;
	currentDate.check();
	currentDate.check();
	return in;
}

ostream& operator << (ostream& out, Time currentDate) {
	out.setf(ios::right);
	out.fill('0');
	out << setw(2) << currentDate.h;
	out << ':';
	out.fill('0');
	out << setw(2) << currentDate.m;
	cout.unsetf(ios::right);
	return out;
}

bool Time::operator < (Time b) {
	if (h != b.h) {
		return h < b.h? 1 : 0;
	}
	return m < b.m ? 1 : 0;
}

bool Time::operator != (Time b) {
	if (h == b.h) {
		return m != b.m ? 1 : 0;
	}
	return h != b.h ? 1 : 0;
}

istream& operator >> (istream& in, Time &currentDate) {
	char separator;
	in >> currentDate.h >> separator >> currentDate.m;
	currentDate.check();
	currentDate.check();
	return in;
}