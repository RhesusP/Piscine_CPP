/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:25:01 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/25 21:23:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// unsigned int	stoul(std::string str)
// {
// 	unsigned int u;
// 	std::istringstream(str) >> u;
// 	return (u);
// }

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	unsigned int *tab;
	try
	{
		PmergeMe(&argv[1], argc - 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
