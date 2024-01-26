/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:51 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/26 11:29:04 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

const char *BadParameterException::what() const throw()
{
	return "Bad parameter";
}

unsigned int	stoul(std::string str)
{
	unsigned int u;
	std::istringstream(str) >> u;
	return (u);
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
		for (size_t j = 0; j < str.size() - 1; j++)
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

void PmergeMe::ListFordJohnsonSort(void)
{
	size_t	list_size = _list.size();
	size_t	nb_sub_array = (list_size % 2) ? (list_size / 2) : list_size / 2 + 1;
	unsigned int tab[nb_sub_array][2];
	int j = 0;
	for (size_t i = 0; i < list_size; i+=2)



	for (size_t i = 0; i < list_size / 2; i++)
	{
		
	}
}