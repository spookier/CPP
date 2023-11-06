#include "../incs/Contacts.hpp"


void Contacts::fill_contact(std::string fields[5])
{
	this->first_name 	= fields[0];
	this->last_name 	= fields[1];
	this->nickname 		= fields[2];
	this->phone_number 	= fields[3];
	this->secret 		= fields[4];
}


std::string Contacts::get_firstname()
{
	return(this->first_name);
}

std::string Contacts::get_lastname()
{
	return(this->last_name);
}


std::string Contacts::get_nickname()
{
	return(this->nickname);
}

std::string Contacts::get_phone()
{
	return(this->phone_number);
}

std::string Contacts::get_secret()
{
	return(this->secret);
}