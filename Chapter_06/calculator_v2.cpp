#include "std_lib_facilities.h"

int main()
{
	cout << "Enter expression (we can handle +, -, * and /): ";
	cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval;
	
	cin >> lval;		// read left hand operand
	if (!cin) error("no first operand");

	for (char op; cin >> op;)
		// read operator and right hand operand repeatedly
	{
		if (op != 'x')cin >> rval;
		if (!cin) error("no second operand");

		switch (op)
		{
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
		default:
			cout << "Result: " << lval << endl;
			return 0;
		}
	}
	error("bad expression");
}
