/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:16:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:27:59 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice(void) {
	_type = "ice";
}

Ice::Ice(Ice const & i) {
	*this = i;
}

Ice::~Ice(void) {}

Ice&	Ice::operator=(Ice const & rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}
