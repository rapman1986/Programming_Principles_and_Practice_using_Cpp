#include "std_lib_facilities.h"

void print_string_vectors(vector<string>, vector<string>);
void sort_vectors(vector<string>&, vector<string>&);
void get_ages(vector<string>&, vector<string>&);

int main()
{
	vector<string> names = { "ab", "gf", "swe", "zaw", "asdf", "ewer" };
	vector<string> ages;

	get_ages(names, ages);
	print_string_vectors(names, ages);

	sort_vectors(names, ages);
	print_string_vectors(names, ages);

	return 0;
}

void print_string_vectors(vector<string> names, vector<string> ages)
{
	if (names.size() != ages.size()) error("vectors not same size");
	cout << "\nThe names and ages are:\n";
	for (int i = 0; i < names.size(); i++)
		cout << names[i] << " " << ages[i] << endl;

}

void sort_vectors(vector<string>& names, vector<string>& ages)
{
	vector<string> names_copy = names;
	vector<string> ages_copy = ages;

	sort(names.begin(), names.end());	// sort names

	// sort ages
	for (int i = 0; i < names.size(); i++)
		for (int j = 0; j < names_copy.size(); j++)
			if (names[i] == names_copy[j])
				ages[i] = ages_copy[j];
}

void get_ages(vector<string>& names, vector<string>& ages)
{
	cout << "Enter ages\n";
	for (string name : names)
	{
		cout << name << " ";
		string age;
		cin >> age;
		ages.push_back(age);
	}
}
