#include "../incs/Contacts.hpp"
#include "../incs/Phonebook.hpp"
#include <iostream>

static int check_if_only_spaces(std::string field)
{
	size_t i;

	i = 0;
	while (field[i] == ' ')
		i++;

	if(i == field.length())
		return (-1);
	else
		return (0);
}

static int check_string(std::string field)
{

	if (field.length() <= 0 || field == "" || (check_if_only_spaces(field) == -1))
	{
		std::cout << "[ERROR] - Field can't be empty. Try again.\n";
		return (-1);
	}
	else
		return (0);
}


void PhoneBook::increment_contact_count()
{
	this->contacts_count++;
}

PhoneBook::PhoneBook()
{
	contacts_count = 0;
}

int PhoneBook::add_contact(Contacts newContact)
{
	std::string vars[5];

	while (1)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, vars[0]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(-1);
		}
		if (check_string(vars[0]) == -1)
			continue;
		break;
	}

	while (1)
	{
		std::cout << "Enter a last name: ";
		std::getline(std::cin, vars[1]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(-1);
		}
		if (check_string(vars[1]) == -1)
			continue;
		break;
	}

	while (1)
	{
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, vars[2]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(-1);
		}
		if (check_string(vars[2]) == -1)
			continue;
		break;
	}

	while (1)
	{
		std::cout << "Enter a phone number: ";
		std::getline(std::cin, vars[3]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(-1);
		}
		if (check_string(vars[3]) == -1)
			continue;
		break;
	}

	while (1)
	{
		std::cout << "Enter a secret: ";
		std::getline(std::cin, vars[4]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(-1);
		}
		if (check_string(vars[4]) == -1)
			continue;
		break;
	}

	newContact.fill_contact(vars);
	this->contacts[this->get_increment() % 8] = newContact;
	
	return (0);
}

int PhoneBook::get_increment(void)
{
	return(this->contacts_count);
}

Contacts PhoneBook::getContact(int n)
{
	return (this->contacts[n]);
}