/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:24:06 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 17:51:10 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("none") {
	std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & f) {
	*this = f;
	std::cout << "ShrubberyCreationForm " << this->getName() << " created by copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { 
	std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	_target = rhs.getTarget();
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	if (this->getIsSigned()) {
		throw FormAlreadySignedException();
		return ;
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw GradeTooLowException();
		return ;
	}
	std::ofstream outfile(_target + "_shrubbery");
	outfile << 
"               ,@@@@@@@," << std::endl <<
"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
"       |o|        | |         | |" << std::endl <<
"       |.|        | |         | |" << std::endl <<
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	outfile.close();
}
