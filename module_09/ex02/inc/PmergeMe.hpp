/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/31 20:56:05 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <ctime>

class BadParameterException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class PmergeMe
{
private:
	std::vector<unsigned int> _vector;
	std::list<unsigned int> _list;

public:
	PmergeMe(void);
	PmergeMe(char **tab, int size);
	PmergeMe(PmergeMe &p);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();

	void sort(void);
};

#endif

std::ostream &operator<<(std::ostream &o, std::list<unsigned int> &rhs);
std::ostream &operator<<(std::ostream &o, std::vector<unsigned int> &rhs);