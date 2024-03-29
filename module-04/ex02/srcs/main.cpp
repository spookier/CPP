#include "../incs/Cat.hpp"
#include "../incs/Dog.hpp"
#include "../incs/WrongCat.hpp"

int main(void)
{
    AAnimal* list[40];

    // * MEMORY ALLOCATION
    std::cout << "--> Allocating 20 Dogs ..." << std::endl;
    for (int i = 0; i < 20; i++)
    {
        list[i] = new Dog();
        std::cout << "> Main Created : " << list[i]->getType() << " " << i << std::endl;
        list[i]->makeSound();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "--> Allocating 20 Cats ..." << std::endl;
    for (int i = 20; i < 40; i++)   // Careful to start i at 20 here so it doesn't overwrite
    {
        list[i] = new Cat();
        std::cout << "Main Created : " << list[i]->getType() << " " << i << std::endl;
        list[i]->makeSound();
        std::cout << std::endl;
    }

    // * FREEING MEMORY
    for (int i = 0; i < 40; i++)
    {
        std::cout << "Main Deleting : " << list[i]->getType() << " " << i << std::endl;
        delete list[i];
        std::cout << std::endl;
    }

    return (0);
}

// // * TEST 2
// int main()
// {
//     const AAnimal* j = new Dog();
//     const AAnimal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;

//     return (0);
// }