/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:51:09 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/11 11:10:49 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

const char *NotEnoughNumbersException::what(void) const throw()
{
	return ("⚠️  Not enough number to perform this operation");
}

const char *FilledListException::what(void) const throw()
{
	return ("⚠️  List cannot accept new numbers");
}

Span::Span(void)
{
	_n = 0;
	std::cout << "default constructor with size << " << _list.size() << std::endl;
}

Span::Span(unsigned int n)
{
	_n = n;
}

Span::Span(Span const &s)
{
	*this = s;
}

Span &Span::operator=(Span const &rhs)
{
	_n = rhs.size();
	_list.clear();
	_list = std::list<int>(rhs.getList());
	return *this;
}

Span::~Span(void)
{
	_n = 0;
	_list.clear();
}

void Span::addNumber(int number)
{
	if (_list.size() < _n)
	{
		_list.push_back(number);
	}
	else
	{
		throw FilledListException();
	}
}

void Span::fill(std::list<int>::iterator begin, std::list<int>::iterator end, int value)
{
	while (begin != end)
	{
		*begin = value;
		++begin;
	}
}

void Span::fillRandomNumbers(void)
{
	if (_n == 0)
	{
		throw NotEnoughNumbersException();
	}
	srand(time(NULL));
	_list.clear();
	for (unsigned int i = 0; i < _n; i++)
	{
		int value = rand();
		_list.push_back(value);
	}
}

std::list<int> Span::getList(void) const
{
	return _list;
}

unsigned int Span::size(void) const
{
	return _n;
}

unsigned int Span::shortestSpan(void)
{
	if (_n < 2)
		throw NotEnoughNumbersException();
	std::list<int> copy = std::list<int>(_list);
	std::list<int>::iterator it_begin = copy.begin();
	std::list<int>::iterator it_end = copy.end();
	unsigned int distance = UINT_MAX;
	unsigned int new_dist;
	int prev = *it_begin;
	int curr;
	++it_begin;
	while (it_begin != it_end)
	{
		curr = *it_begin;
		new_dist = abs(curr - prev);
		if (new_dist < distance)
		{
			distance = new_dist;
		}
		prev = *it_begin;
		++it_begin;
	}
	return (distance);
}

unsigned int Span::longestSpan(void)
{
	if (_n < 2)
		throw NotEnoughNumbersException();
	std::list<int> copy = std::list<int>(_list);
	std::list<int>::iterator it_begin = copy.begin();
	std::list<int>::iterator it_end = copy.end();
	unsigned int distance = 0;
	unsigned int new_dist;
	int prev = *it_begin;
	++it_begin;
	int curr;
	while (it_begin != it_end)
	{
		curr = *it_begin;
		new_dist = abs(curr - prev);
		if (new_dist > distance)
		{
			distance = new_dist;
		}
		prev = *it_begin;
		++it_begin;
	}
	return (distance);
}

std::ostream &operator<<(std::ostream &o, Span const &rhs)
{
	std::list<int> list = rhs.getList();
	std::list<int>::iterator it_begin = list.begin();
	std::list<int>::iterator it_end = list.end();
	while (it_begin != it_end)
	{
		o << *it_begin << std::endl;
		++it_begin;
	}
	return (o);
}
