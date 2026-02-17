#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(RPN const &) {}
RPN & RPN::operator=(RPN const &) { return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::evaluate(std::string const & expression) const
{
	std::stack<int> stk;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isOperator(token[0])) {
			if (stk.size() < 2)
				throw std::runtime_error("Error");
			int b = stk.top(); stk.pop();
			int a = stk.top(); stk.pop();
			if (token[0] == '+') stk.push(a + b);
			else if (token[0] == '-') stk.push(a - b);
			else if (token[0] == '*') stk.push(a * b);
			else {
				if (b == 0) throw std::runtime_error("Error: division by zero");
				stk.push(a / b);
			}
		} else {
			// must be a single digit < 10
			if (token.size() != 1 || token[0] < '0' || token[0] > '9')
				throw std::runtime_error("Error");
			stk.push(token[0] - '0');
		}
	}

	if (stk.size() != 1)
		throw std::runtime_error("Error");
	return stk.top();
}
