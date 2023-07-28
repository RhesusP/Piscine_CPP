/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:27:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 12:18:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <cmath>

/* --------- Constructors and destructor --------- */
Fixed::Fixed(void) {
	this->_value = 0;
}

Fixed::Fixed(const int n) {
	this->_value = n << this->_bits;
}

Fixed::Fixed(const float n) {
	this->_value = roundf(n * (1 << this->_bits));
}

Fixed::Fixed(Fixed const &rhs) {
	*this = rhs;
}

Fixed::~Fixed(void) { }

/* --------- Getter  and setter --------- */
int	Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/* --------- Converters --------- */
float	Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_bits);
}

int	Fixed::toInt(void) const {
	return (this->_value >> this->_bits);
}

/* --------- Comparison operators --------- */
bool	Fixed::operator>(Fixed const &rhs) {
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &rhs) {
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) {
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) {
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) {
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) {
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

/* --------- Arithmetic operators --------- */
Fixed	Fixed::operator+(Fixed const &rhs) const {
	Fixed	temp;
	temp._value = this->getRawBits() + rhs.getRawBits();
	return (temp);
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	Fixed	temp;
	temp._value = this->getRawBits() - rhs.getRawBits();
	return (temp);
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	Fixed	temp;
	temp._value = (this->getRawBits() * rhs.getRawBits()) >> this->_bits;
	return (temp);
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	Fixed	temp;
	temp._value = (this->getRawBits() << this->_bits) / rhs.getRawBits();
	return (temp);
}

Fixed& Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	++*this;
	return (temp);
}

Fixed& Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	--*this;
	return (temp);
}

/* --------- min / max functions --------- */
Fixed&	Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

/* --------- Overloaded operators --------- */
Fixed& Fixed::operator=(Fixed const & rhs) {
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const &rhs) {
	o << rhs.toFloat();
	return (o);
}
