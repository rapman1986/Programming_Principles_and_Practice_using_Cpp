#include "std_lib_facilities.h"

int main()
{
	cout << "Enter expression (we can handle + and -): ";
	int lval = 0;
	int rval = 0;
	char op;
	int res = 0;

	cin >> lval >> op >> rval;

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;

	cout << "Result: " << res << endl;

	return 0;
}