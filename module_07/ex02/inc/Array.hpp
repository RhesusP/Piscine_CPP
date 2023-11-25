/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:08:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/25 14:00:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class IndexOutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("⚠️ Index out of bounds.");
		}
};

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_array;
	public:
		Array(void) {
			_size = 0;
			_array = new T [0];
		}

		Array(unsigned int size) {
			_size = size;
			_array = new T [size];
		}

		Array(Array const & a) {
			this->_array = NULL;
			*this = a;
		}

		Array&	operator=(Array const & rhs) {
			if (_array != NULL)
				delete [] _array;
			this->_size = rhs.size();
			this->_array = new T [_size];
			for (unsigned int i = 0 ; i < rhs.size() ; i++) {
				this->_array[i] = rhs._array[i];
			}
			return *this;
		}
		
		T&	operator[](unsigned int index) const {
			if (index > _size)
				throw IndexOutOfBoundsException();
			return this->_array[index];
		}
		
		~Array(void) {
			if (_array)
				delete [] _array;
		}

		unsigned int	size(void) const {
			return _size;
		}
};

#endif
