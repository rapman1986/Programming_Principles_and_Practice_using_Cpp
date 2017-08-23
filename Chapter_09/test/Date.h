#pragma once

class Date
{
public:
	Date(int, int, int);				// constrcut Date and check for valid
	void add_day(int);					// increase the Date by n days
	int month() { return m; }			// return month
	int day() { return d; }				// return day
	int year() { return y; }			// return year
private:
	int y, m, d;						// year, month, day
	bool is_valid();					// return true if date is valid
};
