/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/25 14:33:10 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

unsigned int	stoul(std::string str)
{
	unsigned int u;
	std::istringstream(str) >> u;
	return (u); 
}

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
		unsigned int u = stoul(str);
		std::cout << u << std::endl;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	unsigned int *tab = parse_args(&argv[1], argc - 1);

	return (0);
}
