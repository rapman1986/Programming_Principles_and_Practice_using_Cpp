#include "std_lib_facilities.h"

class Token
{
public:
	char kind;			// kind of token
	double value;		// value of token, for numbers
	Token(char ch)		// make a token from a char
		: kind(ch), value(0) {}
	Token(char ch, double value)	// make toke from a char and double, for numbers
		: kind(ch), value(value) {}
};

class Token_stream
{
public:
	Token_stream();			// constructor
	Token get();			// get a Token
	void putback(Token t);	// put a Token back to stream
private:
	bool full{ false };				// is there a Toke in buffer?
	Token buffer;			// Token buffer
};

void Token_stream::putback(Token t)
{
	if (full) error("putback into a full buffer");
	buffer = t;		// copy t to buffer
	full = true;	// buffer is full now
}

Token Token_stream::get()
{
	// check if buffer is full
	if (full)
	{
		full = false;		// remove Token from buffer
		return buffer;
	}

	// get new Token from istream
	char ch;
	cin >> ch;

	// check with switch-case the Token type
	switch (ch)
	{
	case '=':		// for print
	case 'x':		// for quit
	case '(': case ')': case '+': case '-': case '*': case '/':
	case '{': case '}': case '!':
		return Token(ch);		// let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);		// put digit back into the input stream
		double val;
		cin >> val;				// read a floatin-point number
		return Token('8', val);	// let '8' represent a number
	}
	default:
		error("bad token");
	}
}

Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

Token_stream ts;		// provides get and putback

double expression();	// declaration so that primary() can call expression()

double primary()		// deal with numbers and parentheses
{
	Token t = ts.get();

	switch (t.kind)
	{
	case '{':		// handle { expression }
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '(':		// handle ( expression )
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':		// '8' represent number
		return t.value;		// return the number`s value
	default:
		error("primary expected");
	}
}

double factorial()		// deal with !
{
	double left = primary();
	Token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
		case '!':
		{
			int d = (int)left;
			if (d == 0) left = 1;
			else
				for (int i = d - 1; i > 0; i--)
					left *= i;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term()		// deal with '*' and '/'
{
	double left = factorial();
	Token t = ts.get();		// get the next token

	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= factorial();
			t = ts.get();
			break;
		case '/':
		{
			double d = factorial();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()		// deal with + and -
{
	double left = term();	// read and evaluate term
	Token t = ts.get();		// get next token
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;		// finnaly: no more + or -: return answer
		}
	}
}

int main()
{
	// Greeting
	cout << "Welcome to simpler calculator\n";
	cout << "Enter expression using point-floating number\n";
	cout << "After expression enter = and press enter to calculate\n";
	cout << "To exit enter x and press enter\n\n";

	try
	{
		double val = 0;
		while (cin)
		{
			Token t = ts.get();
			if (t.kind == 'x') break;		// quit the program
			if (t.kind == '=')				// for print now
				cout << "= " << val << endl;
			else
				ts.putback(t);
			val = expression();
		}
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "exception \n";
		return 2;
	}
	return 0;
}