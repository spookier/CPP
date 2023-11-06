#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contacts.hpp"
#include <iostream>

class PhoneBook
{
	public:
		PhoneBook();
		Contacts 	getContact(int n);
		int 		get_increment(void);
		void 		increment_contact_count(void);
		int 		add_contact(Contacts newContact);

	private:
		Contacts contacts[8];
		size_t contacts_count;
};

#endif