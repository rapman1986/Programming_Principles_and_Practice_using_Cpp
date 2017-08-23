#include "std_lib_facilities.h"

vector<int> string_size(vector<string> vs)
{
	vector<int> vi;
	for (string str : vs)
		vi.push_back(str.size());
	return vi;
}

void long_short(vector<string> v)
{
	vector<int> vi = string_size(v);
	int long_str = vi[0];
	int short_str = vi[0];

	for (int i = 1; i < vi.size(); i++)
	{
		if (vi[i] > long_str) long_str = vi[i];
		else if (vi[i] < short_str) short_str = vi[i];
	}

	cout << "Long string: " << v[long_str] << endl;
	cout << "Short string: " << v[short_str] << endl;
}

void lexicograph(vector<string> v)
{
	sort(v.begin(), v.end());
	cout << "First is: " << v[0] << endl;
	cout << "Last is: " << v[v.size() - 1] << endl;
}