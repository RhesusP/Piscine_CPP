/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:11:35 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 11:21:43 by cbernot          ###   ########.fr       */
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

		Fixed& operator=(Fixed const &rhs);

		bool operator>(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);

		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;

		Fixed& operator++(void);	//prefix increment
		Fixed operator++(int);		//postfix increment
		Fixed& operator--(void);	//prefix decrement
		Fixed operator--(int);		//postfix decrement

		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static const Fixed &min(Fixed const &lhs, Fixed const &rhs);
		
		static Fixed &max(Fixed &lhs, Fixed &rhs);
		static const Fixed &max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream & operator<<(std::ostream & o, Fixed const &rhs);