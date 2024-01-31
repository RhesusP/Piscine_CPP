/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:51 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/31 21:09:22 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

const char *BadParameterException::what() const throw()
{
	return "Bad parameter";
}

/**
 * @brief Converts a string to an unsigned integer
 *
 * @param str The unsigned integer representation of the input string
 * @return unsigned int
 */
unsigned int stoul(std::string str)
{
	unsigned int u;
	std::istringstream(str) >> u;
	return (u);
}

// ==============================
// = Sorting Functions
// ==============================

/**
 * @brief Sorts a list of unsigned integers using the Ford-Johnson algorithm.
 *
 * @param list The list of unsigned integers to be sorted
 * @return std::list<unsigned int>& The sorted list of unsigned integers.
 */
std::list<unsigned int> &ListFordJohnsonSort(std::list<unsigned int> &list)
{
	if (list.size() <= 1)
		return list;

	std::list<unsigned int> odd, even;
	std::list<unsigned int>::iterator it_begin = list.begin();
	std::list<unsigned int>::iterator it_end = list.end();
	int i = 0;

	while (it_begin != it_end)
	{
		if (i % 2 == 0)
			odd.push_back(*it_begin);
		else
			even.push_back(*it_begin);
		i++;
		++it_begin;
	}

	ListFordJohnsonSort(odd);
	ListFordJohnsonSort(even);

	list.clear();
	std::list<unsigned int>::iterator it_odd_begin = odd.begin();
	std::list<unsigned int>::iterator it_odd_end = odd.end();
	std::list<unsigned int>::iterator it_even_begin = even.begin();
	std::list<unsigned int>::iterator it_even_end = even.end();

	while (it_odd_begin != it_odd_end && it_even_begin != it_even_end)
	{
		if (*it_odd_begin < *it_even_begin)
		{
			list.push_back(*it_odd_begin);
			++it_odd_begin;
		}
		else
		{
			list.push_back(*it_even_begin);
			++it_even_begin;
		}
	}

	list.insert(list.end(), it_odd_begin, odd.end());
	list.insert(list.end(), it_even_begin, even.end());

	return list;
}

/**
 * @brief Sorts a vector of unsigned integers using the Ford-Johnson algorithm.
 *
 * @param vector The vector of unsigned integers to be sorted
 * @return std::vector<unsigned int>& The sorted list of unsigned integers.
 */
std::vector<unsigned int> &VectorFordJohnsonSort(std::vector<unsigned int> &vector)
{
	if (vector.size() <= 1)
		return vector;

	std::vector<unsigned int> odd, even;

	for (size_t i = 0; i < vector.size(); i++)
	{
		if (i % 2 == 0)
			odd.push_back(vector[i]);
		else
			even.push_back(vector[i]);
	}

	VectorFordJohnsonSort(odd);
	VectorFordJohnsonSort(even);

	vector.clear();

	size_t i = 0;
	size_t j = 0;

	while (i < odd.size() && j < even.size())
	{
		if (odd[i] < even[j])
		{
			vector.push_back(odd[i]);
			i++;
		}
		else
		{
			vector.push_back(even[j]);
			j++;
		}
	}

	while (i < odd.size())
	{
		vector.push_back(odd[i]);
		i++;
	}

	while (j < even.size())
	{
		vector.push_back(even[j]);
		j++;
	}

	return vector;
}

// ==============================
// = PmergeMe Class Functions
// ==============================

/**
 * @brief Constructs PmergeMe object by converting an array of char* to unsigned integer and storing them in a vector and a list
 *
 * @param tab An array of char* to be converted to unsigned integers
 * @param size
 * @throws BadParameterException if a string is not a positive integer or is more than INT_MAX
 */
PmergeMe::PmergeMe(char **tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::string str(tab[i]);
		if (str.size() > 10)
		{
			std::cerr << "case 1" << std::endl;
			throw BadParameterException();
		}
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!isdigit(str[j]))
			{
				std::cerr << "case 2" << std::endl;
				throw BadParameterException();
			}
		}
		unsigned int u = ::stoul(str);
		_vector.push_back(u);
		_list.push_back(u);
	}
}

/**
 * @brief Destroy a PmergeMe object by clearing its vector and list
 *
 */
PmergeMe::~PmergeMe(void)
{
	_vector.clear();
	_list.clear();
}

/**
 * @brief Sorts the internal std::list and std::vector using Ford-Johnson algorithm and measures execution time.
 *
 */
void PmergeMe::sort(void)
{
	std::cout << "Before : " << _list << std::endl;

	clock_t startL = clock();
	ListFordJohnsonSort(this->_list);
	clock_t endL = clock();
	double durationL = static_cast<double>(endL - startL) / static_cast<double>CLOCKS_PER_SEC * 100000;

	clock_t startV = clock();
	VectorFordJohnsonSort(this->_vector);
	clock_t endV = clock();
	double durationV = static_cast<double>(endV - startV) / static_cast<double>CLOCKS_PER_SEC * 100000;

	std::cout << "After : " << _vector << std::endl;

	std::cout << "Time to process a range of " << _list.size() << " element with std::list : " << durationL << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << _vector.size() << " element with std::vector : " << durationV << " microseconds" << std::endl;
}

// ===================================
// = Output stream Overload Functions
// ===================================

/**
 * @brief Overloads the << operator for std::list<unsigned list> to print the list to an output stream
 *
 * @param o The output stream to print to
 * @param rhs The list of unsigned integer to print
 * @return std::ostream& The output stream
 */
std::ostream &operator<<(std::ostream &o, std::list<unsigned int> &rhs)
{
	std::list<unsigned int>::iterator it_begin = rhs.begin();
	std::list<unsigned int>::iterator it_end = rhs.end();

	while (it_begin != it_end)
	{
		std::cout << *it_begin << " ";
		++it_begin;
	}
	return (o);
}

/**
 * @brief Overloads the << operator for std::vector<unsigned list> to print the list to an output stream
 *
 * @param o The output stream to print to
 * @param rhs The vector of unsigned integer to print
 * @return std::ostream& The output stream
 */
std::ostream &operator<<(std::ostream &o, std::vector<unsigned int> &rhs)
{
	std::vector<unsigned int>::iterator it_begin = rhs.begin();
	std::vector<unsigned int>::iterator it_end = rhs.end();

	while (it_begin != it_end)
	{
		std::cout << *it_begin << " ";
		++it_begin;
	}
	return (o);
}
