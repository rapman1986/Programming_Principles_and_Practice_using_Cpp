#include "Month.h"

Month operator++(Month & m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}
