/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:17:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/09 16:48:15 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

Array::Array(void) {
	_size = 0;
	_array = new T [0];
}

Array::Array(unsigned int size) {
	_size = size;
	_array = new T [size];
}

Array::Array(Array const & a) {
	*this = a;
}

Array&	Array::operator=(Array const & rhs) {
	this->_size = rhs.size();
	this->_array = new T [_size];
	for (unsigned int i = 0 ; i < rhs.size() ; i++) {
		this->_array[i] = rhs->_array[i];
	}
	return *this;
}

<T>&	Array::operator[](unsigned int index) const {
	if (index > _size)
		throw IndexOutOfBoundsException();
	return this->_array[index];
}

Array::~Array(void) {
	delete [] _array;
}

unsigned int	Array::size(void) const {
	return _size;
}
