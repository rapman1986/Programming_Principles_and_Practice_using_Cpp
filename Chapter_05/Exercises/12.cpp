// Bulls and Cows game

#include "std_lib_facilities.h"

void WelcomeMessage();
vector<int> GetUserInput();
bool CheckGuess(vector<int>, vector<int>);

int main()
{
	vector<int> value_to_guess = { 1,2,3,4 };
	vector<int> user_guess;
	bool game_end = false;

	WelcomeMessage();

	while (!game_end)
	{
		user_guess = GetUserInput();
		game_end = CheckGuess(user_guess, value_to_guess);
	}

	cout << "\t\tGame Over!\n";

	return 0;
}

// Welcome message
void WelcomeMessage()
{
	cout << "\t\t### Wellcome to Bulls and Cows game ###\n";
	cout << "You need to guess 4 digits number. The digits appears only once in sequnce, and number can`t start with 0\n";
	cout << "For example: the number that you need to guess is 1234, if you enter 1378, you will get "
		<< "Bulls for 1 and Cows for 3\n";
	cout << "#################################################################################################\n";
	cout << endl;
}

// Get user input and check it for errors
vector<int> GetUserInput()
{
	int user_num;
	bool is_correct = false;
	vector<int> digits = { 0,0,0,0 };

	while (!is_correct)
	{
		cout << "Enter you guess, 4 digits number: ";
		cin >> user_num;

		// check if user entered 4 digits number
		if (user_num < 1000 || user_num > 9999)
		{
			cerr << "Error: Wrong number, enter 4 digits only\n";
			continue;
		}

		// build digits vector
		for (int i = 0; i < 4; i++)
		{
			int digit = user_num % 10;
			digits[3 - i] = digit;
			user_num /= 10;
		}

		is_correct = true;

		// check for repeated digits
		for (int i = 0; i < 4; i++)
			for (int j = i+1; j < 4; j++)
				if (digits[i] == digits[j])
					is_correct = false;
		if (!is_correct) cerr << "Error: You entered number with repeated digits\n";
	}

	return digits;
}

bool CheckGuess(vector<int> user_guess, vector<int> value_to_guess)
{
	bool game_end = false;
	int bulls = 0, cows = 0;

	for (int i = 0; i < user_guess.size(); i++)
		for (int j = 0; j < value_to_guess.size(); j++)
			if (user_guess[i] == value_to_guess[j])
				if (i == j)
					bulls++;
				else
					cows++;
	if (bulls == value_to_guess.size()) game_end = true;		// user finished the game
	else
		cout << "Bulls = " << bulls << "; Cows = " << cows << endl;

	return game_end;
}
