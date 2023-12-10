#include <iostream>
#include <string>
#include "../incs/Weapon.hpp"
#include "../incs/Human_A.hpp"
#include "../incs/Human_B.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		Human_A bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Human_B jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}