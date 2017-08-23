#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	vector<int> numbers;
	vector<int> primes;
	bool is_prime;
	int max;

	cout << "Program to find prime numbers betwee 1 to max\n";
	cout << "Enter max value: ";
	cin >> max;

	// Build vector of numbers
	for (int i = 3; i <= max; i++)
		numbers.push_back(i);

	// Loock for prime and store it in primes vector
	primes.push_back(2);
	for (int i = 0; i < numbers.size(); i++)
	{
		int prime = numbers[i];		// suggest if number is prime
		is_prime = true;

		// check if it prime
		for (int i = 2; i <= sqrt(prime); i++)
			if ((prime %  i) == 0)		// if not prime
			{
				is_prime = false;
				break;
			}

		if (is_prime)
			primes.push_back(prime);
	}

	// print primes
	for (int pr : primes)
		cout << pr << "  ";
	cout << endl;

	return 0;
}