#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"


int main()
{
	vector<int> numbers;
	int num;

	cout << "Enter numbers, to stop enter CTRL+Z: ";
	while (cin >> num)
	{
		numbers.push_back(num);
	}

	sort(numbers);

	cout << "\nYou entered:\n";
	for (int n : numbers)
		cout << n << " ";
	cout << endl;

	vector<int> modes;
	num = numbers[0];
	int count = 1;

	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == num)
			count++;
		else
		{
			// store num and it counter in modes
			modes.push_back(num);
			modes.push_back(count);

			// reset
			num = numbers[i];
			count = 1;
		}
	}

	int max_count = 0;
	int mode_pos;
	for (int i = 1; i < modes.size(); i += 2)
	{
		if (max_count < modes[i])
		{
			mode_pos = i - 1;
			max_count = modes[i];
		}
	}

	cout << "The mode is " << modes[mode_pos] << " it`s appeear " << modes[mode_pos + 1] << " times" << endl;

	return 0;
}