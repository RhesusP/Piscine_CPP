/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:50:25 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/29 13:24:26 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename U>
void	iter(T* array, U len, void(*f)(T &)) {
	if (len <= 0 || !array || !f)
		return ;
	for (U i = 0; i < len; i++) {
		f(array[i]);
	}
}

template<typename T, typename U>
void	iter(const T* array, U len, void(*f)(const T &)) {
	if (len <= 0 || !array || !f)
		return ;
	for (U i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif