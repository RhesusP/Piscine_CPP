/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:51 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/25 21:24:30 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

const char *BadParameterException::what() const throw()
{
	return "Bad parameter";
}

PmergeMe::PmergeMe(char** tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::string str(tab[i]);
		if (str.size() > 10)
		{
			std::cerr << "case 1" << std::endl;
			throw BadParameterException();
		}
		for (int j = 0; j < str.size() - 1; j++)
		{
			if (!isdigit(str[i]))
			{
				std::cerr << "case 2" << std::endl;
				throw BadParameterException();
			}
		}
		unsigned int u = stoul(str);
		std::cout << u << std::endl;
		_deque.push_back(u);
		_list.push_back(u);
	}
}

PmergeMe::~PmergeMe(void)
{
	_deque.clear();
	_list.clear();
}