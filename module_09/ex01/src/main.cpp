/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:14:03 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/14 17:25:16 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RNP.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "⚠️  usage: './btc your_calc'" << std::endl;
		return (1);
	}

	return (0);
}