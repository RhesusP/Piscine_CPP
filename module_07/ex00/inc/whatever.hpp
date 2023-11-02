/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:09:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 18:36:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b) {
	T	temp	=	a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T a, T b) {
	return (a < b ? a : b);
}

template<typename T>
T	max(T a, T b) {
	return (a > b ? a : b);
}

#endif
