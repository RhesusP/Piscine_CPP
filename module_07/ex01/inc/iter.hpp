/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:50:25 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/28 08:04:21 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T* array, size_t len, void(*f)(T)) {
	if (len <= 0)
		return ;
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif
