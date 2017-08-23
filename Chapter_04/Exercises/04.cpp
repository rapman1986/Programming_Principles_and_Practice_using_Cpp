#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	constexpr int MAX_ATTEMPTS = 7;
	int attempts = 1;
	int pc_guess = 50, max_guess = 101, min_guess = 1;
	char user_input;

	cout << "Wellcome to Guess Game\n";
	cout << "Think about some number between 1 to 100\n";
	cout << "Let`s begin\n\n";

	while (attempts <= MAX_ATTEMPTS)
	{
		cout << "Is the number you are thinking of less than " << pc_guess << "? (Enter y/n)	";
		cout << "Enter g if you thinked about " << pc_guess << endl;
		cin >> user_input;
		if (user_input == 'y')
		{
			max_guess = pc_guess;
			pc_guess = (min_guess + max_guess) / 2;
		}
		else if (user_input == 'n')
		{
			min_guess = pc_guess;
			pc_guess = (min_guess + max_guess) / 2;
		}
		else
			break;
		attempts++;
	}

	cout << "You thinked about " << pc_guess << endl;
	cout << "Game over\n";

	return 0;
}