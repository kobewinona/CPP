#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type::iterator iterator;

	MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack<T> &operator=(const MutantStack<T> &other);
	virtual ~MutantStack();

	iterator begin();
	iterator end();
};

// @defgroup constructors
template <typename T>
MutantStack<T>::MutantStack() : stack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : stack(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this != &other)
		stack::operator=(other);

	return *this;
}

// @def destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// @defgroup member functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

#endif
