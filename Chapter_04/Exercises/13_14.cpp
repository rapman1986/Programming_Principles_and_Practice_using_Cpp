#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	vector<int> numbers;
	vector<int> primes;
	int max;

	cout << "Program to find prime numbers betwee 1 to max\n";
	cout << "Enter max value: ";
	cin >> max;

	// Build vector of numbers
	for (int i = 2; i <= max; i++)
		numbers.push_back(i);

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] != -1)
		{
			primes.push_back(numbers[i]);

			for (int j = i + numbers[i]; j < numbers.size(); j += numbers[i])
			{
				numbers[j] = -1;	// delete non prime number
				
				if ((j + numbers[i] >= numbers.size()))
					break;
			}
		}
	}

		// print primes
		for (int pr : primes)
			cout << pr << "  ";
		cout << endl;
	return 0;
}