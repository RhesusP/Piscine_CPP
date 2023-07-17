/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:41:05 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/05 12:50:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(void) {
	std::string myStr = "HI THIS IS BRAIN";
	std::string	*strPtr = &myStr;
	std::string	&strRef = myStr;

	std::cout << "string address:\t\t" << &myStr << std::endl;
	std::cout << "address stored in ptr:\t" << strPtr << std::endl;
	std::cout << "address stored in ref:\t" << &strRef << std::endl;

	std::cout << std::endl;

	std::cout << "string:\t\t\t" << myStr << std::endl;
	std::cout << "ptr:\t\t\t" << *strPtr << std::endl;
	std::cout << "ref:\t\t\t" << strRef << std::endl;

	return (0);
}
