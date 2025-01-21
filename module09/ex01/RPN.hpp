#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

enum {
  ADD = '+',
  SUBTRACT = '-',
  MULTIPLY = '*',
  DIVIDE = '/',
};

class RPN {
public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();
  static long processExpression(std::string &expression);
};

#endif // RPN_HPP
