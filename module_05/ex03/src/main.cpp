/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 15:51:01 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int	main(void) {
	Intern		intern;
	Bureaucrat	john = Bureaucrat("John", 1);
	AForm		*form;

	std::cout << std::endl;

	std::cout << std::endl << "============ Shrubbery Success ✅ ============" << std::endl;
	try {
		form = intern.makeForm("shrubbery creation", "riri");
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	std::cout << std::endl << "============ Robotomy Success ✅ ============" << std::endl;
	try {
		form = intern.makeForm("robotomy request", "fifi");
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}


	std::cout << std::endl << "============ Presidential Pardon Success ✅ ============" << std::endl;
	try {
		form = intern.makeForm("presidential pardon", "loulou");
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Shrubbery Grade Too Low ❌ ============" << std::endl;
	try {
		form = intern.makeForm("nope", "riri");
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}
