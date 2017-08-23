#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	int counter = 0;
	int n;	// max prime numbers
	vector<int> primes;
	int numPrime = 2;	// prime to check
	bool isPrime;

	cout << "Enter number of primes to calculate: ";
	cin >> n;

	while (counter < n)
	{
		isPrime = true;

		for (int i = 2; i <= sqrt(numPrime); i++)
			if (numPrime % i == 0)
				isPrime = false;

		if (isPrime)
		{
			primes.push_back(numPrime);
			counter++;
		}

		numPrime++;
	}

	cout << "The firs " << n << " prime numbers is:\n";
	for (int i : primes)
		cout << i << " ";

	cout << endl;

	return 0;
}