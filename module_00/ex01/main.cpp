/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:17:06 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/02 20:46:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1) {
		std::cout << ">> ";
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}