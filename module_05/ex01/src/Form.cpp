/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:26:28 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 16:43:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

const char*	FormAlreadySignedException::what() const throw() {
	return ("Form is already signed.");
}

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
	std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::Form(Form const & f) : _name(f.getName()), _isSigned(f.getIsSigned()), _signGrade(f.getSignGrade()), _executeGrade(f.getExecuteGrade()) {
	std::cout << "Form " << this->_name << " created by copy constructor" << std::endl;
}

Form&	Form::operator=(Form const & f) {
	_isSigned = f.getIsSigned();
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

const std::string &	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

unsigned int	Form::getSignGrade(void) const {
	return (_signGrade);
}

unsigned int	Form::getExecuteGrade(void) const {
	return (_executeGrade);
}

void	Form::beSigned(Bureaucrat const & b) {
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

std::ostream&	operator<<(std::ostream & o, Form const & rhs) { 
	o << "Form " << rhs.getName() << ":" << std::endl;
	o << "\t- is signed: " << (rhs.getIsSigned() ? "true" : "false") << std::endl;
	o << "\t- Grade to sign: " << rhs.getSignGrade() << std::endl;
	o << "\t- Grade to execute: " << rhs.getExecuteGrade() << std::endl;
	return o;
}
