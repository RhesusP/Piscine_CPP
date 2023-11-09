/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:24:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/09 16:39:50 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &s)
{
	*this = s;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

bool	isPseudoLiteral(std::string str)
{
	if (str == "-inff")
		return true;
	else if (str == "+inff")
		return true;
	else if (str == "nanf")
		return true;
	else if (str == "+-inf")
		return true;
	else if (str == "+inf")
		return true;
	else if (str == "nan")
		return true;
	else
		return false;
}

bool	isOnlyNumber(std::string const & litteral) {
	for (size_t i = 0 ; i < litteral.size() ; i++) {
		if (!isdigit(litteral[i]))
			return (false);
	}
	return true;
}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(std::string const &literal)
{
	std::string toChar = "";
	int		toInt = 0;
	float	toFloat = 0;
	double	toDouble = 0;

	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return;
	}
	toInt = std::atoi(literal.c_str());

	toFloat = std::atof(literal.c_str());
	toDouble = static_cast<double>(toFloat);

	if (isPseudoLiteral(literal) || toInt > 255 || toInt < 0)
	{
		toChar = "impossible";
	}

	if (toInt > 0 && toChar == "" && toInt <= 255 && toInt >= 0 && isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar != "impossible")
	{
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	if (toDouble < -2147483648 || toDouble > 2147483647)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;

	if (toFloat - static_cast<int>(toFloat) == 0)
	{
		std::cout << "float: " << toFloat << ".0f" << std::endl;
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << toFloat << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	}
}
