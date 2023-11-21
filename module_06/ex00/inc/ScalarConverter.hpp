/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:00 by cbernot           #+#    #+#             */
/*   Updated: 2023/11/09 16:04:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter(ScalarConverter const & s);
		ScalarConverter&	operator=(ScalarConverter const & s);
	public:
		ScalarConverter(void);
		~ScalarConverter(void);

		static void	convert(std::string const & literal);
};

#endif
