/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:51:51 by cbernot           #+#    #+#             */
/*   Updated: 2024/01/25 11:44:13 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main(void)
{
	std::cout << "============ SUBJECT TESTS ============" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "============ CUSTOM TESTS ============" << std::endl;
	{
		std::cout << std::endl
				  << "Creating a span of size 10..." << std::endl;
		Span sp = Span(10);
		std::cout << "Adding 10 numbers..." << std::endl;
		for (int i = 0; i < 10; i++)
		{
			try
			{
				sp.addNumber(i);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "Adding 1 more number..." << std::endl;
		try
		{
			sp.addNumber(10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl
				  << "Creating a span of size 1..." << std::endl;
		Span sp = Span(1);
		sp.addNumber(42);
		try
		{
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl
				  << "Creating a span of size 10000..." << std::endl;
		Span sp = Span(10000);
		std::cout << "Adding 10000 random numbers..." << std::endl;
		sp.fillRandomNumbers();
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}

	return (0);
}