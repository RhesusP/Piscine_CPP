/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:05:35 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/01 10:24:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <map>

class FileNotFoundException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class BadDelimiterException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class BadDateException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class BitcoinExchange
{
private:
	std::map<std::string, float> _map;

public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange &b);
	BitcoinExchange &operator=(BitcoinExchange &rhs);
	~BitcoinExchange(void);
	std::map<std::string, float> getMap(void) const;
	void map_insert(std::pair<std::string, float> pair);
	void printValue(std::string date, float rate);
};

bool isDate(std::string date);
std::ostream &operator<<(std::ostream &o, BitcoinExchange &rhs);

#endif