/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:11:44 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

// ==============================
// = Exceptions
// ==============================

const char *FileNotFoundException::what() const throw()
{
	return ("Cannot open file");
}

const char *BadDelimiterException::what() const throw()
{
	return ("Invalid delimiter");
}

const char *BadDateException::what() const throw()
{
	return ("Invalid Date");
}

// ==============================
// = Utils functions
// ==============================

/**
 * @brief Converts a string to an integer
 *
 * @param s The string to convert
 * @return int The integer representation of the string
 */
int stoi(std::string const &s)
{
	int i;
	std::istringstream(s) >> i;
	return i;
}

/**
 * @brief Checks if a string represents a valid date
 *
 * @param date The string to check
 * @return true if the string represents a valid date, false otherwise
 */
bool isDate(std::string date)
{
	if (date[4] != '-' && date[7] != '-' && date.size() != 10)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}
	int year = ::stoi(date.substr(0, 4));
	int month = ::stoi(date.substr(5, 2));
	int day = ::stoi(date.substr(8, 2));
	if (year < 1900 || year > 9999 || month < 1 || month > 12)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (month == 2)
	{
		if ((year - 1900) % 4 == 0 && (day < 1 || day > 29))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
		else if ((year - 1900) % 4 != 0 && (day < 1 || day > 28))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}
	return true;
}

// ==============================
// = BitcoinExchange Class functions
// ==============================

/**
 * @brief Construct a new BitcoinExchange object
 *
 * This constructor reads data from a CSV file named "data.csv". Each line in the file
 * should represent a date and a value, separated by a comma.
 * The date is checked for validity using the isDate function. If the date is valid, a
 * new entry is added to the _map member variable, with the date as the key and the
 * value as the value.
 * If the file cannot be opened, a FileNotFoundException is thrown.
 * If a line in the file does not contain a comma, a BadDelimiterException is thrown.
 */
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
			if (!isDate(date))
				continue;
			value = line.substr(delim + 1, line.length());
			_map.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
		file.close();
	}
}

/**
 * @brief Constructs a new BitcoinExchange object as a copy of an existing one.
 *
 * @param b The existing BitcoinExchange object to copy.
 */
BitcoinExchange::BitcoinExchange(BitcoinExchange &b)
{
	*this = b;
	(void)b;
}

/**
 * @brief Assigns values of one BitcoinExchange object to another
 *
 * @param rhs The right-hand side BitcoinExchange object
 * @return BitcoinExchange& A reference to the left-hand side BitcoinExchange object
 */
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

/**
 * @brief Prints the value of a given amount of Bitcoin on a given date.
 *
 * This function takes a date and a rate  as input. It then finds the value of Bitcoin on
 * the given date and multiplies it by the given rate to find the total value.
 * The function then prints the date, the rate, and the total value to the standard output.
 * The total value is printed with a fixed number of decimal places (2).
 *
 * @param date The date to find the value for
 * @param amount The amount of Bitcoin to find the value for
 */
void BitcoinExchange::printValue(std::string date, float amount)
{
	std::map<std::string, float>::iterator it = _map.lower_bound(date);	
	float value = 0.0f;
	
	if (it == _map.begin())
		value = _map.begin()->second;
	else if (it->first == date)
		value = it->second;
	else
		value = (--it)->second;
	 std::cout << date << " => " << amount << " = " << std::fixed << std::setprecision(2) << amount * value << std::endl;
}

// ===================================
// = Output stream overload functions
// ===================================

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
