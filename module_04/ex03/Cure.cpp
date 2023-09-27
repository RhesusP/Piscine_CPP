/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:14:43 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:27:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	_type = "cure";
}

Cure::Cure(Cure const & c) {
	*this = c;
}

Cure::~Cure(void) {}

Cure&	Cure::operator=(Cure const & rhs) {
	this->_type = rhs._type;
	return (*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}
