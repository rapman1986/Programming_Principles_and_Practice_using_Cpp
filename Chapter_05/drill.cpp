#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	try
	{
		vector<int> v(10);
		v(5) = 7;

		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "Ooops: unknown exception!\n";
		return 2;
	}
}