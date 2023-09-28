/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:12:47 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/29 00:48:41 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	std::cout << "Bureaucrat " << _name << "(" << _grade << ") created." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << _name << "(" << _grade << ") destroyed." << std::endl;
}
