#include "PmergeMe.hpp"

// @defgroup constructors
PmergeMe::PmergeMe(const std::vector<int> &input)
{
	_vecContainer = input;
	_deqContainer.assign(input.begin(), input.end());
}

// @def destructor
PmergeMe::~PmergeMe() {}

// @defgroup member functions
template <typename Container>
void PmergeMe::mergeInsertSort(Container &container)
{
	if (container.empty())
		return;

	// Pair and sort smaller elements
	Container smaller, larger;
	for (std::size_t i = 0; i < container.size(); i += 2)
	{
		if (i + 1 < container.size())
		{
			if (container[i] < container[i + 1])
			{
				smaller.push_back(container[i]);
				larger.push_back(container[i + 1]);
			}
			else
			{
				smaller.push_back(container[i + 1]);
				larger.push_back(container[i]);
			}
		}
		else
			smaller.push_back(container[i]);
	}

	// Sort smaller elements
	std::sort(smaller.begin(), smaller.end());

	// Insert larger elements
	for (std::size_t i = 0; i < larger.size(); ++i)
	{
		typename Container::iterator it = std::lower_bound(smaller.begin(), smaller.end(), larger[i]);
		smaller.insert(it, larger[i]);
	}

	container = smaller;
}

template <typename T>
void PmergeMe::printContainer(const std::string &message,
							  const T &container) const
{
	std::cout << message;
	for (typename T::const_iterator it = container.begin(); it != container.end();
		 ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Execute the algorithm and measure performance
void PmergeMe::execute()
{
	clock_t start, end;

	// Sort and time vector
	start = clock();
	mergeInsertSort(_vecContainer);
	end = clock();
	double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Sort and time deque
	start = clock();
	mergeInsertSort(_deqContainer);
	end = clock();
	double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// Print results
	printContainer("Sorted vector: ", _vecContainer);
	std::cout << std::fixed;
	std::cout << "Time taken by vector: " << vecTime << " seconds" << std::endl;

	printContainer("Sorted deque: ", _deqContainer);
	std::cout << "Time taken by deque: " << deqTime << " seconds" << std::endl;
}
