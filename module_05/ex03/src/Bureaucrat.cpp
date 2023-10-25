/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:12:47 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 15:40:31 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

const char*	GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char*	GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	std::cout << "Bureaucrat " << _name << "(" << _grade << ") created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Bureaucrat " << _name << "(" << _grade << ") created." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << _name << "(" << _grade << ") destroyed." << std::endl;
}

const std::string & Bureaucrat::getName(void) const {
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm & f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << "." << std::endl;
	}
	catch (std::exception & e) {
		std::cout << _name << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << _name << " executed a " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Bureaucrat " << _name << " failed to executed a " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream & o, Bureaucrat & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
