#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	vector<string> words;

	for (string temp; cin >> temp;)
		words.push_back(temp);

	cout << "Number of words: " << words.size() << endl;

	sort(words);

	for (int i = 0; i < words.size(); i++)
		if (i == 0 || (words[i - 1] != words[i]))
			cout << words[i] << endl;

	return 0;
}