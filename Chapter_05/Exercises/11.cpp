#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	int n = 1, m = 1;
	unsigned int next_num = 0;
	unsigned int max_value = pow(2, sizeof(int) * 8) / 2;

	cout << max_value << endl;
	int i = 2;
	while (next_num < max_value && next_num >= 0)
	{
		next_num = n + m;
		n = m;
		m = next_num;
		i++;
	}
	cout << "\n\nMax value: " << next_num << endl;
	cout << i << endl;
	return 0;
}