/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:01:04 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 12:17:36 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class FormAlreadySignedException : public std::exception {
	public:
		virtual const char*	what() const throw();
};

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_executeGrade;
	public:
		AForm(void);
		AForm(std::string name, unsigned int sign, unsigned int execute);
		AForm(AForm const & f);
		virtual ~AForm(void);
		AForm&				operator=(AForm const & rhs);

		const std::string &	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecuteGrade(void) const;

		void				beSigned(Bureaucrat const & b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream & o, AForm const & rhs);

#endif