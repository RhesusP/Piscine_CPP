/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:46 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:16:21 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(Brain const & b);
		~Brain(void);
		std::string*	getIdeas(void);
		void			setIdeas(std::string ideas);
		std::string		getIdea(int index);
		void			setIdea(std::string idea, int index);
		Brain&	operator=(Brain const & rhs);
};

std::ostream&	operator<<(std::ostream& o, Brain& rhs);

#endif
