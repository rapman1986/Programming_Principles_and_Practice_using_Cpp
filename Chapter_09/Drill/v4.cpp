#include "std_lib_facilities.h"

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};		// Month

class Year
{
	static const int min = 1800;
	static const int max = 2200;

public:
	class Invalid{};
	Year(int x) : y{ x } { if (x<min || x> max) throw Invalid{}; }
	int year() { return y; };

private:
	int y;
};

class Date
{
public:
	Date(Year& y, Month m, int d);
	void add_day(int n);
	Month month() { return m; }
	int day() { return d; }
	int year() { return y.year(); }

private:
	Year y;
	Month m;
	int d;
};


Date::Date(Year& y, Month m, int d)
	: y{ y }, m{ m }, d{ d }
{
	switch (int(m))
	{
	case 2: case 4: case 6: case 9: case 11:
		if (d < 1 || d > 30) error("wrong day");
		break;
	default:
		if (d < 1 || d > 31) error("wrong day");
		break;
	}
}

void Date::add_day(int n)
{
	int new_day = Date::d + n;

	switch (int(Date::m))
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
		<< ',' << int(dd.month())
		<< ',' << dd.day()
		<< ')' << endl;
}
int main()
{
	Date today{ Year{1978}, Month::jun, 25 };
	cout << today;
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << tomorrow;

	return 0;
}