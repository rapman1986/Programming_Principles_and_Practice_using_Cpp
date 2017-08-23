#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	double num, smaller, larger;
	constexpr double DIFFERENCE = 1.0 / 100.0;

	cout << "Enter one number (to exit enter |):\t";

	if (cin >> num)
	{
		smaller = num;
		larger = num;

		do
		{
			if (num < smaller)
			{
				smaller = num;
				cout << num << " smallest so far\n";
			}
			if (num > larger)
			{
				larger = num;
				cout << num << " larger so far\n";
			}

			cout << "\nEnter one number (to exit enter |):\t";
		} while (cin >> num);
	}
}