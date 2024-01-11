/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:15:12 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/12 00:25:47 by cbernot          ###   ########.fr       */
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

bool isDateOk(std::string date)
{
	std::stringstream ss(date);
	std::string elmt;
	int nb;
	int i = -1;
	while (!ss.eof())
	{
		i++;
		getline(ss, elmt, '-');
		if (!onlyDigit(elmt))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
		nb = std::atoi(elmt.c_str());
		if (i == 0 && elmt.length() == 4 && nb >= 0 && nb < 9999)
			continue;
		else if ((i == 1 || i == 2) && elmt.length() == 2 && nb > 0 && nb <= 12)
			continue;
		else
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
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
	int delimiter = line.find(" | ");
	std::string date = line.substr(0, delimiter);
	std::string rate = line.substr(delimiter + 3, line.length());
	float ratef = isRateOk(rate);
	if (isDateOk(date) && ratef >= 0)
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