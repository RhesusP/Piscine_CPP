/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:26:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/17 14:27:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>

class PmergeMe
{
private:
	/* data */
public:
	PmergeMe(void);
	PmergeMe(PmergeMe &p);
	PmergeMe &operator=(PmergeMe &rhs);
	~PmergeMe();
};

#endif