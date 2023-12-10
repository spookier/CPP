#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>


class Weapon
{
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string type);
		void setType(const std::string &type);
		const std::string& getType() const;
		~Weapon();
};


#endif