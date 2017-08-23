#pragma once
#include "std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Chrono.h"

namespace Book_Library
{
	class Library
	{
	public:
		void Add_Books();
		void Add_Patron();
		void Check_In(Book& book, Patron& patron);		// resume book back to library
		void Check_Out(Book& book, Patron& patron);		// take book of the library

	private:
		struct Transaction
		{
			Book book;
			Patron patron;
			Chrono::Date date;
			Transaction(Book book, Patron patron) : book{book}, patron{patron}
		};

		vector<Book> books;
		vector<Patron> patrons;
		vector<Transaction> transactions;

		// Additional methods
		int Look_for_book(const Book& book);	// looking for book in library by comparing isbn number
		int Look_for_patrons(const Patron& patron);	// look for patron and return it`s index in vector, by comparing user name and its number
	};
}