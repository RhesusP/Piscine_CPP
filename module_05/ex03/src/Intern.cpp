/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:17:32 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 15:40:35 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

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

AForm*	Intern::makeForm(const std::string name, const std::string target) {
	AForm	*res = 0;
	int		idx = 0;
	AForm*	forms[] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};
	std::string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			idx = i;
			res = forms[i];
		}
	}
	if (res) {
		std::cout << "Intern creates \"" << name << "\" form" << std::endl;
		for (int i = 0 ; i < 3 ; i++) {
			if (i != idx)
				delete forms[i];
		}
	}
	else {
		for (int i = 0 ; i < 3 ; i++) {
			delete forms[i];
		}
		throw FormNameDoesNotExist();
	}
	return (res);
}
