#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "../incs/Contacts.hpp"
#include "../incs/Phonebook.hpp"


void print_user_info(PhoneBook &book, int n)
{
	Contacts contact;

	contact = book.getContact(n);

	std::cout << "-------------------------\n";
	std::cout << "First Name: " << contact.get_firstname() << std::endl;
	std::cout << "Last Name : " << contact.get_lastname() << std::endl;
	std::cout << "Nickname  : " << contact.get_nickname() << std::endl;
	std::cout << "Phone Nb  : " << contact.get_phone() << std::endl;
	std::cout << "Secret    : " << contact.get_secret() << std::endl;
	std::cout << "-------------------------\n";
}

std::string print_column(std::string field)
{

	if(field.length() > 10)
	{
		field.resize(9);
		field += '.';
	}
	else
	{
		field += std::string(10 - field.length(), ' ');
	}
	return (field + " | ");
}

void show_contacts(PhoneBook &book)
{
	int 		i;
	int 		tmp;
	std::string	response;

	i = 0;
	while (i < book.get_increment())
	{
		Contacts c = book.getContact(i);
		std::cout << std::setw(10) << std::left << i << " | "
                  << print_column(c.get_firstname())
                  << print_column(c.get_lastname())
                  << print_column(c.get_nickname())
                  << std::endl;
		i++;
	}

	std::cout << "\nInput the index of user to see more info.\n >> ";
	std::getline(std::cin, response);

	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}

	std::istringstream(response) >> tmp; // BASICALLY A C++ ATOI
	if((tmp >= 0 && tmp <= 8) && book.get_increment() > tmp)
	{
		print_user_info(book, tmp);
	}
	else
		std::cout << "[ERROR] User ID " << response << " doesn't exist.\n\n";
}

int main(void)
{
	PhoneBook	book;
	std::string	response;

	while (1)
	{
		std::cout << "Enter a command - [ADD] | [SEARCH] | [EXIT] \n >> ";
		std::getline(std::cin, response);

		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if(response == "EXIT")
			return(0);
		else if(response == "ADD")
		{
			Contacts newContact;

			if(book.add_contact(newContact) == -1)
				return(0);

			book.increment_contact_count();
		}
		else if(response == "SEARCH")
		{
			show_contacts(book);
		}
	}
	return (0);
}
