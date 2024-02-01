/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:13:58 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/01 10:26:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdlib.h>
#include <string>

class BadSyntaxException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class RPN
{
private:
	std::stack<float> _stack;

	void handle_operand(std::string str);

public:
	RPN(void);
	RPN(std::string input);
	RPN(RPN &r);
	RPN &operator=(RPN &rhs);

	std::stack<float> getStack(void);
	~RPN(void);
};

std::ostream &operator<<(std::ostream &o, RPN &rhs);

#endif