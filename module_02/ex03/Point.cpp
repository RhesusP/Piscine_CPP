/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:31:22 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 12:18:43 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) { }

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) { }

Point::Point(Point const &p) : _x(p._x), _y(p._y) { }

Point::~Point(void) { }

Fixed const	Point::getX(void) const {
	return (this->_x);
}

Fixed const	Point::getY(void) const {
	return (this->_y);
}

Point&	Point::operator=(Point const &rhs) {
	(Fixed)this->_x = rhs.getX();
	(Fixed)this->_y = rhs.getY();
	return (*this);
}
