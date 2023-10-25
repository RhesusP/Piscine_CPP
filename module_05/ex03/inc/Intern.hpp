/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:11:05 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/25 15:26:36 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# define UNUSED(x) (void)(x)

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class FormNameDoesNotExist : public std::exception {
	public:
		virtual const char* what() const throw();
};

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & i);
		~Intern(void);
		Intern&	operator=(Intern const & rhs);
		AForm*	makeForm(std::string name, std::string target);
};

#endif