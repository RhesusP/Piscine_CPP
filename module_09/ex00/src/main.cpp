/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:12 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/14 11:47:04 by cbernot          ###   ########.fr       */
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
	float res = -1.0f;
	if (rate.size() == 0)
		return res;
	bool point_found = false;
	for (size_t i = 0 ; i < rate.size() ; i++)
	{
		if (rate[i] == '.' && !point_found)
			point_found = true;
		else if (rate[i] == '.' && point_found)
			return -1.0f;
		if (!isdigit(rate[i]) && rate[i] != '.')
			return -1.0f;
	}
	long double rateld = std::strtold(rate.c_str(), 0);
	if (rateld < 0.0)
	{
		std::cout << "Error: not a positive number => " << rate << std::endl;
		return -2.0f;
	}
	if (rateld > 1000.0)
	{
		std::cout << "Error: too large a number => " << rate << std::endl;
		return -2.0f;
	}
	else
		res = (float)rateld;
	return res;
}

void getValue(BitcoinExchange *exchange, std::string line)
{
	if (line.size() == 0)
		return ;
	size_t delimiter = line.find(" | ");
	if (delimiter == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, delimiter);
	std::string rate = line.substr(delimiter + 3, line.length());
	float ratef = isRateOk(rate);
	if (ratef == -1.0f)
	{
		std::cout << "Error: bad value => " << line << std::endl;
		return ;
	}
	if (isDate(date) && ratef >= 0.0f)
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