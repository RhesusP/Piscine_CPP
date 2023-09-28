/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:07:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/29 00:12:40 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
		
};

std::ostream&	operator<<(std::ostream & o, Bureaucrat & rhs);

#endif
