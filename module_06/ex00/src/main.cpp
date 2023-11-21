/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:03:55 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/21 13:10:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Error: no parameter" << std::endl;
		return (1);
	}
	if (argc > 2) {
		std::cout << "Error: too many parameters" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
