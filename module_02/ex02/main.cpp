/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:10:23 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/28 11:24:51 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "------ My own tests ------" << std::endl;
	Fixed c(2);
	Fixed d(1024.42f);
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "d / c = " << d / c << std::endl;

	std::cout << "d++ = " << d++ << std::endl;
	std::cout << "d reset to 1024.42f" << std::endl;
	d = 1024.42f;
	std::cout << "++d = " << ++d << std::endl;

	std::cout << "d-- = " << d-- << std::endl;
	std::cout << "d reset to 1024.42f" << std::endl;
	d = 1024.42f;
	std::cout << "--d = " << --d << std::endl;

	std::cout << "d reset to 1024.42f" << std::endl;
	d = 1024.42f;
	std::cout << "min between c and d : " << Fixed::min(c, d) << std::endl;
	std::cout << "max between c and d : " << Fixed::max(c, d) << std::endl;

	return 0;
}
