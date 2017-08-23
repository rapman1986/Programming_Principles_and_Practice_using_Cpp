#include "std_lib_facilities.h"

// Constants
const char number = '8';				// t.kind means that is number Token
const char quit = 'q';					// t.kind = quit means that is quit Token
const char print = ';';					// t.kind = print means that is print Token
const string prompt = "> ";				// prompt for user
const string result = "= ";				// used to print result
const char name = 'a';					// name token
const char let = 'L';					// declaration token
const string declkey = "let";			// declaration keywoard
const char change = 'C';				// change variable token
const string changekey = "change";		// change keywoard
const char constant = 'K';				// constant variable token
const string const_key = "const";		// constant keywoard
const char help = 'h';					// help
const char Help = 'H';					// Help

/*****************************************************************************/
void Greeting();					// print greeting to user

/*****************************************************************************/
class Token
{
public:
	char kind;			// kind of token
	double value;		// value of token, for numbers
	string name;		// name for token
	Token(char ch)		// make a token from a char
		: kind(ch), value(0) {}
	Token(char ch, double value)	// make toke from a char and double, for numbers
		: kind(ch), value(value) {}
	Token(char ch, string n)
		: kind(ch), name(n) {}	//initialize kind and name
};

/*****************************************************************************/
class Token_stream
{
public:
	Token_stream();			// constructor
	Token get();			// get a Token
	void putback(Token t);	// put a Token back to stream
	void ignore(char c);	// discard characters up to and including a c
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
	case print:						// for print
	case quit:						// for quit
	case '(': case ')':
	case '+': case '-':
	case '*': case '/':
	case '{': case '}':
	case '!': case '%':
	case '=':
		return Token(ch);			// let each character represent itself

	case '.':						//  a floating-point-literal can start with dot
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);			// put digit back into the input stream
		double val;
		cin >> val;					// read a floatin-point number
		return Token(number, val);	// let '8' represent a number
	}

	case help: case Help:
		return Token(help);

	default:
	{
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || (ch == '_'))) s += ch;
			cin.putback(ch);
			if (s == declkey)return Token{ let };			// declaration keywoard
			if (s == const_key) return Token{ constant };	// constant declaration keywoard
			if (s == changekey) return Token{ change };		// change variable keywoard
			return Token(name, s);
		}
		error("bad token");
	}
	}
}

void Token_stream::ignore(char c)	// c represents the kind of token
{
	// first look in buffer
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	// now search input
	char ch = 0;
	while (cin >> ch)
		if (ch == c) return;

}

Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

Token_stream ts;				// provides get and putback

/*****************************************************************************/
double expression();			// declaration so that primary() can call expression()

/*****************************************************************************/
class Variable
{
public:
	string name;
	double value;
	bool const_var;
	Variable(string str, double val, bool constant)
		: name(str), value(val), const_var(constant) {}
};

/*****************************************************************************/
class Symbol_table
{
public:
	double get(string s);					// return the value of the Variable named s
	void set(string s, double d);			// set the Variable named s to d
	double declare(string var, double val, bool const_var);		// add (var, val) to var_table
	double change_var();					// change variable to new value

private:
	vector<Variable> var_table;
	bool is_declared(string var);			// is var already in var_table?
	bool is_constant(string var);			// is var is constant?
};

// return the value of the Variable named s
double Symbol_table::get(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
}

// set the Variable named s to d
void Symbol_table::set(string s, double d)
{
	for (Variable& v : var_table)
		if (v.name == s)
		{
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}

// is var already in var_table?
bool Symbol_table::is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

// add (var, val) to var_table
double Symbol_table::declare(string var, double val, bool const_var)
{
	if (is_declared(var)) error(var, " already declared");
	var_table.push_back(Variable(var, val, const_var));
	return val;
}

// is var is constant?
bool Symbol_table::is_constant(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var)
			if (v.const_var)
				return true;
	return false;
}

// change variable to new value
double Symbol_table::change_var()
{
	Token t = ts.get();
	if (t.kind != name) error("variable name expected");
	string var_name = t.name;

	if (is_constant(var_name))
		error(var_name + " is constansnt variable");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in change of ", var_name);

	if (is_declared(var_name))		// check is variable with same name is exist
	{
		for (int i = 0; i < var_table.size(); i++)
			if (var_name == var_table[i].name)	// find variable and put new value
			{
				double d = expression();
				var_table[i].value = d;
				return d;
			}
	}
	else
		error(var_name + " not exist");
}

Symbol_table st;

/*****************************************************************************/
double primary()				// deal with numbers and parentheses
{
	Token t = ts.get();

	switch (t.kind)
	{
	case '{':					// handle { expression }
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '(':					// handle ( expression )
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:				// '8' represent number
		return t.value;			// return the number`s value
	case name:
		return st.get(t.name);	// return the variable`s value
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("primary expected");
	}
}

/*****************************************************************************/
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
			if (d < 0) error("factorial can`t be on negative number\n");
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

/*****************************************************************************/
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
		case '%':
		{
			double d = factorial();
			if (d == 0)error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

/*****************************************************************************/
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

/*****************************************************************************/
void clean_up_mess()
{
	ts.ignore(print);
}

/*****************************************************************************/
// assume we have seen "let"
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
double declaration(bool const_var)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	st.declare(var_name, d, const_var);
	return d;
}

/*****************************************************************************/
double statement()
{
	Token t = ts.get();

	switch (t.kind)
	{
	case let:
		return declaration(false);
	case constant:
		return declaration(true);
	case change:
		return st.change_var();
	default:
		ts.putback(t);
		return expression();
	}
}

/*****************************************************************************/
void calculate()				// expression evalution loop
{
	while (cin)
		try
	{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();		// "eat" ';'
		if (t.kind == quit)	return;
		if (t.kind == help) { Greeting(); continue; }
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

/*****************************************************************************/
int main()
{
	Greeting();

	try
	{
		// predefine names
		st.declare("pi", 3.1415926535, true);
		st.declare("e", 2.7182818284, true);

		calculate();

		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		keep_window_open("~~");
		return 1;
	}
	catch (...)
	{
		cerr << "exception \n";
		keep_window_open("~~");
		return 2;
	}
	return 0;
}

/*****************************************************************************/
void Greeting()					// print greeting to user
{
	// Greeting
	cout << "Welcome to simpler calculator\n";
	cout << "Enter expression using point-floating number\n";
	cout << "After expression enter " << print << " and press enter to calculate\n";
	cout << "You can use: + - * / ! () {}\n";
	cout << "To create new  variable type: " << declkey << " var_name = expression;\n";
	cout << "To create constant variable type: " << const_key << " var_name = expression;\n";
	cout << "To change existing variable: " << changekey << " var_name = expression;\n";
	cout << "To print this help again, enter H or h\n";
	cout << "To exit enter " << quit << " and press enter\n\n";
}