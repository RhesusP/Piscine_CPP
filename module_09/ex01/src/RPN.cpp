/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:14:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/17 14:15:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

const char *BadSyntaxException::what() const throw()
{
	return "Error: Bad syntax";
}

int is_operator(std::string str)
{
	if (str.size() > 1)
		throw BadSyntaxException();
	char c = str[0];
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (1);
	return (0);
}

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
