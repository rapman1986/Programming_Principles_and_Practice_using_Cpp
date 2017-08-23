#include "Library.h"

void Book_Library::Library::Add_Books()
{
	string author;
	string title;
	Genre genre;
	string isbn;
	string copyright;

	cout << "Adding new book to library\n";
	cout << "Enter book`s author: ";
	cin >> author;

	cout << "Enter book`s title: ";
	cin >> title;

	bool get_genre = true;
	while (get_genre)
	{
		cout << "Enter genre. Enter number to choose option:\n"
			<< "Fiction - 0\n"
			<< "Nonfiction - 1\n"
			<< "Peridical - 2\n"
			<< "Biography - 3\n"
			<< "Children - 4\n";
		int gnr;
		cin >> gnr;

		// check option
		if (gnr < 0 || gnr > 4)
			cerr << "Wrong option choosed, try again\n";
		else
		{
			get_genre = false;
			genre = Genre(gnr);
		}
	}

	cout << "Enter ISBN: ";
	cin >> isbn;

	cout << "Enter copyright: ";
	cin >> copyright;

	Book new_book = Book(author, title, genre, isbn, copyright);
	books.push_back(new_book);
}

void Book_Library::Library::Add_Patron()
{
	string user_name;
	int card_number;

	cout << "Adding new patron to library\n";
	cout << "Enter user name: \n";
	cin >> user_name;

	cout << "Enter card number: \n";
	cin >> card_number;

	Patron new_patron = Patron(user_name, card_number);
	patrons.push_back(new_patron);
}

void Book_Library::Library::Check_In(Book & book, Patron & patron)
{

}

void Book_Library::Library::Check_Out(Book & book, Patron & patron)
{	
	// check if book in library
	int book_index = Look_for_book(book);
	if (book_index == -1)
	{
		cerr << "Book not found in library\n";
		return;
	}

	// check if book already checked out
	if (books[book_index].Is_Checked_out())
	{
		cerr << "Book is already checked out\n";
		return;
	}

	// Book is found, and it`s not checked out
	// Check patron
	// check if patron exist
	int patron_index = Look_for_patron(patron);
	if (patron_index == -1)
	{
		cerr << "Patron not exist in library\n";
		return;
	}

	// check if patron owe fee
	if (patrons[patron_index].get_Fee())
	{
		cerr << "Patron owes fee. He can`t to chek out new book\n";
		return;
	}

	// check out the book and add fee to patron
	books[book_index].CheckInOut();		// book checked out
	patrons[patron_index].set_Fee(true);	// set fee to patron

	// put this book and patron to Transaction vector
	Transaction new_transaction = Transaction();
}

int Book_Library::Library::Look_for_book(const Book & book)
{
	for (int i = 0; i < books.size(); i++)
		if (book.ISBN() == books[i].ISBN())		// if book found by isbn
			return i;							// return it`s index in books vector

	return -1;									// book not found, return -1
}

int Book_Library::Library::Look_for_patron(const Patron & patron)
{
	for (int i = 0; i < patrons.size(); i++)
		if (patron.get_Card_Number() == patrons[i].get_Card_Number())	// patron found by card number, check user name
			if (patron.get_User_name() == patrons[i].get_User_name())	// patron is exist
				return i;	// return its index

	return -1;	// patron not found
}
