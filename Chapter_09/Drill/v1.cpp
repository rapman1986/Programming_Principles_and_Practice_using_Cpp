#include "std_lib_facilities.h"

struct Date
{
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
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
	
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n)
{
	int new_day = dd.d + n;

	switch (dd.m)
	{
	case 2: case 4: case 6: case 9: case 11:
		if (new_day > 30) dd.d = new_day - 30;
		else dd.d = new_day;
		break;
	default:
		if (new_day > 31) dd.d = new_day - 31;
		else dd.d = new_day;
		break;
	}
}

ostream& operator<<(ostream& os, const Date& dd)
{
	return os << '(' << dd.y
		<< ',' << dd.m
		<< ',' << dd.d
		<< ')' << endl;
}
int main()
{
	Date today;
	init_day(today, 1978, 6, 25);
	cout << today;
	Date tomorrow = today;
	add_day(tomorrow, 1);
	cout << tomorrow;

	return 0;
}