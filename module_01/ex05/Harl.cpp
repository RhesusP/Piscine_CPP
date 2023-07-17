/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:36:36 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/17 14:54:19 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*f_debug)(void) = &Harl::debug;
	void	(Harl::*f_info)(void) = &Harl::info;
	void	(Harl::*f_warning)(void) = &Harl::warning;
	void	(Harl::*f_error)(void) = &Harl::error;

	void	(Harl::*f[4])(void) = {f_debug, f_info, f_warning, f_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			(this->*f[i])();
	}
}
