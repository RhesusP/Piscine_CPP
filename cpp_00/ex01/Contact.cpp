/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:12:33 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 10:34:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* ------------- CONSTRUCTOR AND DESTRUCTOR ------------- */
Contact::Contact()
{
	std::cout << "Contact created" << std::endl;
	_firstname = "";
	_lastname = "";
	_nickname = "";
	_phonenumber = "";
	_darkestsecret = "";
	_last_update = 0;
}

Contact::~Contact()
{
	std::cout << "Contact deleted" << std::endl;
}

/* ------------- GETTERS ------------- */
std::string	Contact::get_firstname(void)
{
	return (this->_firstname);
}

std::string	Contact::get_lastname(void)
{
	return (this->_lastname);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string	Contact::get_phonenumber(void)
{
	return (this->_phonenumber);
}

std::string	Contact::get_darkestsecret(void)
{
	return (this->_darkestsecret);
}

std::time_t	Contact::get_last_update(void)
{
	return (this->_last_update);
}

/* ------------- SETTERS ------------- */
int	Contact::set_firstname(std::string firstname)
{
	if (!firstname.size())
		return (0);
	this->_firstname = firstname;
	return (1);
}

int	Contact::set_lastname(std::string lastname)
{
	if (!lastname.size())
		return (0);
	this->_lastname = lastname;
	return (1);
}

int	Contact::set_nickname(std::string nickname)
{
	if (!nickname.size())
		return (0);
	this->_nickname = nickname;
	return (1);
}

int	Contact::set_phonenumber(std::string phonenumber)
{
	if (!phonenumber.size())
		return (0);
	this->_phonenumber = phonenumber;
	return (1);
}

int	Contact::set_darkestsecret(std::string darkestsecret)
{
	if (!darkestsecret.size())
		return (0);
	this->_darkestsecret = darkestsecret;
	return (1);
}

void	Contact::set_last_update(std::time_t last_update)
{
	this->_last_update = last_update;
}

/* ------------- DISPLAY ------------- */
void	Contact::print(void) {
	std::cout << "First name: " << this->_firstname << std::endl;
	std::cout << "Last name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestsecret << std::endl;
}
