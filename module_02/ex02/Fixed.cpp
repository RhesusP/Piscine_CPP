/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:27:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/27 21:35:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_bits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(n * (1 << this->_bits));
}

Fixed::Fixed(Fixed const &rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_bits);
}

int	Fixed::toInt(void) const {
	return (this->_value >> this->_bits);
}

Fixed& Fixed::operator=(Fixed const & rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const &rhs) {
	o << rhs.toFloat();
	return (o);
}

bool operator>(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool operator<(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool operator>=(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool operator<=(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool operator==(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool operator!=(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}