#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <string>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw() { return "Element not found!"; }
};

template <typename T, typename V>
typename T::iterator easyfind(T &container, V value)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();

	while (it != end)
	{
		if (*it == value)
			return it;
		++it;
	}

	throw NotFoundException();
}

#endif
