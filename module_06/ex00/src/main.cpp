/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:03:55 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/26 18:28:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	ScalarConverter	converter;
	converter.convert(argv[1]);
	return (0);
}