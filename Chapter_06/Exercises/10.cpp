#include "std_lib_facilities.h"

double Permutation(double, double);
double Combination(double, double);
double Factorial(double);

int main()
{
	double a, b, value = 0;
	char option;

	while (true)
	{
		cout << "Enter option to compute: P for permuatation; C for combinations; something else to quit: ";
		cin >> option;

		switch (option)
		{
		case 'p': case 'P':
		{
			cout << "Enter two numbers:\n";
			cout << "First for number of entity, second number for number of used entity\n";
			cin >> a >> b;

			// Check for errors
			if (a < b) { cerr << "Possible numbers can`t be less than used numbers in set\n"; continue; }
			if (a <= 0 || b <= 0) { cerr << ("a or b can`t be less or equal than 0\n"); continue; }

			value = Permutation(a, b);
			cout << "Permutation(" << a << "," << b << ") = " << value << endl;
			break;
		}
		case 'C': case 'c':
		{
			cout << "Enter two numbers:\n";
			cout << "First for number of entity, second number for number of used entity\n";
			cin >> a >> b;

			// Check for errors
			if (a < b) { cerr << "Possible numbers can`t be less than used numbers in set\n"; continue; }
			if (a <= 0 || b <= 0) { cerr << ("a or b can`t be less or equal than 0"); continue; }

			value = Combination(a, b);
			cout << "Combinations(" << a << "," << b << ") = " << value << endl;
			break;
		}
		default:
			cout << "Bye!\n";
			return 0;
		}
	}
	return 1;
}

double Permutation(double a, double b)
{
	try
	{
		return Factorial(a) / Factorial(a - b);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
}

double Combination(double a, double b)
{
	try
	{
		return Permutation(a, b) / Factorial(b);
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
}

double Factorial(double num)
{
	try
	{
		for (double i = num - 1; i > 0; i--)
			num *= i;

		return num;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
}
