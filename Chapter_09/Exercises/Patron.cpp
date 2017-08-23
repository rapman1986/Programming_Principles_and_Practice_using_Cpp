#include "Patron.h"

Book_Library::Patron::Patron(string user_name, int card_number)
	:user_name{ user_name }, card_number{ card_number }, fee{ true } {}

