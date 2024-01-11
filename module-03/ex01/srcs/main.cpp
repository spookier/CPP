#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap alex_obj = ClapTrap("alex");
    ClapTrap eve_obj = ClapTrap("eve");

    // Test until it has no more energy (energy limit for an obj is 10)
    // alex_obj should run out of energy after attacking 10 times
    // damage is 0, so its normal for eve to not die

    int i;

    i = 0;
    while (i < 10)
    {
        alex_obj.attack("eve");
        eve_obj.takeDamage(1);
        i++;
    }
    
    return(0);

}