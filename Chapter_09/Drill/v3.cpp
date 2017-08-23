#include "std_lib_facilities.h"

class Date
{
	int y, m, d;

public:
	Date(int y, int m, int d);
	void add_day(int n);
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};


Date::Date(int y, int m, int d)
{
	if (y < 1900 || y > 2200)  error("wrong year");
	if (m < 1 || m > 12) error("wrong month");

	switch (m)
	{
	case 2: case 4: case 6: case 9: case 11:
		if (d < 1 || d > 30) error("wrong day");
		break;
	default:
		if (d < 1 || d > 31) error("wrong day");
		break;
	}

	Date::y = y;
	Date::m = m;
	Date::d = d;
}

void Date::add_day(int n)
{
	int new_day = Date::d + n;

	switch (Date::m)
	{
	case 2: case 4: case 6: case 9: case 11:
		if (new_day > 30) Date::d = new_day - 30;
		else Date::d = new_day;
		break;
	default:
		if (new_day > 31) Date::d = new_day - 31;
		else Date::d = new_day;
		break;
	}
}

ostream& operator<<(ostream& os, Date& dd)
{
	return os << '(' << dd.year()
		<< ',' << dd.month()
		<< ',' << dd.day()
		<< ')' << endl;
}
int main()
{
	Date today{ 1978, 6, 25 };
	cout << today;
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow;

	return 0;
}