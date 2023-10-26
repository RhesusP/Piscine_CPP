/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:00 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/26 12:25:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string.h>

class ScalarConverter
{
	private:
		/* data */
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & s);
		ScalarConverter&	operator=(ScalarConverter const & s);
		~ScalarConverter(void);
		void	convert(const std::string str);
};

#endif