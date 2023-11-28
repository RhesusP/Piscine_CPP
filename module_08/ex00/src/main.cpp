/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:59:51 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/28 13:06:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <string.h>
#include <list>
#include <vector>

#define MAX_VAL 10 

int	main(void) {
	std::list<int>	list;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i;
        list.push_back(value);
    }

	std::cout << "============ int list ============" << std::endl;
	std::list<int>::iterator it_begin = list.begin();
	std::list<int>::iterator it_end = list.end();
	while (it_begin != it_end) {
		std::cout << *it_begin << std::endl;
		++it_begin;
	}
	std::cout << std::endl << "searching 5 in the list..." << std::endl;
	try {
		std::cout << *easyfind(list, 5) << " found" << std::endl;;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "searching 10 in the list..." << std::endl;
	try {
		std::cout << *easyfind(list, 10) << " found" << std::endl;;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	vector;
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i;
        vector.push_back(value);
    }
	std::cout << "============ int vector ============" << std::endl;
	std::vector<int>::iterator it_begin_vec = vector.begin();
	std::vector<int>::iterator it_end_vec = vector.end();
	while (it_begin_vec != it_end_vec) {
		std::cout << *it_begin_vec << std::endl;
		++it_begin_vec;
	}
	std::cout << std::endl << "searching 2 in the vector..." << std::endl;
	try {
		std::cout << *easyfind(vector, 2) << " found" << std::endl;;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "searching -2 in the vector..." << std::endl;
	try {
		std::cout << *easyfind(vector, -2) << " found" << std::endl;;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}