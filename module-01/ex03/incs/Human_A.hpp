#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Human_A
{
	private:
		Weapon &weapon;
		std::string name;

	public:
		Human_A(std::string name, Weapon &weapon);
		void attack();
		~Human_A();
};


#endif