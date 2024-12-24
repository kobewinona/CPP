#include "RPN.hpp"

long RPN::processExpression(std::string &expression)
{
	std::stack<long> stack;

	for (size_t i = 0; i < expression.size(); ++i)
	{
		char ch = expression[i];

		if (std::isspace(ch))
			continue;

		if (std::isdigit(ch))
			stack.push(ch - '0');
		else if (ch == ADD || ch == SUBTRACT || ch == MULTIPLY || ch == DIVIDE)
		{
			if (stack.size() < 2)
				throw std::runtime_error("Insufficient operands");

			long b = stack.top();
			stack.pop();
			long a = stack.top();
			stack.pop();

			switch (ch)
			{
			case ADD:
				stack.push(a + b);
				break;
			case SUBTRACT:
				stack.push(a - b);
				break;
			case MULTIPLY:
				stack.push(a * b);
				break;
			case DIVIDE:
				if (b == 0)
					throw std::runtime_error("Division by zero");

				stack.push(a / b);
				break;
			}
		}
		else
			throw std::runtime_error("Invalid token: " + std::string(1, ch));
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");

	return stack.top();
}
