#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// TEST 1 - From SUBJECT
int main()
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    return (0);
}

// // TEST 2 - Add new materia, use it, unequips and use again
// int main()
// {
//     IMateriaSource* src = new MateriaSource();

//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);

//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     ICharacter* bob = new Character("bob");

//     me->use(0, *bob); 
//     me->use(1, *bob); 

//     // Put a new Ice materia in slot 2
//     tmp = src->createMateria("ice");
//     me->equip(tmp); // finds an empty slot here

//     me->use(2, *bob);

//     // Test unequip
//     me->unequip(0); // Unequips the Ice materia at slot 0

//     me->use(0, *bob); // This should not do anything as slot 0 is now empty
//     delete bob;
//     delete me;
//     delete src;
//     return (0);
// }