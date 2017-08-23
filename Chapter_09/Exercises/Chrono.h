#pragma once
#include "std_lib_facilities.h"

namespace Chrono
{
	enum class Month
	{
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};		// Month

	class Date
	{
	public:
		class Invalid{};				// to throw an exception

		Date(int yy, Month mm, int dd);	// check for valid date and initializer
		Date();							// default constructor

		// nonmodifying opertions
		int day() const { return d; }
		Month month() const { return m; }
		int year() const { return y; }

		// modifying operations
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

	private:
		int y;
		Month m;
		int d;
	};		// Date

	// helper functions
	bool is_date(int y, Month m, int d);		// true for valid date
	bool leapyear(int y);						//true if y is leap year

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
}		// Chrono