/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:00:43 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 12:23:32 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char*	FormAlreadySignedException::what() const throw() {
	return ("Form is already signed.");
}

AForm::AForm(void) : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << this << "created" << std::endl;
}

AForm::AForm(std::string name, unsigned int sign, unsigned int execute) : _name(name), _isSigned(false), _signGrade(sign), _executeGrade(execute) {
	if (sign < 1  || execute < 1) {
		throw GradeTooHighException();
	}
	else if (sign > 150 || execute > 150) {
		throw GradeTooLowException();
	}
	std::cout << "AForm " << this->_name << " created" << std::endl;
}

AForm::AForm(AForm const & f) : _name(f.getName()), _isSigned(f.getIsSigned()), _signGrade(f.getSignGrade()), _executeGrade(f.getExecuteGrade()) {
	std::cout << "AForm " << this->_name << " created by copy constructor" << std::endl;
}

AForm&	AForm::operator=(AForm const & f) {
	_isSigned = f.getIsSigned();
	return (*this);
}

AForm::~AForm(void) {
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
}

const std::string &	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

unsigned int	AForm::getSignGrade(void) const {
	return (_signGrade);
}

unsigned int	AForm::getExecuteGrade(void) const {
	return (_executeGrade);
}

void	AForm::beSigned(Bureaucrat const & b) {
	if (_isSigned) {
		throw FormAlreadySignedException();
		return ;
	}
	else if (b.getGrade() > _signGrade) {
		throw GradeTooLowException();
		return ;
	}
	else {
		_isSigned = true;
	}
}

std::ostream&	operator<<(std::ostream & o, AForm const & rhs) { 
	o << "AForm " << rhs.getName() << ":" << std::endl;
	o << "\t- is signed: " << (rhs.getIsSigned() ? "true" : "false") << std::endl;
	o << "\t- Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "\t- Grade to execute: " << rhs.getExecuteGrade() << std::endl;
	return o;
}
