/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 13:21:35 by cbernot          ###   ########.fr       */
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
	AForm*	forms[] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};
	std::string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for (int i = 0; i < 3; i++) {
		if (names[i] == name)
			return (forms[i]);
	}
	return (0);
}