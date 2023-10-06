/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:26:28 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/04 15:44:21 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << this << "created" << std::endl;
}

Form::Form(std::string name, unsigned int sign, unsigned int execute) : _name(name), _isSigned(false), _signGrade(sign), _executeGrade(execute) {
	if (sign < 1  || execute < 1) {
		throw GradeTooHighException();
	}
	else if (sign > 150 || execute > 150) {
		throw GradeTooLowException();
	}
	std::cout << this << "created" << std::endl;
}

Form::~Form(void) {
	std::cout << this << "destroyed" << std::endl;
}

const std::string &	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

const unsigned int	Form::getSignGrade(void) const {
	return (_signGrade);
}

const unsigned int	Form::getExecuteGrade(void) const {
	return (_executeGrade);
}

void	Form::beSigned(Bureaucrat b) {
	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream & o, Form const & rhs) { 
	o << "Form " << rhs.getName() << ":" << std::endl;
	o << "\t- is signed: " << (rhs.getIsSigned() ? "true" : "false") << std::endl;
	o << "\t- Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "\t- Grade to execute: " << rhs.getExecuteGrade() << std::endl;
	return o;
}
