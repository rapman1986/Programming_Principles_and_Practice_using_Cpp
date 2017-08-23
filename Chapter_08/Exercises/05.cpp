#include "std_lib_facilities.h"

vector<int> reverse(vector<int>);
void reverse_vector(vector<int>&);
void swap(int&, int&);
void print(string, vector<int>);

int main()
{
	vector<int> v = { 1,2,3,4,5,6 };
	vector<int> v1 = reverse(v);
	print("V1", v1);
	reverse_vector(v);
	print("V2", v);
}

vector<int> reverse(vector<int> vctr)
{
	vector<int> reversed_vector;

	for (int i = vctr.size(); i > 0; i--)
		reversed_vector.push_back(vctr[i - 1]);

		return  reversed_vector;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse_vector(vector<int>& vctr)
{
	for (int i = 0, j = vctr.size() - 1; i < j; i++, j--)
		swap(vctr[i], vctr[j]);
}

void print(string str, vector<int> vct)
{
	cout << "Vector: " << str << endl;
	for (int v : vct)
		cout << v << " ";
	cout << endl;
}

