/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:39:09 by cbernot           #+#    #+#             */
/*   Updated: 2023/12/20 10:06:51 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	
	iterator begin(void) {
		return this->c.begin();
	}

	iterator end(void) {
		return this->c.end();
	}

	const_iterator begin(void) const {
		return this->c.begin();
	}

	const_iterator end(void) const {
		return this->c.end();
	}
};

#endif