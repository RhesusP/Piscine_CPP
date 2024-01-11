/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:57:26 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/29 13:23:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <string.h>

void	display(int & nb) {
	std::cout << nb << std::endl;
}

void	display(std::string & str) {
	std::cout << str << std::endl;
}

int	main(void) {
	std::cout << ">>> Int array <<<" << std::endl;
	int	int_array[10];
	for (size_t i = 0; i < 10; i++) {
		int_array[i] = i;
	}
	iter(int_array, 10, display);

	std::cout << std::endl << ">>> String array <<<" << std::endl;
	std::string string_array[10] = {"Hello",
									"Is",
									"it",
									"working",
									"?",
									"I",
									"guess",
									"yes",
									"!",
									":)"};
	iter(string_array, 10, display);
	return (0);
}
