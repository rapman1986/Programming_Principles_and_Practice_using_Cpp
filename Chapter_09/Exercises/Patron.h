#pragma once
#include "std_lib_facilities.h"
#include "Book.h"

namespace Book_Library
{
	class Patron
	{
	public:
		// Constructor
		Patron(string user_name, int card_number);

		// Get methods
		string get_User_name() const { return user_name; }
		int get_Card_Number() const { return card_number; }
		bool get_Fee() const { return fee; }

		// Set methods
		void set_Fee(bool fee) { Patron::fee = fee; }
	private:
		string user_name;
		int card_number;
		bool fee;
	};

	// Helper function
	bool owes_fee(const Patron& patron)
	{
		if (patron.get_Fee())
			return true;
		else
			return false;
	}
}