/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:19:47 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/04 15:41:09 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class GradeTooLowException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
	public:
		Form(void);
		Form(std::string name, unsigned int sign, unsigned int execute);
		Form(Form const & f);
		~Form(void);
		Form&	operator=(Form const & rhs);

		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		const unsigned int	getSignGrade(void) const;
		const unsigned int	getExecuteGrade(void) const;

		void	beSigned(Bureaucrat b);
};

std::ostream&	operator<<(std::ostream & o, Form const & rhs);

#endif