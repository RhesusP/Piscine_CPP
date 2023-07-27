/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:38:09 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/27 12:51:54 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
#include <iomanip>
#include <stdlib.h>
#include <typeinfo>

/* ------------- CONSTRUCTOR AND DESTRUCTOR ------------- */
PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook deleted" << std::endl;
}

/* ------------- COMMANDS ------------- */
void PhoneBook::add_contact() {
	std::string	input;
	Contact		*oldest;
	int			is_syntax_valid;

	std::cout << "#####################################################################" << std::endl;
	std::cout << "#                            ADD A CONTACT                          #" << std::endl;
	std::cout << "#####################################################################" << std::endl << std::endl;
	oldest = get_oldest_contact();
	oldest->set_last_update(std::time(NULL));
	is_syntax_valid = 0;
	while (!is_syntax_valid) {
		std::cout << "First name : ";
		std::cin >> input;
		is_syntax_valid = oldest->set_firstname(input);
	}
	is_syntax_valid = 0;
	while (!is_syntax_valid) {
		std::cout << "Last name : ";
		std::cin >> input;
		is_syntax_valid = oldest->set_lastname(input);
	}
	is_syntax_valid = 0;
	while (!is_syntax_valid) {
		std::cout << "Nickname : ";
		std::cin >> input;
		is_syntax_valid = oldest->set_nickname(input);
	}
	is_syntax_valid = 0;
	while (!is_syntax_valid) {
		std::cout << "Phone number : ";
		std::cin >> input;
		is_syntax_valid = oldest->set_phonenumber(input);
	}
	is_syntax_valid = 0;
	while (!is_syntax_valid) {
		std::cout << "Darkest secret : ";
		std::cin >> input;
		is_syntax_valid = oldest->set_darkestsecret(input);
	}
	std::cout << std::endl << "Contact added!" << std::endl << std::endl;
}

void	PhoneBook::search_contact() {
	std::string	index;
	int			is_syntax_valid;

	std::cout << "#####################################################################" << std::endl;
	std::cout << "#                             CONTACT LIST                          #" << std::endl;
	std::cout << "#####################################################################" << std::endl << std::endl;
	print_repertory();
	is_syntax_valid = -1;
	while (is_syntax_valid < 0)
	{
		std::cout << "Enter the contact index to display (or type EXIT to quit): ";
		std::cin >> index;
		if (index == "EXIT")
			return ;
		is_syntax_valid = check_input(index);
	}
	contacts[is_syntax_valid].print();
}

void PhoneBook::print_repertory(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0 ; i < 8 ; i++) {
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		if (contacts[i].get_firstname().size() > 10)
			std::cout << std::setw(10) << contacts[i].get_firstname().substr(0, 9) +  "." << "|";
		else
			std::cout << std::setw(10) <<  contacts[i].get_firstname() << "|";
		if (contacts[i].get_firstname().size() > 10)
			std::cout << std::setw(10) << contacts[i].get_lastname().substr(0, 9) +  "." << "|";
		else
			std::cout << std::setw(10) <<  contacts[i].get_lastname() << "|";
		if (contacts[i].get_firstname().size() > 10)
			std::cout << std::setw(10) << contacts[i].get_nickname().substr(0, 9) +  "." << "|";
		else
			std::cout << std::setw(10) <<  contacts[i].get_nickname() << "|";		
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}

/* ------------- UTILS ------------- */
Contact *PhoneBook::get_oldest_contact(void)
{
	Contact *oldest;
	
	if (contacts[0].get_last_update() == 0)
		return (&contacts[0]);
	oldest = &contacts[0];
	for (int i = 1 ; i < 8 ; i++) {
		if (contacts[i].get_last_update() == 0)
			return (&contacts[i]);
		if (contacts[i].get_last_update() < oldest->get_last_update())
			oldest = &contacts[i];
	}
	return (oldest);
}

int PhoneBook::check_input(std::string input) {
	int eger;

	for (unsigned int i = 0 ; i < input.size() ; i++) {
		if (!isdigit(input[i])) {
			std::cout << "Input is not an integer" << std::endl;
			return (-1);
		}
	}
	eger = atoi(input.c_str());
	if (eger < 0 || eger > 7) {
		std::cout << "Input is not a valid index" << std::endl;
		return (-1);
	}
	if (contacts[eger].get_last_update() == 0) {
		std::cout << "This contact doesn't exist" << std::endl;
		return (-1);
	}
	return (eger);
}
