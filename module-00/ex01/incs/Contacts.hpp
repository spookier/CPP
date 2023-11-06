#ifndef CONTACTS_H
#define CONTACTS_H

#include <string>
#include <iostream>

class Contacts
{
    public:
        void        fill_contact(std::string fields[5]);
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_phone();
        std::string get_secret();

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
};

#endif // CONTACTS_H
