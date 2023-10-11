/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:47:41 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 12:53:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("None") {
	std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & f) {
	*this = f;
	std::cout << "RobotomyRequestForm " << this->getName() << " created by copy constructor" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	_target = rhs.getTarget();
	return (*this);
}