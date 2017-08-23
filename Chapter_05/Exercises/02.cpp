#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

// Converts Celsius to Kelvin
double ctok(double c)
{
	if (c < -273.15) error("temperature too low\n");	// check argument value, and throw an exception
	double k = c + 273.15;
	return k;
}

// Converts Kelvin to Celsius
double ktoc(double k)
{
	if (k < 0) error("temperature too low\n");			// check argument value, and throw an exception
	double c = k - 273.15;
	return c;
}

int main()
{
	// declare input variables
	double c = 0;
	double k = 0;
	char choose;
	
	cout << "What conversion to do?\n";
	cout << "Celsius to Kelvin press c\n";
	cout << "Kelvin to Celsius press k\n";
	cin >> choose;
	if (choose == 'c')
	{
		cout << "Enter temperature in Celsius: ";
		cin >> c;		// get temperature
		k = ctok(c);		// convert temp and store in k
		cout << k << " kelvin" << endl;		// print result
	}
	else if (choose == 'k')
	{
		cout << "Enter temperature in Kelvin: ";
		cin >> k;
		c = ktoc(k);
		cout << c << " celsius" << endl;
	}
	else
		cout << "Wrong option choosed\n";

	return 0;
}