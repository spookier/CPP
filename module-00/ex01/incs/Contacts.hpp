#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>
#include <iostream>

class Contacts
{
public:
    unsigned int 	ID;
    std::string		name;
    std::string 	number;

    Contacts(unsigned int _ID, std::string _name, std::string _number);
};

#endif // CONTACTS_H
