/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:14:28 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/06 21:56:51 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T*		_array;
		size_t	_len;
	public:
		Array(void) {
			_len = 0;
			_array = [];
		}
		Array(unsigned int n);	//creates a n-len array;
		Array(Array const & a);
		Array&	operator=(Array const & a);
		Array&	operator[](unsigned int) const;
		
		unsigned int	size(void) const;

};

#endif