/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:50:17 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 13:02:06 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Calculate the cross product of two vectors
 * @details If we consider two vectors AB and CD, we calculate the cross product of AB and AD with the formula :
 * AB x AD = (xb - xa) * (yd - yc) - (xd - xc) * (yb - ya)
 * @param a (xa, ya)
 * @param b (xb, yb)
 * @param c (xc, yc)
 * @param d (xd, yd)
 * @return Fixed 
 */
Fixed	crossProduct(Point a, Point b, Point c, Point d) {
	Fixed cp = (b.getX() - a.getX()) * (d.getY() - c.getY()) - (d.getX() - c.getX()) * (b.getY() - a.getY());
	return (cp);
}

/**
 * @brief Check if a point is inside a triangle
 * @details We use the barycentric coordinate system to check if a point is inside a triangle. If we consider 
 * a triangle ABC and a point P, we calculate the cross product of AP and AB, BP and BC, CP and CA. If the three
 * cross products have the same sign, the point is inside the triangle.
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @return true if the point is inside the triangle
 * @return false if the point is outside the triangle
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	cp_apab = crossProduct(a, point, a, b);
	Fixed	cp_bpbc = crossProduct(b, point, b, c);
	Fixed	cp_cpca = crossProduct(c, point, c, a);
	if ((cp_apab > 0 && cp_bpbc > 0 && cp_cpca > 0) || (cp_apab < 0 && cp_bpbc < 0 && cp_cpca < 0) )
		return (true);
	return (false);
}
