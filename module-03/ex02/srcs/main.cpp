#include "../incs/FragTrap.hpp"

int main(void)
{
    FragTrap alex_Frag_obj      = FragTrap("ALEX_Frag");
    FragTrap eve_Frag_obj       = FragTrap("EVE_Frag");

    int i;

    // i = 0;
    // while(i <= 10)
    // {
    //     std::cout << "------------- TURN [" << i << "] -------------" << std::endl;

    //     alex_Frag_obj.attack("EVE_Frag");
    //     eve_Frag_obj.takeDamage(30);

    //     if (i == 2)
    //         alex_Frag_obj.highFivesGuys(); 

    //     if (i == 4)
    //         alex_Frag_obj.highFivesGuys();      

    //     std::cout << std::endl;
    //     i++;
    // }


    // Set of tests where every other turn (i modulo 2) they attack each other

    i = 0;
    while(i <= 10)
    {
        std::cout << "------------- TURN [" << i << "] -------------" << std::endl;

        if (i % 2 == 0)
        {
            alex_Frag_obj.attack("EVE_Frag");
            eve_Frag_obj.takeDamage(alex_Frag_obj.getDamage());
        }
        else
        {
            eve_Frag_obj.attack("ALEX_Frag");
            alex_Frag_obj.takeDamage(eve_Frag_obj.getDamage());
        }

        if (i % 3 == 0)
        {
            alex_Frag_obj.highFivesGuys();
        }
        else if(i % 4 == 0)
        {
            eve_Frag_obj.highFivesGuys();
        }

        std::cout << std::endl;
        i++;
    }


    return (0);
}