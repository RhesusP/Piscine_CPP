/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:16:49 by cbernot           #+#    #+#             */
/*   Updated: 2023/09/01 11:16:29 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "A brain has been created." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "default idea";
	}
}

Brain::Brain(Brain const & b) {
	std::cout << "A brain has been created by copy constructor." << std::endl;
	*this = b;
}

Brain::~Brain(void) {
	std::cout << "Brain has been destroyed" << std::endl;
}

std::string*	Brain::getIdeas(void) {
	return (this->_ideas);
}

void	Brain::setIdeas(std::string ideas) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = ideas;
	}
}

std::string	Brain::getIdea(int index) {
	if (index < 0 || index >= 100) {
		return NULL;
	}
	return (this->_ideas[index]);
}

void	Brain::setIdea(std::string idea, int index) {
	if (index < 0 || index >= 100) {
		return ;
	}
	this->_ideas[index] = idea;
}

Brain&	Brain::operator=(Brain const &rhs) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream & o, Brain & rhs) {
	for (int i = 0; i < 100; i++) {
		o << rhs.getIdeas()[i] << std::endl;
	}
	return (o);
}