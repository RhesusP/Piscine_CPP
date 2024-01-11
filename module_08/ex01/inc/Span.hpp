/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:26 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/28 17:58:08 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <list>
# include <climits>
# include <cstdlib>

class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char* what(void) const throw();
};

class FilledListException : public std::exception {
	public:
		virtual const char* what(void) const throw();
};

class Span
{
	private:
		unsigned int	_n;
		std::list<int>	_list;
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const & s);
		Span&	operator=(Span const & rhs);
		~Span(void);
		void	addNumber(int number);
		void	fill(std::list<int>::iterator begin, std::list<int>::iterator end, int value);
		void	fillRandomNumbers(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		std::list<int>	getList(void) const;
		unsigned int	size(void) const;
};

#endif

std::ostream&	operator<<(std::ostream & o, Span const & rhs);