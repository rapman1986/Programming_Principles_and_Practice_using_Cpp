// Bulls and Cows game

#include "std_lib_facilities.h"

void WelcomeMessage();
void PlayGame();
vector<int> GetUserInput(int);
vector<int> BuildDigitsVector(int, int);
vector<int> BuildValueToGuess(int);
int GetLength();
bool CheckGuess(vector<int>, vector<int>);
bool CheckForRepeatedDigits(vector<int>);

int main()
{
	WelcomeMessage();
	PlayGame();

	return 0;
}

// Welcome message
void WelcomeMessage()
{
	cout << "\t\t### Wellcome to Bulls and Cows game ###\n";
	cout << "You need to guess some number. The digits appears only once in sequnce, and number can`t start with 0\n";
	cout << "For example: the number that you need to guess is 1234, if you enter 1378, you will get "
		<< "1 Bulls for 1 and 1 Cows for 3\n";
	cout << "#################################################################################################\n";
	cout << endl;
}

// Main game function that controliing all logic and game flow
void PlayGame()
{
	bool play_game = true;		// play game flag
	bool play_stage = true;		//. check if stage is finished

	vector<int> value_to_guess;		// number that user need to guess
	int value_length;
	vector<int> user_guess;			// user guess

	// main game loop
	while (play_game)
	{
		// Get length for value to guess
		value_length = GetLength();

		// Build value to guess
		value_to_guess = BuildValueToGuess(value_length);

		// Player plays the game
		cout << "\nWe generated number for you with " << value_length << " digits.\n";
		cout << "Try to guess it!!\n";

		while (play_stage)
		{
			user_guess = GetUserInput(value_length);
			play_stage = CheckGuess(user_guess, value_to_guess);
		}

		play_stage = true;		// reset play srage for new game

		// check if user whant to start new stage
		cout << "You guessed the number, it was ";
		for (int i = 0; i < value_to_guess.size(); i++) cout << value_to_guess[i];
		cout << endl;
		cout << "Start new game? Y/N ";
		while (true)
		{
			char answer;
			cin >> answer;
			if (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n')
				cout << "Wrong input, try again\n";
			else
			{
				if (answer == 'n' || answer == 'N') play_game = false;
				break;
			}
		}
	}

	cout << "\t\tGame Over!\n";
}

// Get user input and check it for errors
vector<int> GetUserInput(int value_length)
{
	int user_num;
	bool is_correct = false;
	vector<int> user_guess;

	while (!is_correct)
	{
		cout << "Enter your guess, " << value_length << " digits number: ";
		cin >> user_num;

		// build digits vector, and return vector
		user_guess = BuildDigitsVector(user_num, value_length);

		// check if user entered right length number
		if (user_guess.size() != value_length)
		{
			cerr << "Error: Wrong number length. Try again\n";
			continue;
		}

		// check for repeated digits, and return true or false
		is_correct = CheckForRepeatedDigits(user_guess);
	}

	return user_guess;
}

vector<int> BuildDigitsVector(int user_num, int value_length)
{
	vector<int> temp;
	vector<int> user_guess;

	while(user_num != 0)
	{
		int digit = user_num % 10;
		temp.push_back(digit);
		user_num /= 10;
	}

	for (int i = temp.size(); i > 0; i--)
		user_guess.push_back(temp[i - 1]);

	return user_guess;
}

vector<int> BuildValueToGuess(int value_length)
{
	vector<int> value_to_guess;

	for (int i = 0; i < value_length;)
	{
		srand(value_length);
		int num = randint(0, 9);

		if (i == 0 && num == 0) // check if first digit choosed to be 0, it is wrong
			continue;

		// check for repeated digit
		bool is_repeated = false;
		for (int j = 0; j < value_to_guess.size(); j++)
			if (value_to_guess[j] == num)
			{
				is_repeated = true;
				break;
			}

		// if all okay, push the number to vector, and continue
		if (!is_repeated)
		{
			value_to_guess.push_back(num);
			i++;
		}
	}

	return value_to_guess;
}

int GetLength()
{
	int value_length;

	cout << "Enter the lenght for value that you whant to guess.\n";
	cout << "Minimu value is 4 and maximum value is 10. The more length the harder game will be.\n";

	while (true)
	{
		cin >> value_length;

		if (value_length < 4 || value_length > 10)
			cout << "Wrong length, try again\t";
		else
			break;
	}

	return value_length;
}

bool CheckGuess(vector<int> user_guess, vector<int> value_to_guess)
{
	bool play_stage = true;
	int bulls = 0, cows = 0;

	for (int i = 0; i < user_guess.size(); i++)
		for (int j = 0; j < value_to_guess.size(); j++)
			if (user_guess[i] == value_to_guess[j])
				if (i == j)
					bulls++;
				else
					cows++;
	if (bulls == value_to_guess.size()) play_stage = false;		// user finished the game
	else
		cout << "Bulls = " << bulls << "; Cows = " << cows << endl;

	return play_stage;
}

bool CheckForRepeatedDigits(vector<int> user_guess)
{
	bool is_correct = true;

	// check for repeated digits
	for (int i = 0; i < user_guess.size(); i++)
		for (int j = i + 1; j < user_guess.size(); j++)
			if (user_guess[i] == user_guess[j])
				is_correct = false;
	if (!is_correct) cerr << "Error: You entered number with repeated digits\n";

	return is_correct;
}
