#include "Book.h"

namespace Book_Library
{
	Book::Book(string author, string title, Genre genre, string isbn, string copyright)
		:author{ author }, title{ title }, genre{ genre },
		isbn{ isbn }, copyright{ copyright }
	{
		is_checked_out = false;		// set book not check out state

		// check ISBN
		while (!Validate_ISBN())
		{
			cerr << "Wrong ISBN\n";
			cerr << "Must be " << isbn_size << " chars length\n";
			cerr << "And of type: NNNXX..., where N - digit, X - letter or digit\n";
			cerr << "Enter new ISBN ";
			cin >> isbn;
			Book::isbn = isbn;
		}
	}

	string Book::get_Genre() const
	{
		switch (int(Book::genre))
		{
		case 0:
			return "fiction";
		case 1:
			return "nonfiction";
		case 2:
			return "periodical";
		case 3:
			return "biography";
		case 4:
			return "children";
		default:
			return "no genre";
		}
	}

	void Book::CheckInOut()
	{
		if (is_checked_out)
		{
			is_checked_out = false;
			cout << title << " is checked in back\n";
		}
		else
		{
			is_checked_out = true;
			cout << title << " is checked out\n";
		}
	}

	bool Book::Validate_ISBN()
	{
		bool is_valid = true;

		if (isbn.size() != isbn_size)
			is_valid = false;
		else
		{
			for (int i = 0; i < isbn_size; i++)
			{
				// ISBN = NNNXXXX...
				// N - digit, X - digit or letter
				switch (i)
				{
				case 0:
					if (isbn[i] < '1' || isbn[9] > '9')
						is_valid = false;
					break;
				case 1: case 2:
					if (isbn[i] < '0' || isbn[i] > '9')
						is_valid = false;
					break;
				default:
					if (isbn[i] >= '0' && isbn[i] <= '9');			// its okay
					else if (isbn[i] >= 'a' && isbn[i] <= 'z');		//its okay
					else if (isbn[i] >= 'A' && isbn[i] <= 'Z');		// its okay
					else is_valid = false;							// ISBN is wrong
					break;
				}
			}
		}

		return is_valid;
	}

	// Helper operators for Book class
	bool operator==(const Book& b1, const Book& b2)	// compare ISBN for two books
	{
		if (b1.ISBN().size() != b2.ISBN().size())
			return false;

		for (int i = 0; i < b1.ISBN().size(); i++)
			if (b1.ISBN()[i] != b2.ISBN()[i])
				return false;

		return true;
	}

	bool operator!=(const Book & b1, const Book & b2)
	{
		return !(b1 == b2);
	}

	ostream& operator<<(ostream & os, const Book & book)
	{
		os << "Title: " << book.Title()
			<< ", Author: " << book.Author()
			<< ", Genre: " << book.get_Genre()
			<< ", ISBN: " << book.ISBN()
			<< ", Copyright: " << book.Copyright()
			<< endl;
	}
}