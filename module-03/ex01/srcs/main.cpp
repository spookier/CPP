#include "../incs/ScavTrap.hpp"

int main(void)
{

    ScavTrap alex_scav_obj      = ScavTrap("ALEX_scav");
    ScavTrap eve_scav_obj       = ScavTrap("EVE_scav");


    // ScavTrap STATS : Attack Damage = 20 | HP = 100 | Energy = 50

    // To kill Eve, Alex should attack 5 times
    // (5 times * 20dmg = 100 total damage, also equivalent to a scav's health)
    // but since Eve gets repaired the 4th turn, she gains 20HP, so she can survive one more attack
    // So in total, 6 attacks are needed to kill Eve

    int i;

    i = 0;
    while(i <= 6)
    {
        std::cout << "------------- TURN [" << i << "] -------------" << std::endl;

        alex_scav_obj.attack("EVE_scav");
        eve_scav_obj.takeDamage(alex_scav_obj.getDamage());

        if(i == 2)
            alex_scav_obj.guardGate(); 

        if(i == 4)
        {
            alex_scav_obj.guardGate();      // Re-activate guard mode again for debug message
            eve_scav_obj.beRepaired(20);    // Give Eve +20HP
        }

        std::cout << std::endl;
        i++;
    }  

    // A different test, checks if they are able to attack when dead    
    // int i;

    // i = 0;
    // std::cout << "------------- SECOND TEST ------------------" << std::endl;
    // ScavTrap a          = ScavTrap("A");
    // ScavTrap b          = ScavTrap("B");

    // // Kill both
    // a.takeDamage(1000);
    // b.takeDamage(1000);
    
    // // A tries to attack B
    // a.attack("B");
    // b.takeDamage(20);

    // // B tries to attack A
    // b.attack("A");
    // a.takeDamage(2003213421);

    return (0);

}