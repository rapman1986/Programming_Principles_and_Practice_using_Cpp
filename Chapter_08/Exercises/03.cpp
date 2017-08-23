#include "std_lib_facilities.h"

void print(string, vector<int>);
vector<int> fibonacci(int, int, vector<int>, int);

int main()
{
	vector<int> vct = fibonacci(0, 1, vct, 15);
	print("Fibonacci", vct);

	return 0;
}

void print(string str, vector<int> vct)
{
	cout << "Vector: " << str << endl;
	for (int v : vct)
		cout << v << " ";
	cout << endl;
}

vector<int> fibonacci(int x, int y, vector<int> v, int n)
{
	if (v.size() != 0)
		error("vector not empty!");
	
	// start build fibonacci vector, x and y are first elemts
	v.push_back(x);
	v.push_back(y);
	for (int i = 0; i < n - 2; i += 2)
	{
		x += y;
		y += x;
		v.push_back(x);
		v.push_back(y);
	}

	return v;
}
