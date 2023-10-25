/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:06:50 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 17:49:30 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("None") {
	std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & f) {
	*this = f;
	std::cout << "PresidentialPardonForm " << this->getName() << " created by copy constructor" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & f) {
	_target = f.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm " << this->getName() << " destroyed" << std::endl;
}

const std::string &	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned()) {
		throw FormAlreadySignedException();
		return ;
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw GradeTooLowException();
		return ;
	}
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}
