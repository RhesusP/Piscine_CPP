/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:06:02 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:27:49 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	_type = "default amateria";
}

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::AMateria(AMateria const & m) {
	*this = m;
}

AMateria&	AMateria::operator=(AMateria const & rhs) {
	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria(void) {}

std::string const & AMateria::getType(void) const {
	return (this->_type);
}

AMateria*	AMateria::clone(void) const {
	return (AMateria*)this;

}
void	AMateria::use(ICharacter& target) {
	std::cout << "AMateria (type: " << _type << ") used on " << target.getName() << std::endl; 
}