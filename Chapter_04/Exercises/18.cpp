#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	double a, b, c;
	double x1, x2;

	cout << "Enter a, b and c for quadratic formula: ";
	cin >> a >> b >> c;

	// if a = 0
	if (a == 0)
	{
		x1 = (-c) / b;
		cout << "Equation have only one solution: " << x1 << endl;
		return 0;
	}

	// if a != 0
	double root = b*b - 4.0 * a*c;

	if (root < 0)
		cout << "The equation don`t have solution\n";
	else if (root == 0)
	{
		cout << "Equation have only one solution: ";
		x1 = -b / (2.0 * a);
		cout << x1 << endl;
	}
	else
	{
		root = sqrt(root);
		x1 = (-b - root) / (2.0*a);
		x2 = (-b + root) / (2.0*a);
		cout << "Solutions are " << x1 << " and " << x2 << endl;
	}


	return 0;
}