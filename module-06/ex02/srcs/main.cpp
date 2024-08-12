#include "../incs/Base.hpp"
#include "../incs/Functions.hpp"

int main()
{
    // // Testing with *ptr
    Base *base = generate();
	identify(base);
	delete (base);


    // // Testing with reference &
    // Base *base = generate();
	// identify(*base);
	// delete (base);

    return(0);
}