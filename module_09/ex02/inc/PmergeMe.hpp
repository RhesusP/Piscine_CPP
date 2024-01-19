/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/19 11:49:03 by cbernot          ###   ########.fr       */
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

class BadParameterException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class PmergeMe
{
private:
	/* data */
public:
	PmergeMe(void);
	PmergeMe(int *array);
	PmergeMe(PmergeMe &p);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();
};

#endif