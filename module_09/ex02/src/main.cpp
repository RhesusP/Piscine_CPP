/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/19 11:52:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

unsigned int *parse_args(char **argv, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::string str(argv[i]);
		if (str.size() > 10)
			throw BadParameterException();
		for (int j = 0; j < str.size(); j++)
		{
			if (!isdigit(str[i]))
				throw BadParameterException();
		}
		// std::stoul()
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int *tab = parse_args(&argv[1], <sta argc - 1);

	return (0);
}
