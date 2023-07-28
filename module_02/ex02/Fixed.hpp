/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:11:35 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/27 21:36:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed & src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed & operator=(Fixed const &rhs);
};

bool operator>(Fixed const &lhs, Fixed const &rhs);
bool operator<(Fixed const &lhs, Fixed const &rhs);
bool operator>=(Fixed const &lhs, Fixed const &rhs);
bool operator<=(Fixed const &lhs, Fixed const &rhs);
bool operator==(Fixed const &lhs, Fixed const &rhs);
bool operator!=(Fixed const &lhs, Fixed const &rhs);

std::ostream & operator<<(std::ostream & o, Fixed const &rhs);