/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:56:30 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/28 13:07:03 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class NotFoundException : public std::exception {
	public: 
		virtual const char*	what() const throw() {
			return ("not found 🙃");
		}		
};

template<typename T>
typename T::iterator	easyfind(T t, int n) {
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif
