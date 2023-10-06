/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/04 15:45:27 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat&	operator=(Bureaucrat const & b);
		~Bureaucrat();
		const std::string &	getName(void) const;
		unsigned int		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(void) const;
};

std::ostream&	operator<<(std::ostream & o, Bureaucrat & rhs);

#endif
