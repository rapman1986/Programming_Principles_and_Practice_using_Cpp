#include "std_lib_facilities.h"

class Name_value
{
public:
	Name_value(string name, int score);
	void print();
	string getName();
	int getScore();
private:
	string name;
	int score;
};

Name_value::Name_value(string name, int score)
{
	Name_value::name = name;
	Name_value::score = score;
}

void Name_value::print()
{
	cout << Name_value::name << " " << Name_value::score << endl;
}

string Name_value::getName()
{
	return Name_value::name;
}

int Name_value::getScore()
{
	return Name_value::score;
}

vector<Name_value> getValues()
{
	vector<Name_value> names;

	// get names and scores
	cout << "Enter name and score, to terminame enter \"NoName 0\"" << endl;
	while (true)
	{
		string name;
		int score;
		cin >> name >> score;
		if (name == "NoName") break;
		names.push_back(Name_value(name, score));
	}

	return names;
}

void printNames(vector<Name_value> names)
{
	for (Name_value name : names)
		name.print();
}

bool checkForDuplicates(vector<Name_value> names)
{
	// if vector have duplicates return true, else return false

	for (int i = 0; i < names.size(); i++)
		for (int j = i + 1; j < names.size(); j++)
			if (names[i].getName() == names[j].getName())
				return true;

	return false;
}

int main()
{
	vector<Name_value> names = getValues();
	if (checkForDuplicates(names)) error("duplicate names");
	printNames(names);
}