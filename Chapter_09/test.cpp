#include "Chrono.h"
using namespace Chrono;

int main()
{
	try 
	{
		Date today{ 1978, Month(6), 25 };
		cout << today << endl;
		Date tomorrow = today;
		tomorrow.add_day(7);
		cout << tomorrow << endl;
	}
	catch(Date::Invalid e)
	{
		cerr << "wrong date\n";
	}
	return 0;
}