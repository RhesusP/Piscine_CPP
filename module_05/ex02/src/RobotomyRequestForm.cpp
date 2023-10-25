/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:47:41 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 16:40:31 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("None") {
	srand(time(0));
	std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	srand(time(0));
	std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & f) {
	*this = f;
	std::cout << "RobotomyRequestForm " << this->getName() << " created by copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm " << this->getName() << " destroyed" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	_target = rhs.getTarget();
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned()) {
		throw FormAlreadySignedException();
		return ;
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw GradeTooLowException();
		return ;
	}
	std::cout << "DDDDRRRRrrrRRRRRrrRrRrRRRR" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized" << std::endl;	
	} else {
		std::cout << "Robotomy failed :(" << std::endl;
	}
}
