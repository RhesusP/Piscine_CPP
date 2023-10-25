/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 16:40:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int	main(void) {
	Bureaucrat	tom("Tom", 1);
	Bureaucrat	luc("Luc", 150);


	std::cout << std::endl << "============ Shrubbery Success ✅ ============" << std::endl;
	try {
		ShrubberyCreationForm	s("target");
		tom.executeForm(s);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Robotomy Success ✅ ============" << std::endl;
	try {
		RobotomyRequestForm	r("maybe");
		RobotomyRequestForm	r1("maybe not");
		RobotomyRequestForm	r2("maybe maybe");
		tom.executeForm(r);
		tom.executeForm(r1);
		tom.executeForm(r2);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Presidential Pardon Success ✅ ============" << std::endl;
	try {
		PresidentialPardonForm	p("target");
		tom.executeForm(p);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Shrubbery Grade Too Low ❌ ============" << std::endl;
	try {
		ShrubberyCreationForm	s("target");
		luc.executeForm(s);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "============ Robotomy Grade Too Low ❌ ============" << std::endl;
	try {
		RobotomyRequestForm	r("maybe");
		luc.executeForm(r);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Presidential Pardon Grade Too Low ❌ ============" << std::endl;
	try {
		PresidentialPardonForm	p("target");
		luc.executeForm(p);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "============ Shrubbery Form Already Sign ❌ ============" << std::endl;
	try {
		ShrubberyCreationForm	s("target");
		tom.signForm(s);
		tom.executeForm(s);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Robotomy Grade Too Low ❌ ============" << std::endl;
	try {
		RobotomyRequestForm	r("maybe");
		tom.signForm(r);
		tom.executeForm(r);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "============ Presidential Pardon Grade Too Low ❌ ============" << std::endl;
	try {
		PresidentialPardonForm	p("target");
		tom.signForm(p);
		tom.executeForm(p);
	}
	catch (std::exception	& e) {
		std::cout << "error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return (0);
}
