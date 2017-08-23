#pragma once
#include <ostream>

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m);
