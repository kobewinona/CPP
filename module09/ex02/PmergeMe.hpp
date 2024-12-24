#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vecContainer;
	std::deque<int> _deqContainer;

public:
	PmergeMe(const std::vector<int> &input);
	~PmergeMe();

	template <typename Container>
	void mergeInsertSort(Container &container);

	template <typename Container>
	void printContainer(const std::string &message,
						const Container &container) const;
	void execute();
};

#endif // PMERGE_ME_HPP
