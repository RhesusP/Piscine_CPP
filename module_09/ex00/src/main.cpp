/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:12 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/01 10:24:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

bool onlyDigit(std::string s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

float isRateOk(std::string rate)
{
	long double rateld = std::strtold(rate.c_str(), 0);
	float res = -1.0f;
	if (rateld < 0.0)
		std::cout << "Error: not a positive number => " << rate << std::endl;
	if (rateld > 1000.0)
		std::cout << "Error: too large a number => " << rate << std::endl;
	else
		res = (float)rateld;
	return res;
}

void getValue(BitcoinExchange *exchange, std::string line)
{
	size_t delimiter = line.find(" | ");
	if (delimiter == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, delimiter);
	std::string rate = line.substr(delimiter + 3, line.length());
	float ratef = isRateOk(rate);
	if (isDate(date) && ratef >= 0)
	{
		exchange->printValue(date, ratef);
	}
}

void process_file(BitcoinExchange *exchange, char *file_path)
{
	std::string line;
	std::ifstream file(file_path);

	if (!file.is_open())
	{
		std::cerr << file_path << std::endl;
		throw FileNotFoundException();
	}
	else
	{
		getline(file, line);
		if (line != "date | value")
		{
			std::cerr << line << std::endl;
			throw BadDelimiterException();
		}
		while (getline(file, line))
			getValue(exchange, line);
		file.close();
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "⚠️  usage: './btc input.txt'" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange exchange;
		process_file(&exchange, argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}