#include "Date.h"

Date::Date(int yy, int mm, int dd)
	:y(yy), m(mm), d(dd)				// initialize data members
{
	//if (!is_valid()) throw Invalid{};	// check for validality
}