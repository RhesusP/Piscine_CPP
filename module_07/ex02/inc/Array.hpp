/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:08:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/08 15:20:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

class IndexOutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw();
}

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_array;
	public:
		Array(void);
		Array(unsigned int size);
		Array(Array const & a);
		Array&	operator=(Array const & rhs);
		<T>&	operator[](unsigned int index) const;
		~Array(void);

		unsigned int	size(void) const;
};

#endif