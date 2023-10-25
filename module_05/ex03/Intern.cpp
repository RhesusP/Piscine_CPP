/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 12:51:34 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*	FormNameDoesNotExist::what() const throw() {
	return ("Form name does not exist");
}

Intern::Intern(void) {
	std::cout << "An Intern has been created" << std::endl;
}

Intern::Intern(Intern const & i) {
	*this = i;
}

Intern&	Intern::operator=(Intern const & rhs) {
	UNUSED(rhs);
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "An Intern has been destroyed" << std::endl;
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	void	(PresidentialPardonForm::*presidential)(std::string target);
	void	(RobotomyRequestForm::*robotomy)(std::string target);
	void	(ShrubberyCreationForm::*shrubbery)(std::string target);

	void	(void::*constructors[3])(std::string) = {presidential, robotomy, shrubbery};
	std::string	targets[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	std::cout << "make " << name << " with " << target << " as target" << std::endl;
	


	return (0);
}