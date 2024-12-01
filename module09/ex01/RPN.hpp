#pragma once

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
  static long processExpression(std::string &expression);
};
