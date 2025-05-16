#include "PmergeMe.hpp"

// Check for negatives, decimals, overflow)
static bool parse_input(const char *str)
{
	if (!str[0]) 				// check if string empty
		return (false);

	int i = 0;
	while (str[i]) 				// check if all chars are digits
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}

	std::stringstream ss(str);	// convert string to int
	int num;
	ss >> num;

	if (ss.fail() || !ss.eof()) // check if stringstream failed
		return (false);

	if (num <= 0)				// check if negative
		return (false);

	return (true);
}

static void printVec(const std::string &msg, std::vector<int> &vec)
{
	std::cout << msg;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (it != vec.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int> 	numbersVec;
	std::deque<int> 	numbersDeque;

	for (int i = 1; i < argc; ++i)
	{
		if (parse_input(argv[i]) == false)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}

		// Use stringstream to convert to int
		std::stringstream ss(argv[i]);
		int value;
		ss >> value;

		// Store the value in both containers
		numbersVec.push_back(value);
		numbersDeque.push_back(value);
	}


	printVec("Before: ", numbersVec);


	// ----------- VECTOR -----------

	clock_t startTimeVec = clock();

	fordJohnsonSort(numbersVec);

	clock_t endTimeVec = clock();

	printVec("After: ", numbersVec);

	double durationTimeVec = (endTimeVec - startTimeVec) / (double)CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << numbersVec.size()
			  << " elements with std::vector : "
			  << std::fixed << std::setprecision(6)
			  << durationTimeVec << " us" << std::endl;

	// ------------------------------

	// ----------- DEQUE -----------

	clock_t startTimeDeque = clock();

	fordJohnsonSort(numbersDeque);

	clock_t endTimeDeque = clock();

	double durationTimeDeque = (endTimeDeque - startTimeDeque) / (double)CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << numbersDeque.size()
			  << " elements with std::deque : "
			  << std::fixed << std::setprecision(6)
			  << durationTimeDeque << " us" << std::endl;
	

	// ------------------------------
	return (0);
}
