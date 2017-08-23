#include "std_lib_facilities.h"

void print(string, vector<int>);

int main()
{
	vector<int> vct;
	for (int i = 1; i < 1025; i *= 2)
		vct.push_back(i);
	print("PWS", vct);

	return 0;
}

void print(string str, vector<int> vct)
{
	cout << "Vector: " << str << endl;
	for (int v : vct)
		cout << v << " ";
	cout << endl;
}
