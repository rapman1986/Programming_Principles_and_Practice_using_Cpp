#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	int n_sum;
	vector<int> nums;
	int sum = 0;

	// get N value and check for error
	cout << "Enter number of values to calculate the sum: ";
	cin >> n_sum;
	if (n_sum <= 0) { cerr << "Wrong value enterd\n"; return 1; }

	// get values and store them in vector
	cout << "Enter some integers:\n";
	for (int num; cin >> num;)
		nums.push_back(num);

	// check if n_num <= nums.size()
	if (n_sum > nums.size()) cerr << "WARNING: You enterd not enough data\n";

	// calculate sum
	for (int i = 0; i < n_sum && i < nums.size(); i++)
		sum += nums[i];

	cout << "Sum of ";
	if (n_sum <= nums.size()) cout << n_sum;
	else cout << nums.size();
	cout << " elements is " << sum << endl;

	return 0;
}