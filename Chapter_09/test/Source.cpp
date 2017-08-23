#include "std_lib_facilities.h"
#include "Date.h"
#include "Month.h"
#include "Date.h"

int main()
{
	Month m = Month::feb;
	Month m2 = Month(3);
	
	for (int i = 0; i < 15; i++, ++m)
		cout << int(m) << " ";
	cout << endl;

	return 0;
}