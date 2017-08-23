#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

void ex2();
void ex4();
void ex6();
void ex11();

int main()
{
	int ex_num = 0;

	do
	{
		cout << "Enter exercise number: ";
		cin >> ex_num;
		cout << endl;

		switch (ex_num)
		{
		case 2:	
			ex2();
			break;

		case 4:
			ex4();
			break;

		case 6:
			ex6();
			break;

		case 11:
			ex11();
			break;

		default:
			break;
		}
	} while (ex_num > 0);
}

void ex11()
{
	int pennies, nickels, dimes, quarters, half_dollar, total_cents;
	double dollars;

	// Promt to user
	cout << "Enter pennies, nickels, dimes, quarters and half dollars\n";
	cin >> pennies >> nickels >> dimes >> quarters >> half_dollar;

	// Print results
	cout << "You have " << pennies;
	if (pennies != 1)
		cout << " pennies\n";
	else
		cout << " pennie\n";

	cout << "You have " << nickels;
	if (nickels != 1)
		cout << " nickels\n";
	else
		cout << " nickel\n";

	cout << "You have " << dimes;
	if (dimes != 1)
		cout << " dimes\n";
	else
		cout << " dime\n";

	cout << "You have " << quarters;
	if (quarters != 1)
		cout << " quarters\n";
	else
		cout << " quarter\n";


	cout << "You have " << half_dollar;
	if (half_dollar != 1)
		cout << " hald dollars\n";
	else
		cout << " half dollar\n";

	total_cents = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollar;
	cout << "The values of all your coins is " << total_cents;
	if (total_cents != 1)
		cout << " cents\n";
	else
		cout << " cent\n";

	dollars = (double)total_cents / 100.0;
	cout << "You have $" << dollars << endl;
}

void ex6()
{
	int val1, val2, val3;
	cout << "Enter three integers: \n";
	cin >> val1 >> val2 >> val3;

	if (val1 > val2)
	{
		val1 += val2;
		val2 = val1 - val2;
		val1 -= val2;
	}

	if (val1 > val3)
	{
		val1 += val3;
		val3 = val1 - val3;
		val1 -= val3;
	}

	if (val2 > val3)
	{
		val2 += val3;
		val3 = val2 - val3;
		val2 -= val3;
	}

	cout << val1 << ", " << val2 << ", " << val3 << endl;
}

void ex4()
{
	int val1, val2;

	cout << "Enter two integers: ";
	cin >> val1 >> val2;
	int dif = 0;
	double ratio = 1;

	if (val1 > val2)
	{
		cout << val1 << " is larger than " << val2 << endl;
		dif = val1 - val2;
		ratio = val1 / val2;
	}
	else if (val1 < val2)
	{
		cout << val2 << " is larger than " << val1 << endl;
		dif = val2 - val1;
		ratio = val2 / val1;
	}
	else
		cout << "Values are equals" << endl;

	cout << "Sum is " << val1 + val2 << endl;
	cout << "Difference is " << dif << endl;
	cout << "Product is " << val1*val2 << endl;
	cout << "Ratio is " << ratio << endl;
}

void ex2()
{
	double ratio = 1.609;
	double kilometers = 0;
	double miles = 0;

	cout << "Enter miles: ";
	cin >> miles;

	kilometers = miles * ratio;

	cout << "Kilometers == " << kilometers << endl;
}