/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:14:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/02 16:23:29 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

// ==============================
// = Exceptions
// ==============================

const char *BadSyntaxException::what() const throw()
{
	return "Error: Bad syntax";
}

// ==============================
// = Utils functions
// ==============================

/**
 * @brief Checks if a string represents a supported arithmetic operator
 * @details Supported arithmetic operators are '+', '-', '/' and '*'.
 *
 * @param str The string to check
 * @return true if the string represents an arithmetic operator, 0 vtherwise
 */
bool is_operator(std::string str)
{
	if (str.size() > 1)
		throw BadSyntaxException();
	char c = str[0];
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

/**
 * @brief Performs an arithmetic operation on two numbers
 *
 * @param a
 * @param b
 * @param op The operator
 * @return float The result of the operation
 */
float do_op(float a, float b, char op)
{
	if (op == '+')
		return b + a;
	if (op == '-')
		return b - a;
	if (op == '/')
		return b / a;
	if (op == '*')
		return b * a;
	else
		throw BadSyntaxException();
}

// ==============================
// = BitcoinExchange Class functions
// ==============================

/**
 * @brief Handles an operand in a Reverse Polish Notation expression
 * @details This function takes a string as input and checks if it represents
 * a valid operand. The function checks if the string is a single digit. If it
 * is, the function converts the string to a float and pushes it onto the
 * _stack member variable.
 *
 * @param str The string to check
 */
void RPN::handle_operand(std::string str)
{
	if (str.size() > 1)
		throw BadSyntaxException();
	if (!isdigit(str[0]))
		throw BadSyntaxException();
	_stack.push(std::strtof(str.c_str(), 0));
}

RPN::RPN(void)
{
}

/**
 * @brief Constructs a new RPN object and evaluates an RPN expression.
 * @details This constructor takes a string representing an RPN expression as input.
 * It splits the string into tokens by space characters and processes each token.
 * If the token is an operator, we pops two numbers from the _stack member variable, performs the operation and pushes the result back onto the _stack.
 * If a token is an operand, the constructor pushes it onto the _stack.
 * After all tokens have been processed, the constructor checks if there is exactly one number left on the _stack. If there is, it prints this number and pops it from the _stack. If there is not, a BadSyntaxException is thrown.
 *
 * @param input The RPN expression to evaluate.
 */
RPN::RPN(std::string input)
{
	std::istringstream str(input);
	std::string s;
	while (std::getline(str, s, ' '))
	{
		if (is_operator(s))
		{
			if (_stack.size() < 2)
				throw BadSyntaxException();
			float a = _stack.top();
			_stack.pop();
			float b = _stack.top();
			_stack.pop();
			_stack.push(do_op(a, b, s[0]));
		}
		else
			handle_operand(s);
	}
	if (_stack.size() > 1)
		throw BadSyntaxException();
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}

RPN::RPN(RPN &r)
{
	*this = r;
}

RPN &RPN::operator=(RPN &rhs)
{
	this->_stack = rhs.getStack();
	return *this;
}

RPN::~RPN(void)
{
}

std::stack<float> RPN::getStack(void)
{
	return _stack;
}

// ===================================
// = Output stream overload Functions
// ===================================

std::ostream &operator<<(std::ostream &o, RPN &rhs)
{
	std::stack<float> stack = rhs.getStack();
	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	return o;
}
