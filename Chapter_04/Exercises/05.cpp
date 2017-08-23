#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

void Add(double, double);
void Sub(double, double);
void Mult(double, double);
void Div(double, double);

int main()
{
	double num1, num2;
	char operation;

	cout << "Enter two numbers and operation, + - * /\n";
	cin >> num1 >> num2 >> operation;

	if (operation == '+')
		Add(num1, num2);
	else if (operation == '-')
		Sub(num1, num2);
	else if (operation == '*')
		Mult(num1, num2);
	else
		Div(num1, num2);

	return 0;
}

void Add(double num1, double num2)
{
	cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
}

void Sub(double num1, double num2)
{
	cout << "The substraction of " << num1 << " and " << num2 << " is " << num1 - num2 << endl;
}

void Mult(double num1, double num2)
{
	cout << "The multiplication of " << num1 << " and " << num2 << " is " << num1 * num2 << endl;
}

void Div(double num1, double num2)
{
	cout << "The division of " << num1 << " and " << num2 << " is " << num1 / num2 << endl;
}
