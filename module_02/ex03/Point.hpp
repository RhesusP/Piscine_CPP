/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:27:33 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 15:46:17 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(Point const &p);
		~Point();
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
		Point& operator=(Point const &rhs);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
