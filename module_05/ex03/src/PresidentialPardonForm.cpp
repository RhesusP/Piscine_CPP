/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:06:50 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 15:40:48 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("None") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & f) {
	*this = f;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & f) {
	_target = f.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

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
