#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;

	cout << "Enter name and score. To terminate enter \"NoName 0\": ";
	while (true)
	{
		string name;
		int score;
		cin >> name >> score;

		if (name == "NoName" && score == 0)
			break;

		names.push_back(name);
		scores.push_back(score);
	}

	// check if names is uniq
	for (int i = 0; i < names.size(); i++)
		for (int j = i + 1; j < names.size(); j++)
			if (names[j] == names[i])
			{
				cout << "Error! " << names[i] << " entered more than one time\n";
				return 0;
			}

	// print names and scores
	cout << "Name and score:\n";
	for (int i = 0; i < names.size(); i++)
		cout << names[i] << "\t" << scores[i] << endl;

	while (true)
	{
		cout << "What name you lookig for (enter \"stop\" to end): ";
		string name;
		cin >> name;

		bool found = false;
		int position = -1;

		if (name == "stop")
			break;

		for (int i = 0; i < names.size(); i++)
			if (name == names[i])
			{
				found = true;
				position = i;
			}

		if (found)
			cout << names[position] << "\t" << scores[position] << endl;
		else
			cout << "Name not found\n";
	}

	return 0;
}