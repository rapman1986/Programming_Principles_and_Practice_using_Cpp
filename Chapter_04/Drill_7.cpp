#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

bool CheckUnit(string);
double ConvertToMeter(double, string);
void PrintValues(vector<double>);

int main()
{
	double num, smallest, larger, total_sum = 0.0;
	vector<double> values;
	int counter = 0;
	string unit;

	cout << "Enter value and meassure unit (cm, m, in, ft)\t";

	while (cin >> num >> unit)
	{
		if (!CheckUnit(unit))
		{
			cout << "You entered wrong unit, try again\n";
			cout << "\nEnter value and meassure unit (cm, m, in, ft)\t";
			continue;
		}

		values.push_back(ConvertToMeter(num, unit));	// convert to meter and store in vector
		counter++;

		if (counter == 1)		// check if this is first value that entered, and set 
			smallest = larger = total_sum = num;
		else
		{
			if (values[counter - 1] < smallest) smallest = values[counter - 1];
			if (values[counter - 1] > larger)  larger = values[counter - 1];
			total_sum += values[counter - 1];
		}

		cout << "You entered: " << num << unit << endl;

		cout << "\nEnter value and meassure unit (cm, m, in, ft)\t";
	}

	// print results
	cout << "\nSmallest value is\t" << smallest << "m\n";
	cout << "Larger value is\t" << larger << "m\n";
	cout << "Total values is\t" << total_sum << "m\n";
	cout << "Total values entered is\t" << counter << endl;
	cout << "You entered:\t";
	PrintValues(values);
}

bool CheckUnit(string unit)
{
	vector<string> units = { "cm", "m", "in", "ft" };

	for (int i = 0; i < units.size(); i++)
		if (unit == units[i])
			return true;

	return false;
}

double ConvertToMeter(double value, string unit)
{
	constexpr double CONV_M_TO_CM = 100.0;
	constexpr double CONV_IN_TO_CM = 2.54;
	constexpr double CONV_FT_TO_IN = 12.0;

	if (unit == "ft")
	{
		value *= CONV_FT_TO_IN;		// convert ft to in
		unit = "in";
	}

	if (unit == "in")
	{
		value *= CONV_IN_TO_CM;		// convert in to cm
		unit = "cm";
	}

	if (unit == "cm")
	{
		value /= CONV_M_TO_CM;		// convert cm to m
		unit = "m";
	}
	return value;
}

void PrintValues(vector<double> values)
{
	sort(values);
	for (double value : values) cout << value << "m" << "\t";
	cout << endl;
}
