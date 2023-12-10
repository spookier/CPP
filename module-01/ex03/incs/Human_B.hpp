#ifndef Human_B_HPP
# define Human_B_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Human_B
{
	private:
		Weapon *weapon;
		std::string name;

	public:
		Human_B(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
		~Human_B();
};


#endif