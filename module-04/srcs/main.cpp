#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongCat.hpp"

// * TEST 1 -- TEST FROM SUBJECT
int main()
{
    std::cout << "--- CONSTRUCTORS INIT ---" << std::endl;
    const Animal*       meta = new Animal();
    const Animal*       j = new Dog();
    const Animal*       i = new Cat();
    std::cout << "-------------------------" << std::endl;

    std::cout << std::endl;

    std::cout << "--------- GET TYPE ------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << "-------------------------" << std::endl;

    std::cout << std::endl;

    std::cout << "------- MAKE SOUND ------" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "-------------------------" << std::endl;
    
    delete meta;
    delete j;
    delete i;

    return(0);
}

// // * TEST 2 -- ONLY WRONG ANIMAL NOISES
// int main()
// {
//     std::cout << "--- CONSTRUCTORS INIT ---" << std::endl;
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i    = new WrongCat();
//     std::cout << "-------------------------" << std::endl;

//     std::cout << std::endl;

//     std::cout << "--------- GET TYPE ------" << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     std::cout << meta->getType() << " " << std::endl;
//     std::cout << "-------------------------" << std::endl;

//     std::cout << std::endl;

//     std::cout << "------- MAKE SOUND ------" << std::endl;
//     i->makeSound(); // will output the cat sound!
//     meta->makeSound();
//     std::cout << "-------------------------" << std::endl;
    
//     delete meta;
//     delete i;

//     return(0);
// }

// // * TEST 3 -- WRONG ANIMAL NOISES BUT BETTER TO SEE THE DIFFERENCE
// int main()
// {
//     std::cout << "--- CONSTRUCTORS INIT ---" << std::endl;
//     const WrongAnimal*  meta = new WrongAnimal();
//     const Animal*       j = new Dog();
//     const WrongAnimal*  i = new WrongCat();
//     std::cout << "-------------------------" << std::endl;

//     std::cout << std::endl;

//     std::cout << "--------- GET TYPE ------" << std::endl;
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     std::cout << meta->getType() << " " << std::endl;
//     std::cout << "-------------------------" << std::endl;

//     std::cout << std::endl;

//     std::cout << "------- MAKE SOUND ------" << std::endl;
//     i->makeSound(); // will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     std::cout << "-------------------------" << std::endl;
    
//     delete meta;
//     delete j;
//     delete i;

//     return(0);
// }
