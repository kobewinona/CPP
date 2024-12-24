#include "Span.hpp"

// @defgroup constructors
Span::Span(unsigned int n) : _maxSize(n) { _numbers.reserve(n); }

Span::Span(const Span &other)
	: _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}

	return *this;
}

// @def destructor
Span::~Span() {}

// @defgroup member functions
void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();

	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];

		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}