/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:21:40 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 17:46:42 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & f);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & rhs);

		const std::string &	getTarget(void) const;
		void				execute(Bureaucrat const & executor) const;
};

#endif