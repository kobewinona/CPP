#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <string>
#include <algorithm>

class NotFoundException : public std::exception
{
public:
	const char *what() const throw() { return "Element not found!"; }
};

template <typename T, typename V>
typename T::iterator easyfind(T &container, V value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it != container.end())
		return it;
	else
		throw NotFoundException();
}

#endif
