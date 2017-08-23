#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	string name = " ";
	double age = -1.0;

	cout << "Enter first name and age, and press enter...\n";
	cin >> name >> age;

	cout << "Hello " << name << ", your age is " << age * 12 << " monnths.\n";

	return 0;
}