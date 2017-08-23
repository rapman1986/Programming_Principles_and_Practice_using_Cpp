#pragma once
#include "std_lib_facilities.h"

namespace Book_Library
{
	enum class Genre
	{
		fiction, nonfiction, periodical, biography, children
	}; // Genre

	class Book
	{
	public:
		// Cinstructor
		Book(string authot, string title, Genre genre, string isbn, string copyright);

		// Get`s
		string ISBN() const { return isbn; }
		string Title() const { return title; }
		string Author() const { return author; }
		string Copyright() const { return copyright; }
		string get_Genre() const;

		// Additional
		bool Is_Checked_out() { return is_checked_out; }
		void CheckInOut();

	private:
		string isbn;
		string title;
		string author;
		string copyright;
		Genre genre;
		const int isbn_size = 4;
		bool is_checked_out;
		bool Validate_ISBN();
	};

	// Helper operators for Book class
	bool operator==(const Book& b1, const Book& b2);	// compare ISBN for two books
	bool operator!=(const Book& b1, const Book& b2);	// compare ISBN for two books
	ostream& operator<<(ostream& os, const Book& book);		// print Book data to cmd
}