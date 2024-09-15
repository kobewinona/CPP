#pragma once

#include <iterator>
#include <vector>

class Span {
private:
  size_t _maxSize;
  std::vector<int> _numbers;

public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  // @defgroup member functions
  void addNumber(int number);
  template <typename InputIterator>
  void addNumbers(InputIterator begin, InputIterator end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
      throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end);
  };
  int shortestSpan() const;
  int longestSpan() const;

  class SpanFullException : public std::exception {
  public:
    const char *what() const throw() { return "Span is already full!"; }
  };

  class NotEnoughNumbersException : public std::exception {
  public:
    const char *what() const throw() {
      return "Not enough numbers to find a span!";
    }
  };
};
