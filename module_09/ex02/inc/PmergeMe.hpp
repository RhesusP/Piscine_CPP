/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/26 11:15:39 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <stdlib.h>

class BadParameterException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class PmergeMe
{
private:
	std::deque<unsigned int> _deque;
	std::list<unsigned int> _list;

public:
	PmergeMe(void);
	PmergeMe(char** tab, int size);
	PmergeMe(PmergeMe &p);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();

	void	ListFordJohnsonSort(void);
	void	DequeFordJohnsonSort(void);
};

#endif