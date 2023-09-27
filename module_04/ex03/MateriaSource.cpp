/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:40:26 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/27 11:28:11 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & m) {
	*this = m;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i]) {
			delete _materias[i];
		}
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & rhs) {
	for (int i = 0; i < 4; i++) {
		this->_materias[i] = rhs._materias[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource is full. AMateria deleted" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return (_materias[i]->clone());
		}
	}
	return (NULL);
}

AMateria*	MateriaSource::getMateria(int idx) const {
	if (idx >= 0 && idx <= 3 && _materias[idx]) {
		return (_materias[idx]);
	} else {
		return (NULL);
	}
}

std::ostream&	operator<<(std::ostream& o, MateriaSource& rhs) {
	AMateria	*tmp;
	for (int i = 0; i < 4; i++) {
		tmp = rhs.getMateria(i);
		if (tmp) {
			o << "[" << i << "]: " << tmp->getType() << std::endl;
		}
		else {
			o << "[" << i << "]: null" << std::endl;
		}
	}
	return (o);
}

