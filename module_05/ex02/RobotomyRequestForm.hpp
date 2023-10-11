/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:45:58 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/11 12:49:46 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & f);
	~RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(RobotomyRequestForm const & rhs);

	const std::string &	getTarget(void) const;
	void				execute(Bureaucrat const & executor) const;
};

#endif
