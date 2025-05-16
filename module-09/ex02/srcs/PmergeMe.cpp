#include "PmergeMe.hpp"

static void insertInSortedVec(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator it = sorted.begin();

	while (it != sorted.end() && *it < value)	// find where *it < value and insert it there so it stays sorted
	{
		++it;
	}
	sorted.insert(it, value);
}

static void insertInSortedDeque(std::deque<int> &sorted, int value)
{
	std::deque<int>::iterator it = sorted.begin();

	while (it != sorted.end() && *it < value)
	{
		++it;
	}
	sorted.insert(it, value);
}


void fordJohnsonSort(std::vector<int> &vec)
{
	// If vector has 0 or 1 element, it's already sorted
	if (vec.size() <= 1)
		return ;

	std::vector<int> maxNumbers; // will store the largest of each pair
	std::vector<int> minNumbers; // will store the smallest of each pair

	// 1. Split into pairs and find min and max for each pair
	std::size_t i = 0;
	while (i + 1 < vec.size())
	{
		int first = vec[i];
		int second = vec[i + 1];

		if (first > second)
		{
			maxNumbers.push_back(first);  // bigger goes to maxNumbers
			minNumbers.push_back(second); // smaller goes to minNumbers
		}
		else
		{
			maxNumbers.push_back(second);
			minNumbers.push_back(first);
		}
		i += 2;
	}

	// If there's an odd last element, just put it in maxNumbers
	if (i < vec.size())
		maxNumbers.push_back(vec[i]);

	// 2. Sort the maxNumbers list by calling this function recursively
	fordJohnsonSort(maxNumbers);

	// 3. Insert each minNumber into the right place in the sorted maxNumbers
	for (std::size_t j = 0; j < minNumbers.size(); ++j)
	{
		insertInSortedVec(maxNumbers, minNumbers[j]);
	}

	// 4. Now maxNumbers has all the numbers in sorted order
	//    Copy them back to the original vector
	for (std::size_t k = 0; k < vec.size(); ++k)
	{
		vec[k] = maxNumbers[k];
	}
}


void fordJohnsonSort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;

	std::deque<int> maxNumbers;
	std::deque<int> minNumbers;

	// 1. Split into pairs
	std::size_t i = 0;
	while (i + 1 < deq.size())
	{
		int first = deq[i];
		int second = deq[i + 1];

		if (first > second)
		{
			maxNumbers.push_back(first);
			minNumbers.push_back(second);
		}
		else
		{
			maxNumbers.push_back(second);
			minNumbers.push_back(first);
		}
		i += 2;
	}
	// If odd, add last to maxNumbers
	if (i < deq.size())
		maxNumbers.push_back(deq[i]);

	// 2. Recursively sort maxNumbers
	fordJohnsonSort(maxNumbers);

	// 3. Insert each minNumber in sorted order
	for (std::size_t j = 0; j < minNumbers.size(); ++j)
	{
		insertInSortedDeque(maxNumbers, minNumbers[j]);
	}

	// 4. Copy back to original deque
	for (std::size_t k = 0; k < deq.size(); ++k)
	{
		deq[k] = maxNumbers[k];
	}
}


/*
	Explanation:

Original:   [8, 2, 4, 5, 1]
			   | 	|    |
		   pair pair  odd   |
		 /----/  \---/   \--/
		[8,2]   [4,5]    [1]
		 |         |      |
		maxs: 8    5      1
		mins: 2    4

	maxNumbers = [8,5,1]
	minNumbers = [2,4]

	Now sort maxNumbers [8,5,1] recursively:
		pairs: [8,5], [1]
		maxs: 8, 1
		mins: 5
		-> sort again maxNumbers [8,1] recursively:
			pair: [8,1]
			maxs: 8
			mins: 1
			-> sort [8] (one element, nothing to sort, return)
			pop stack frame, insert the min 1 --> [1,8]
		pop stack frame, insert the min 5 --> [1,5,8]
	
	When the original maxNumbers has been sorted, binary insert 2 into [1,5,8] --> [1,2,5,8]
	same thing, binary insert 4 into [1,2,5,8] --> [1,2,4,5,8]


*/