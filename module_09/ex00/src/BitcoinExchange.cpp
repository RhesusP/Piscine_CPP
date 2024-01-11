/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:11:44 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/12 00:25:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

const char *FileNotFoundException::what() const throw()
{
	return ("Cannot open file");
}

const char *BadDelimiterException::what() const throw()
{
	return ("Invalid delimiter");
}

BitcoinExchange::BitcoinExchange(void)
{
	std::string line;
	std::ifstream file("data.csv");

	if (!file.is_open())
	{
		std::cerr << "data.csv" << std::endl;
		throw FileNotFoundException();
	}
	else
	{
		std::string date;
		std::string value;
		getline(file, line);
		while (getline(file, line))
		{
			size_t delim = line.find(',');
			if (delim == std::string::npos)
			{
				std::cerr << line << std::endl;
				throw BadDelimiterException();
			}
			date = line.substr(0, delim);
			value = line.substr(delim + 1, line.length());
			_map.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
		file.close();
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &b)
{
	*this = b;
	(void)b;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs)
{
	std::map<std::string, float>::iterator it_begin = _map.begin();
	std::map<std::string, float>::iterator it_end = _map.end();
	while (it_begin != it_end)
	{
		rhs.map_insert(std::pair<std::string, float>(it_begin->first, it_begin->second));
		++it_begin;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	_map.clear();
}

std::map<std::string, float> BitcoinExchange::getMap(void) const
{
	return _map;
}

void BitcoinExchange::map_insert(std::pair<std::string, float> pair)
{
	_map.insert(pair);
}

void BitcoinExchange::printValue(std::string date, float rate)
{
	std::map<std::string, float>::iterator it_begin = _map.begin();
	std::map<std::string, float>::iterator it_end = _map.end();
	std::map<std::string, float>::reverse_iterator it_2_last = _map.rbegin();
	float value = 0.0f;
	if (date <= it_begin->first)
		value = it_begin->second;
	if (date >= it_2_last->first)
		value = it_2_last->second;
	else
	{
		while (it_begin != it_end)
		{
			if (it_begin->first >= date)
			{
				value = it_begin->second;
				break;
			}
			++it_begin;
		}
	}
	std::cout << date << " => " << rate << " = " << std::fixed << std::setprecision(2) << rate * value << std::endl;
}

std::ostream &operator<<(std::ostream &o, BitcoinExchange &rhs)
{
	std::map<std::string, float> map = rhs.getMap();
	std::map<std::string, float>::iterator it_begin = map.begin();
	std::map<std::string, float>::iterator it_end = map.end();
	while (it_begin != it_end)
	{
		std::cout << it_begin->first << "," << std::setprecision(2) << std::fixed << it_begin->second << std::endl;
		++it_begin;
	}
	return o;
}
