/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:37 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/02 16:15:19 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"

int	main(void) {
	Serializer	serializer;
	Data*		original_msg = new Data("Hello World", "Awesome author");
	Data*		des_msg;
	uintptr_t	ptr;

	std::cout << ">>> Data before serialization <<<" << std::endl;
	std::cout << *original_msg << std::endl;
	
	ptr = serializer.serialize(original_msg);
	des_msg = serializer.deserialize(ptr);

	std::cout << ">>> Data after serialization <<<" << std::endl;
	std::cout << *des_msg << std::endl;

	delete original_msg;
	return (0);
}
